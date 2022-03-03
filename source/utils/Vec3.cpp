#include "./Vec3.hpp"

Vec3::Vec3(void) {
	x = y = z = 0;
}

Vec3::Vec3(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
