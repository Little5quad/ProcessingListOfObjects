#include "group.h"

const std::deque<Object>& ManagerGroup::GetAllObjects() {
	return all_objects_;
}

void ManagerGroup::AddToList(std::string name, Coordinates coord, std::string type, double time) {
	//Object obj(name, coord, type, time);
	all_objects_.emplace_back(name, coord, type, time);
}
