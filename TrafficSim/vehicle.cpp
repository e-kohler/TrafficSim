//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include <cstdint>
#include <stdlib.h>
#include <ctime>
#include "vehicle.h"

Vehicle::Vehicle() {
	size_ = (int)((rand()/RAND_MAX)*5)+2;  // Comprimento do carro (entre 2 e 6).
	size_ += 3;  // Soma do espaço da frente e de trás.
}

int Vehicle::getSize() const {
	return size_;
}

void Vehicle::setSpeed(int speed) {
    speed_ = speed;
}
