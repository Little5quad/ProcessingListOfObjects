#pragma once

#include <string>
#include <ctime>

#include "geo.h"

class Object {
public:

	Object(std::string name, Coordinates coord, std::string type, double time) :
		name_(name), coordinates_(coord), type_(type), time_(time) {
	}

    const std::string& GetName() const;
    Coordinates GetCoordinates() const;
    const std::string& GetType() const;
	double GetTime() const;

private:
	std::string name_;
	Coordinates coordinates_;
	std::string type_;
	double time_; //исходя из условия задания используется дата в формате Unix Time 
};
