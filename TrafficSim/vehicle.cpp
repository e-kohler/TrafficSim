//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include <cstdint>
#include <stdlib.h>
#include <ctime>
#include "vehicle.h"

Vehicle::Vehicle() {
	srand((unsigned int) time(NULL));
	size_ = int(((rand()/RAND_MAX)*5)+2);  // Comprimento do carro (entre 2 e 6).
	size_ += 3;  // Soma do espaço da frente e de trás.
}

Vehicle::~Vehicle() {}

int Vehicle::getSize() const {
	return size_;
}
