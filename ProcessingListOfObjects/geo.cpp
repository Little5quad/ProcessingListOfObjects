#include "geo.h"

inline bool Coordinates::operator==(const Coordinates& other) {
	return x_ == other.x_ && y_ == other.y_;
}

inline bool Coordinates::operator!=(const Coordinates& other) {
	return !(*this == other);
}

double ComputeDistance(Coordinates coord) {
	// рискну предположить что группировка по расстоянию должна происходить относитель (0;0)
	return std::sqrt(coord.x_ * coord.x_ + coord.y_ * coord.y_);
}
