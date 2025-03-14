#pragma once

#include <memory>

#include "object.h"
#include "geo.h"

enum class SortingCriteria {
	Name, 
	Distance, 
	Type, 
	Date
};

class Comparator {
public: 
	Comparator() = default;
	Comparator(const SortingCriteria& criteria) :
		criteria_(criteria) {
	}
	bool operator()(const Object& lhs, const Object& rhs);

	bool operator()(std::shared_ptr<Object> lhs, std::shared_ptr<Object> rhs);

private:
	SortingCriteria criteria_;
};