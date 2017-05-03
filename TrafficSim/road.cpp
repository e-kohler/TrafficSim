//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "road.h"
#include <cstdint>
#include <stdlib.h>

Road::Road(std::size_t size, int speed, double probWest, double probEast) {
	used_ = 0;
	size_ = size;
	speed_ = speed;
	probWest_ = probWest;
	probEast_ = probEast;
}

Road::~Road() {}


void Road::add(const Vehicle& vehicle) {
	if(used_ + vehicle.getSize() > size_) {
		throw std::out_of_range("Road is full");  //
	}
	queue_.enqueue(vehicle);
	used_ += vehicle.getSize();  // Diminui o tamanho restante.
}


std::size_t Road::getSize() {
	return size_;
}

int Road:: getSpeed() {
	return speed_;
}

bool Road::isEmpty() {
	return queue_.empty();
}

wayIn::wayIn(int freq) {
	freq_ = freq;
}

wayIn::~wayIn() {}

wayOut::wayOut() {}  // To do

void wayOut::remove() {
	queue_.dequeue();
	used_ -= queue_.front().getSize();
}




