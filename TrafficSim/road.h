//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "semaphore.h"
#include "vehicle.h"
#include "../structures/linked_queue.h"

class Road {
 protected:
	std::string name_;
	int used_, size_;
	int speed_;
	double probEast_, probWest_;
	structures::LinkedQueue<Vehicle> queue_;
    Semaphore semaphore_;

 public:
	Road(int size, int speed, double probWest, double probEast, Semaphore& semaphore, std::string name);
    Road();
    ~Road();
	bool add(const Vehicle& vehicle);
	int getSize();
	int getSpeed();
    int getAvailable();
	std::string getName();
	bool isEmpty();
    Semaphore& getSemaphore();
    Vehicle& last();
};

class wayIn : Road {
 private:
	wayOut east_, west_;
	middleRoad front_;
	int freq_;

 public:
    wayIn();
	wayIn(int freq, wayOut west, wayOut east, middleRoad front);
    int getFreq();
};

class wayOut : Road {
 public:
	wayOut();
	void remove();
};

class middleRoad : Road {
private:
	wayOut west_, east_, front_;

public:
	middleRoad();
	middleRoad(wayOut west, wayOut east, wayOut front);
};





