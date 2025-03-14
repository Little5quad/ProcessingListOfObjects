#include "object.h"

std::string Object::GetName() const {
	return name_;
}
Coordinates Object::GetCoordinates() const {
	return coordinates_;
}
std::string Object::GetType() const {
	return type_;
}
double Object::GetTime() const {
	return time_;
}