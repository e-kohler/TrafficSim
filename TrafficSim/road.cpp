//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "road.h"

Road::Road()  = default;

Road::Road(int size, int speed, double probWest, double probEast, Semaphore& semaphore, std::string name) {
	used_ = 0;
	size_ = size;
    semaphore_ = semaphore;
	speed_ = speed;
	probWest_ = probWest;
	probEast_ = probEast;
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

Semaphore& Road::getSemaphore() {
    return semaphore_;
}

Vehicle& Road::last() {
    return queue_.back();
}

wayIn::wayIn() = default;

wayIn::wayIn(int freq, wayOut west, wayOut east, middleRoad front) {
    west_ = west;
    east_ = east;
    front_ = front;
	freq_ = freq;
}

int wayIn::getFreq() {
    return freq_;
}

wayOut::wayOut() = default;

wayOut::wayOut() {}

void wayOut::remove() {
    used_ -= queue_.front().getSize();
    queue_.dequeue();
}

middleRoad::middleRoad() = default;

middleRoad::middleRoad(wayOut west, wayOut east, wayOut front) {
    west_ = west;
    east_ = east;
    front_ = front;
}
