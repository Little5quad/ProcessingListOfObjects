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

// ����������� ��� ����� �������, �.�. ������� ������ �� �� ��� � ������ ������������ ��������� 
double ComputeDistance(Coordinates coord);