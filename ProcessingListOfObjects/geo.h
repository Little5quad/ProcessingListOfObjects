#pragma once

#include <cmath>

struct Coordinates {
	double x_;
	double y_;

	Coordinates(double x, double y) :
		x_(x), y_(y) {
	}

	bool operator==(const Coordinates& other);

	bool operator!=(const Coordinates& other);
};

// ѕредполагаю что земл€ плоска€, т.к. условие похоже на то что в задаче координатна€ плоскость 
double ComputeDistance(Coordinates coord);