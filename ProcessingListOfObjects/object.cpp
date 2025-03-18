#include "object.h"

const std::string& Object::GetName() const {
	return name_;
}
Coordinates Object::GetCoordinates() const {
	return coordinates_;
}
const std::string& Object::GetType() const {
	return type_;
}
double Object::GetTime() const {
	return time_;
}
