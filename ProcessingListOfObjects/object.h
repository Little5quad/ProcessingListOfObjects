#pragma once

#include <string>
#include <ctime>

#include "geo.h"

class Object {
public:

	Object(std::string&& name, Coordinates coord, std::string&& type, std::time_t time) :
		name_(std::move(name)), coordinates_(coord), type_(std::move(type)), time_(time) {
	}

	std::string_view GetName() const;
	Coordinates GetCoordinates() const;
	std::string_view GetType() const;
	std::time_t GetTime() const;

private:
	std::string name_;
	Coordinates coordinates_;
	std::string type_;
	std::time_t time_; //исходя из условия задания используется дата в формате Unix Time 
};