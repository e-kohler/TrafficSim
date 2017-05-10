//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "semaphore.h"

Semaphore::Semaphore() = default;

Semaphore::Semaphore(int freq, float probEast, float probWest) {
	isOpen_ = false;
    freq_ = freq;
    probEast_ = probEast;
    probWest_ = probWest;
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

float Semaphore::getWest() {
    return probWest_;
}

float Semaphore::getEast() {
    return probEast_;
}

