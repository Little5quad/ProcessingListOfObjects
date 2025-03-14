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

// ѕредполагаю что земл€ плоска€, т.к. условие похоже на то что в задаче координатна€ плоскость 
double ComputeDistance(Coordinates coord);