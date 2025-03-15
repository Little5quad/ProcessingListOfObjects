#pragma once

#include <string>
#include <unordered_map>
#include <deque>
#include <memory>
#include <iostream>
#include <set>
#include <map>

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

	void AddObject(std::shared_ptr<Object> obj);
	void AddSubgroup(std::multiset<std::shared_ptr<Object>, Comparator> subgroup);

	std::multiset<std::shared_ptr<Object>, Comparator>& GetGroup();

private:
	std::multiset<std::shared_ptr<Object>, Comparator> subgroup_;
	Comparator comparator_;
};

class Group {
public:
	Group(const std::string& name) :
		name_(name) {
	}

	void AddSubgrop(const std::string& name_subgr, Comparator comp);

	// Проверит наличие подгруппы и вызвать AddSubgrop
	void CheckOfSubgroup(const std::string& name, Comparator comp);

	void EraseSubgroups();
	void EraseSubgroupConsistsOneElement();

	std::string_view GetNameGroup();
	const std::map<std::string, SubGroup>& GetSubgroups();
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