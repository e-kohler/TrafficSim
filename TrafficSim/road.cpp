//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "road.h"

Road::Road()  = default;

Road::Road(int size, int speed, std::string name) {
	used_ = 0;
	size_ = size;
	speed_ = speed;
    name_ = name;
}

Road::~Road() {}

void Road::add(Vehicle& vehicle) {
	if(!fits(vehicle)) {
        std::cout << "Novo carro não cabe na rua: " << getName() << "\n";
	} else {
        queue_.enqueue(vehicle);
        used_ += vehicle.getSize();
        std::cout << "Carro adicionado à rua: " << getName() << "\n";
    }
}

bool Road::fits(Vehicle& vehicle) {
    return vehicle.getSize() <= getAvailable();
}

int Road::getSize() {
	return size_;
}

int Road:: getSpeed() {
	return speed_;
}

int Road::getAvailable() {
    return size_ - used_;
}

std::string Road::getName() {
    return name_;
}

bool Road::isEmpty() {
	return queue_.empty();
}

Vehicle& Road::last() {
    return queue_.back();
}

wayIn::wayIn() = default;

wayIn::wayIn(int freq, Semaphore semaphore) {
	freq_ = freq;
    semaphore_ = semaphore;
}

int wayIn::getFreq() {
    return freq_;
}

Semaphore& wayIn::getSemaphore() {
    return semaphore_;
}

wayOut::wayOut() = default;

wayOut::wayOut() {}

void wayOut::remove() {
    used_ -= queue_.front().getSize();
    queue_.dequeue();
}

middleRoad::middleRoad() = default;

middleRoad::middleRoad(Semaphore semaphore) {
    semaphore_ = semaphore;
}

Semaphore& middleRoad::getSemaphore() {
    return semaphore_;
}
