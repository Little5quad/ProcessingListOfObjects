#include "group.h"

#include <ctime>
#include <chrono>

void SubGroup::AddObject(std::shared_ptr<Object> obj) {
	subgroup_.insert(obj);
}

void SubGroup::AddSubgroup(std::multiset<std::shared_ptr<Object>, Comparator> subgroup){
	subgroup_ = subgroup;
}

std::multiset<std::shared_ptr<Object>, Comparator>& SubGroup::GetGroup() {
	return subgroup_;
}

const std::multiset<std::shared_ptr<Object>, Comparator>& SubGroup::GetConstGroup() const{
	return subgroup_;
}

const std::deque<Object>& ManagerGroup::GetAllObjects() {
	return all_objects_;
}

const Group& ManagerGroup::GetGroup(std::string_view name) const{
	for (const Group& group : all_groups_) {
		if (group.GetNameGroup() == name) {
			return group;
		}
	}
	return Group("");
}

void Group::AddSubgrop(const std::string& name_subgr, Comparator comp) {
	subgroups_.emplace(name_subgr, SubGroup(comp));
}

void Group::CheckOfSubgroup(const std::string& name, Comparator comp) {
	if (GetSubgroup(name) == nullptr) {
		AddSubgrop(name, comp);
	}
}

void Group::EraseSubgroups() {
	subgroups_.clear();
}

void Group::EraseSubgroupConsistsOneElement(){
	std::vector<std::string> name_to_erase;
	for (auto& [name, subgr] : subgroups_) {
		auto& tmp = subgr.GetGroup();
		if (tmp.size() == 1 && name != "Разное") {
			CheckOfSubgroup("Разное", Comparator(SortingCriteria::Name));
			GetSubgroup("Разное")->AddSubgroup(tmp);
			name_to_erase.push_back(name);
		}
	}
	for (const auto& name : name_to_erase) {
		subgroups_.erase(name);
	}
}

std::string_view Group::GetNameGroup() const {
	return name_;
}

const std::map<std::string, SubGroup>& Group::GetSubgroups() const {
	return subgroups_;
}

SubGroup* Group::GetSubgroup(const std::string& name) {
	if (auto it = subgroups_.find(name); it != subgroups_.end()) {
		return &it->second;
	}

	return nullptr;
}

void ManagerGroup::AddToList(std::string name, Coordinates coord, std::string type, double time) {
	all_objects_.emplace_back(name, coord, type, time);
}

void ManagerGroup::CreateGroup(const SortingCriteria& criteria) {
	switch (criteria) {
	case SortingCriteria::Name: {
		CreateGroupByName();
		break;
		}
	case SortingCriteria::Distance: {
		CreateGroupByDistance();
		break;
		}
	case SortingCriteria::Type: {
		CreateGroupByType();
		break;
		}
	case SortingCriteria::Date: {
		CreateGroupByDate();
		break;
		}
	}
}

void ManagerGroup::Clear(){
	all_objects_.clear();
	all_groups_.clear();
}

void ManagerGroup::CreateGroupByDistance() {
	if (!all_objects_.empty()) {
		Group group("По расстоянию");
		for (const auto& obj : all_objects_) {
			if (ComputeDistance(obj.GetCoordinates()) < DISTANCE_HUNDERED) {
				AddToSubgroup(group, "До 100 ед", Comparator(SortingCriteria::Distance), std::make_shared<Object>(obj));
			}
			else if (ComputeDistance(obj.GetCoordinates()) < DISTANCE_THOUSAND) {
				AddToSubgroup(group, "До 1000 ед", Comparator(SortingCriteria::Distance), std::make_shared<Object>(obj));
			}
			else if (ComputeDistance(obj.GetCoordinates()) < DISTANCE_TEN_THOUSAND) {
				AddToSubgroup(group, "До 10000 ед", Comparator(SortingCriteria::Distance), std::make_shared<Object>(obj));
			}
			else {
				AddToSubgroup(group, "Слишком далеко", Comparator(SortingCriteria::Distance), std::make_shared<Object>(obj));
			}
		}
		all_groups_.push_back(std::move(group));
	}
}

void ManagerGroup::CreateGroupByName() {
	if (!all_objects_.empty()) {
		Group group("По имени");
		for (const auto& obj : all_objects_) {
			if (char c = std::toupper(obj.GetName()[0]);  ALPHOBET.find(c) != std::string::npos) {
				AddToSubgroup(group, std::string(1, c), Comparator(SortingCriteria::Name), std::make_shared<Object>(obj));
			}
			else {
				AddToSubgroup(group, "#", Comparator(SortingCriteria::Name), std::make_shared<Object>(obj));
			}
		}
		all_groups_.push_back(std::move(group));
	}
}

void ManagerGroup::CreateGroupByType(){
	if (!all_objects_.empty()) {
		Group group("По типу");
		for (const auto& obj : all_objects_) {
			AddToSubgroup(group, obj.GetType(), Comparator(SortingCriteria::Name), std::make_shared<Object>(obj));
		}
		group.EraseSubgroupConsistsOneElement();
		all_groups_.push_back(std::move(group));
	}
}

void ManagerGroup::CreateGroupByDate(){
	if (!all_objects_.empty()) {
		NowDate date;
		Group group("По дате");
		for (const auto& obj : all_objects_) {
			std::time_t tmp = static_cast<std::time_t>(obj.GetTime());
			std::tm* time_obj = std::localtime(&tmp);
			if (date.year_ - time_obj->tm_year > 0) {
				AddToSubgroup(group, "Ранее", Comparator(SortingCriteria::Date), std::make_shared<Object>(obj));
			}
			else if (date.mon_ - time_obj->tm_mon > 0) {
				AddToSubgroup(group, "В этом году", Comparator(SortingCriteria::Date), std::make_shared<Object>(obj));
			}
			else if (date.wday_ - time_obj->tm_wday > 0 && date.mday_ - time_obj->tm_mday > 1) {
				AddToSubgroup(group, "На этой неделе", Comparator(SortingCriteria::Date), std::make_shared<Object>(obj));
			}
			else if (date.mday_ - time_obj->tm_mday == 1){
				AddToSubgroup(group, "Вчера", Comparator(SortingCriteria::Date), std::make_shared<Object>(obj));
			}
			else {
				AddToSubgroup(group, "Сегодня", Comparator(SortingCriteria::Date), std::make_shared<Object>(obj));
			}
		}
		all_groups_.push_back(std::move(group));
	}
}

void ManagerGroup::AddToSubgroup(Group& group, const std::string& name, Comparator comp, std::shared_ptr<Object> obj){
	group.CheckOfSubgroup(name, comp);
	group.GetSubgroup(name)->AddObject(obj);
}
