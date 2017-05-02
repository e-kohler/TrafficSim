//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "semaphore.h"
#include "vehicle.h"
#include "structures/linked_queue.h"

class Road {
 protected:
	Semaphore& semaphore_;
	std::size_t size_;
	int speed_;
	double probEast_, probWest_;
	structures::LinkedQueue<Vehicle> queue_;

 public:
	Road(Semaphore& semaphore, std::size_t size, int speed, double probWest, double probEast);
	~Road();
	std::size_t getSize();
	int getSpeed();
	bool isEmpty();
};

class wayIn : Road {
 private:
	int freq_;

 public:
	wayIn(int freq);
	~wayIn();
	void add(const Vehicle& vehicle);
};

class wayOut : Road {
 public:
	wayOut();
	~wayOut();
	bool isFull();
	void remove();
};






