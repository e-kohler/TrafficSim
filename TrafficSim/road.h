//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
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
	void pop();
	bool fits(Vehicle& vehicle);
	int getSize();
	int getSpeed();
    int getAvailable();
	std::string getName();
	bool isEmpty();
    Vehicle& last();
};

class wayIn : public Road {
 private:
    int min_;
	int max_;

 public:
    wayIn();
	wayIn(int min, int max);
    int getFreq();
};

class wayOut : public Road {
 public:
	explicit wayOut();
};

class middleRoad : public Road {
 public:
 	explicit middleRoad();
};

#endif





