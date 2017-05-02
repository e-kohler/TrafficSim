//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#include "road.h"
#include <cstdint>
#include <stdlib.h>

Road::Road(Semaphore& semaphore, std::size_t size, int speed, double probWest, double probEast) {
	semaphore_ = semaphore;
	size_ = size;
	speed_ = speed;
	probWest_ = probWest;
	probEast_ = probEast;
}

Road::~Road() {}

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

void wayIn::add(const Vehicle& vehicle) {
	queue_.enqueue(vehicle);
	size_ -= vehicle.getSize();  // Diminui o tamanho restante.
}

wayOut::wayOut() {}  // To do

bool wayOut::isFull() {
	return size_ == 0;  // hmmm
}

void wayOut::remove() {
	queue_.dequeue();
	size_ += queue_.front().getSize();  // Aumenta o tamanho restante da pista.
}




