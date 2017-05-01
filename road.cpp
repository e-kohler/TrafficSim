//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#ifndef Road_H
#define Road_H

#include <cstdint>
#include <stdlib.h>
#include <road.h>

Road::Road(Semaphore& semaphore, std::size_t size, int speed) {
	semaphore_ = semaphore;
	size_ = size;
	speed_ = speed;
}

Road::~Road() {}

std::size_t Road::getSize() {
	return size_;
}

int Road:: getSpeed() {
	return speed_;
}

Vehicle Road::pop() {
	Vehicle popped = queue_.dequeue();
	size_ += popped.getSize();  // Aumenta o tamanho restante da pista.
	return popped;
}

void Road::add(Vehicle vehicle) {
	queue_.enqueue(vehicle);
	size_ -= vehicle.getSize();  // Diminui o tamanho restante da pista.
}

bool Road::empty() {
	return queue_.empty();
}



