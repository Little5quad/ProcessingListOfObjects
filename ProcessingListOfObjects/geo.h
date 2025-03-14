#pragma once

#include <cmath>

struct Coordinates {
	float x_;
	float y_;

	Coordinates(float x, float y) :
		x_(x), y_(y) {
	}

	bool operator==(const Coordinates& other);

	bool operator!=(const Coordinates& other);
};

// Предполагаю что земля плоская, т.к. условие похоже на то что в задаче координатная плоскость 
double ComputeDistance(Coordinates coord);
