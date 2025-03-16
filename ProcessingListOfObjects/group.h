#pragma once

#include <string>
#include <unordered_map>
#include <deque>
#include <memory>
#include <set>
#include <map>
#include <vector>

#include "object.h"
#include "comparator.h"

const std::string ALPHOBET = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
const double DISTANCE_HUNDERED = 100.;
const double DISTANCE_THOUSAND = 1000.;
const double DISTANCE_TEN_THOUSAND = 10000.;

class SubGroup {
public:
	SubGroup(Comparator& comp) : 
		subgroup_(comp), comparator_(comp) {
	}

	SubGroup(SubGroup&& other) noexcept {
		subgroup_ = std::move(other.subgroup_);
		comparator_ = std::move(other.comparator_);
	}

	SubGroup& operator=(SubGroup&& rhs) noexcept {
		subgroup_ = std::move(rhs.subgroup_);
		comparator_ = std::move(rhs.comparator_);

		return *this;
	}

	void AddObject(std::shared_ptr<Object> obj);
	void AddSubgroup(std::multiset<std::shared_ptr<Object>, Comparator> subgroup);

	std::multiset<std::shared_ptr<Object>, Comparator>& GetGroup();
	const std::multiset<std::shared_ptr<Object>, Comparator>& GetConstGroup() const;

private:
	std::multiset<std::shared_ptr<Object>, Comparator> subgroup_;
	Comparator comparator_;
};

class Group {
public:
	Group(const std::string& name) :
		name_(name) {
	}

	Group(Group&& other) noexcept {
		name_ = std::move(other.name_);
		subgroups_ = std::move(other.subgroups_);
	}

	Group& operator=(Group&& rhs) noexcept {
		name_ = std::move(rhs.name_);
		subgroups_ = std::move(rhs.subgroups_);

		return *this;
	}

	void AddSubgrop(const std::string& name_subgr, Comparator comp);

	// Проверит наличие подгруппы и вызвать AddSubgrop
	void CheckOfSubgroup(const std::string& name, Comparator comp);

	void EraseSubgroups();
	void EraseSubgroupConsistsOneElement();

	std::string_view GetNameGroup() const;
	const std::map<std::string, SubGroup>& GetSubgroups() const;
	SubGroup* GetSubgroup(const std::string& name);
private:
	std::string name_; // название типа группировки 
	std::map<std::string, SubGroup> subgroups_; // имя подгруппы и порядк подгруппы 
};

class ManagerGroup {
public:

	void AddToList(std::string name, Coordinates coord, std::string type, double time);

	const std::deque<Object>& GetAllObjects();
	const Group& GetGroup(std::string_view name) const;

	void CreateGroup(const SortingCriteria& criteria);

private:
	std::deque<Object> all_objects_;
	std::vector<Group> all_groups_;

	void CreateGroupByDistance();
	void CreateGroupByName();
	void CreateGroupByType();
	void CreateGroupByDate();

	void AddToSubgroup(Group& group, const std::string& name, Comparator comp, std::shared_ptr<Object> obj);

	struct NowDate {
		NowDate() {
			std::time_t time = std::time(NULL);
			std::tm* now = std::localtime(&time);
			year_ = now->tm_year;
			mon_ = now->tm_mon;
			wday_ = now->tm_wday;
			mday_ = now->tm_mday;
		}

		int year_;
		int mon_;
		int wday_;
		int mday_;
	};
};
