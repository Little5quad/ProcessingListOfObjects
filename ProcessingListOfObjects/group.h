#pragma once

#include <string>
#include <unordered_map>
#include <deque>
#include <memory>

#include "object.h"

class ManagerGroup {
public:

	void AddToList(const Object& obj);

private:
	std::deque<Object> all_objects_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_distance_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_name_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_type_;
	std::unordered_map<std::string_view, std::shared_ptr<Object>> group_by_time_;
};