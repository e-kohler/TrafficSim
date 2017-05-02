//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "semaphore.h"
#include "vehicle.h"
#include "structures/linked_queue.h"

class Road {
 private:
	Semaphore& semaphore_ = NULL;
	std::size_t size_;
	int speed_;
	double probEast_, probWest_;
	structures::LinkedQueue<Vehicle> queue_;

 public:
	Road(Semaphore& semaphore, std::size_t size, int speed, double probWest, double probEast);
	~Road();
	std::size_t getSize();
	int getSpeed();
	Vehicle pop();
	void add(Vehicle vehicle);
	bool empty();
};
#endif
