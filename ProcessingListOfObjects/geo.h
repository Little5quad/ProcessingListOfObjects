﻿#pragma once

#include <cmath>

struct Coordinates {
	double x_;
	double y_;

	Coordinates(double x, double y) :
		x_(x), y_(y) {
	}

    inline bool operator==(const Coordinates& other);

    inline bool operator!=(const Coordinates& other);
};

// Предполагаю что земля плоская, т.к. условие похоже на то что в задаче координатная плоскость
double ComputeDistance(Coordinates coord);
