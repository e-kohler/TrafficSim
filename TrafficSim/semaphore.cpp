//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "semaphore.h"

using namespace structures;

Semaphore::Semaphore() = default;

Semaphore::Semaphore(int freq, float probLeft, float probRight, Road source, Road right, Road left, Road front) {
    roads_ = ArrayList<Road>(4);
    roads_.push_front(source);
    roads_.push_front(front);
    roads_.push_front(right);
    roads_.push_front(left);
	isOpen_ = false;
    freq_ = freq;
    probLeft_ = probLeft;
    probRight_ = probRight;
    nextChange_ = 0;
}

Semaphore::~Semaphore() {}

bool Semaphore::isOpen() {
	return isOpen_;
}

void Semaphore::change() {
	isOpen_ = !isOpen_;
    nextChange_ += getFreq();
}

int Semaphore::getFreq() {
    return freq_;
}

int Semaphore::getNextChange() {
    return nextChange_;
}

float Semaphore::getProbRight() {
    return probRight_;
}

float Semaphore::getProbLeft() {
    return probLeft_;
}

Road& Semaphore::getLeft() {
    return roads_.at(0);
}

Road& Semaphore::getRight() {
    return roads_.at(1);
}

Road& Semaphore::getFront() {
    return roads_.at(2);
}

Road& Semaphore::getSource() {
    return roads_.at(3);
}

