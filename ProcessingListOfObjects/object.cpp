#include "object.h"

std::string_view Object::GetName() const {
	return name_;
}
Coordinates Object::GetCoordinates() const {
	return coordinates_;
}
std::string_view Object::GetType() const {
	return type_;
}
std::time_t Object::GetTime() const {
	return time_;
}