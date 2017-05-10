//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "semaphore.h"

Semaphore::Semaphore() = default;

Semaphore::Semaphore(int freq, float probEast, float probWest, Road source, Road west, Road east, Road front) {
    source_ = source;
    west_ = west;
    east_ = east;
    front_ = front;
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

float Semaphore::getProbWest() {
    return probWest_;
}

float Semaphore::getProbEast() {
    return probEast_;
}

Road& Semaphore::getEast() {
    return east_;
}

Road& Semaphore::getWest() {
    return west_;
}

Road& Semaphore::getFront() {
    return front_;
}

Road& Semaphore::getSource() {
    return source_;
}

