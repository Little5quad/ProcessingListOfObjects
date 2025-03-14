#pragma once

#include <string>
#include <ctime>

#include "geo.h"

class Object {
public:

	Object(std::string name, Coordinates coord, std::string type, double time) :
		name_(std::move(name)), coordinates_(coord), type_(std::move(type)), time_(time) {
	}

	std::string GetName() const;
	Coordinates GetCoordinates() const;
	std::string GetType() const;
	double GetTime() const;

private:
	std::string name_;
	Coordinates coordinates_;
	std::string type_;
	double time_; //������ �� ������� ������� ������������ ���� � ������� Unix Time 
};