#include "comparator.h"

bool Comparator::operator()(Object lhs, Object rhs) {
	switch (criteria_) {
	case SortingCriteria::Name:
		return lhs.GetName() < rhs.GetName();
	case SortingCriteria::Distance:
		return ComputeDistance(lhs.GetCoordinates()) < ComputeDistance(rhs.GetCoordinates());
	case SortingCriteria::Type:
		return lhs.GetType() < rhs.GetType();
	case SortingCriteria::Date:
		return lhs.GetTime() < rhs.GetTime();
	default:
		return false;
	}
}

bool Comparator::operator()(std::shared_ptr<Object> lhs, std::shared_ptr<Object> rhs) const volatile {
	switch (criteria_) {
	case SortingCriteria::Name:
		return lhs->GetName() < rhs->GetName();
	case SortingCriteria::Distance:
		return ComputeDistance(lhs->GetCoordinates()) < ComputeDistance(rhs->GetCoordinates());
	case SortingCriteria::Type:
		return lhs->GetType() < rhs->GetType();
	case SortingCriteria::Date:
		return lhs->GetTime() < rhs->GetTime();
	default:
		return false;
	}
}