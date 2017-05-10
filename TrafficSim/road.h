//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "semaphore.h"
#include "vehicle.h"
#include "../structures/linked_queue.h"

using namespace structures;

class Road {
 protected:
	std::string name_;
	int used_, size_;
	int speed_;
	LinkedQueue<Vehicle> queue_;

 public:
	Road(int size, int speed, std::string name);
    Road();
    ~Road();
	void add(Vehicle& vehicle);
	bool fits(Vehicle& vehicle);
	int getSize();
	int getSpeed();
    int getAvailable();
	std::string getName();
	bool isEmpty();
    Vehicle& last();
};

class wayIn : Road {
 private:
	Semaphore semaphore_;
	middleRoad front_;
	int freq_;

 public:
    wayIn();
	wayIn(int freq, Semaphore semaphore);
    int getFreq();
	Semaphore& getSemaphore();

};

class wayOut : Road {
 public:
	wayOut();
	void remove();
};

class middleRoad : Road {
private:
	Semaphore semaphore_;
	Semaphore& getSemaphore();

public:
	middleRoad();
	middleRoad(Semaphore semaphore);
};





