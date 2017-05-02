//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#include <cstdint>
#include <stdlib.h>
#include <semaphore.h>

Semaphore::Semaphore() {
	isOpen_ = false;
}

Semaphore::~Semaphore() {}

bool Semaphore::isOpen() {
	return isOpen_;
}
