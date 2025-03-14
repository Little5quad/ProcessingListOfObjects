#include "group.h"

const std::deque<Object>& ManagerGroup::GetAllObjects() {
	return all_objects_;
}

void ManagerGroup::AddToList(std::string name, Coordinates coord, std::string type, double time) {
	//Object obj(name, coord, type, time);
	all_objects_.emplace_back(name, coord, type, time);
}

void ManagerGroup::CreateGroup(const SortingCriteria& criteria) {

}

std::set<std::shared_ptr<Object>, Comparator>& ManagerGroup::GetGroup(const std::string& name_group) {
	if (auto search = group_to_name_.find(name_group); search != group_to_name_.end()) {
		return search->second;
	}
}