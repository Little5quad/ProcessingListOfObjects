#include "group.h"

void ManagerGroup::PrintAllObjects() {
	for (const auto& obj : all_objects_) {
		std::cout << obj.GetName() <<std::endl;
	}
}

void ManagerGroup::AddToList(std::string name, Coordinates coord, std::string type, double time) {
	//Object obj(name, coord, type, time);
	all_objects_.emplace_back(name, coord, type, time);
}