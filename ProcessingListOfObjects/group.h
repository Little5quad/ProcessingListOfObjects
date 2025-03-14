#pragma once

#include <string>
#include <unordered_map>
#include <deque>
#include <memory>
#include <iostream>

#include "object.h"

class ManagerGroup {
public:

	void AddToList(std::string name, Coordinates coord, std::string type, double time);

	const std::deque<Object>& GetAllObjects();

private:
	std::deque<Object> all_objects_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_distance_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_name_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_type_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_time_;
};
