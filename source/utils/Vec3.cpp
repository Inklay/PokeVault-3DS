#include "./Vec3.hpp"

Vec3::Vec3(void) {
	x = y = z = 0;
}

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
