//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "semaphore.h"

using namespace structures;

Semaphore::Semaphore() = default;

Semaphore::Semaphore(int freq, float probLeft, float probRight, Road& source, Road& right, Road& left, Road& front) {
    roads_ = ArrayList<Road>(4);
    roads_.push_front(source);
    roads_.push_front(front);
    roads_.push_front(right);
    roads_.push_front(left);
    isOpen_ = false;
    freq_ = freq;
    probLeft_ = probLeft;
    probRight_ = probRight;
    nextOpenTime_ = 0;
    nextCloseTime_ = 0;
}

Semaphore::~Semaphore() {}

bool Semaphore::isOpen() {
    return isOpen_;
}

void Semaphore::change(int t) {
    if (isOpen_) {
        nextOpenTime_ = t + (freq_ - freq_/4);
    } else {
        nextCloseTime_ = t + freq_/4;
    }
    isOpen_ = !isOpen_;
}

int Semaphore::getFreq() {
    return freq_;
}

int Semaphore::getNextOpenTime() {
    return nextOpenTime_;
}

int Semaphore::getNextCloseTime() {
    return nextCloseTime_;
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
