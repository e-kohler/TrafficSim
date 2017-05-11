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

void Road::pop() {
    used_ -= queue_.front().getSize();
    queue_.dequeue();
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

Vehicle& Road::getFirst() {
    return queue_.front();
}

wayIn::wayIn() = default;

wayIn::wayIn(int size, int speed, std::string name,int min, int max) {
	min_ = min;
    max_ = max;
}

int wayIn::getFreq() {
    return (int)(((rand()/RAND_MAX) * ((max_ - min_)+1)) + min_);
}

wayOut::wayOut(int size, int speed, std::string name) {
    size_ = size;
    speed_ = speed;
    name_ = name;
}

middleRoad::middleRoad(int size, int speed, std::string name) {
    size_ = size;
    speed_ = speed;
    name_ = name;
}



