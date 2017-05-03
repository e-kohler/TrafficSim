//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include <cstdint>
#include <stdlib.h>
#include "semaphore.h"

Semaphore::Semaphore() {
	isOpen_ = false;
}

Semaphore::~Semaphore() {}

bool Semaphore::isOpen() {
	return isOpen_;
}

void Semaphore::open() {
	isOpen_ = true;
}

void Semaphore::close() {
	isOpen_ = false;
}
