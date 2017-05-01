//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#ifndef ROAD_H
#define ROAD_H

#include "semaphore.h"
#include "vehicle.h"
#include "structures/linked_queue.h"

class Road {
 private:
	Semaphore& semaphore_;
	std::size_t size_;
	int speed_;
	LinkedQueue<Vehicle> queue_;

 public:
	Road(Semaphore& semaphore, std::size_t size, int speed);
	~Road();
	std::size_t getSize();
	int getSpeed();
	Vehicle pop();
	void add(Vehicle vehicle);
	bool empty();
};
#endif
