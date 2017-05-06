//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "road.h"

Road::Road()  = default;

Road::Road(int size, int speed, double probWest, double probEast, Semaphore& semaphore) {
	used_ = 0;
	size_ = size;
    semaphore_ = semaphore;
	speed_ = speed;
	probWest_ = probWest;
	probEast_ = probEast;
}

Road::~Road() {}

bool Road::add(const Vehicle& vehicle) {
	if(used_ + vehicle.getSize() > size_) {
        return false;
	} else {
        queue_.enqueue(vehicle);
        used_ += vehicle.getSize();
        return true;
    }
}


int Road::getSize() {
	return size_;
}

int Road:: getSpeed() {
	return speed_;
}

bool Road::isEmpty() {
	return queue_.empty();
}

Semaphore& Road::getSemaphore() {
    return semaphore_;
}

Vehicle& Road::last() {
    return queue_.back();
}

wayIn::wayIn() = default;

wayIn::wayIn(int freq) {
	freq_ = freq;
}

wayOut::wayOut() = default;

wayOut::wayOut() {}

void wayOut::remove() {
    used_ -= queue_.front().getSize();
    queue_.dequeue();
}




