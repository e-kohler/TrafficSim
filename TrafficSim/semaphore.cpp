//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "semaphore.h"

Semaphore::Semaphore() = default;

Semaphore::Semaphore(int freq) {
	isOpen_ = false;
    freq_ = freq;
}

Semaphore::~Semaphore() {}

bool Semaphore::isOpen() {
	return isOpen_;
}

void Semaphore::change() {
	isOpen_ = !isOpen_;
}

int Semaphore::getFreq() {
    return freq_;
}

