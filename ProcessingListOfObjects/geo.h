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

// ����������� ��� ����� �������, �.�. ������� ������ �� �� ��� � ������ ������������ ��������� 
double ComputeDistance(Coordinates coord);