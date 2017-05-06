//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "semaphore.h"
#include "vehicle.h"
#include "../structures/linked_queue.h"

class Road {
 protected:
	int used_, size_;
	int speed_;
	double probEast_, probWest_;
	structures::LinkedQueue<Vehicle> queue_;
    Semaphore semaphore_;

 public:
	Road(int size, int speed, double probWest, double probEast, Semaphore& semaphore);
    Road();
    ~Road();
	bool add(const Vehicle& vehicle);
	int getSize();
	int getSpeed();
	bool isEmpty();
    Semaphore& getSemaphore();
    Vehicle& last();
};

class wayIn : Road {
 private:
	int freq_;

 public:
    wayIn();
	wayIn(int freq);
};

class wayOut : Road {
 public:
	wayOut();
	void remove();
};






