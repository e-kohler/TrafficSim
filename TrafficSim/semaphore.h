//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include "road.h"
#include "../structures/linked_list.h"
#include "../structures/array_list.h"
#include "../structures/linked_queue.h"

using namespace structures;

class Semaphore {
private:
	bool isOpen_;
	int freq_;
	int nextOpenTime_, nextCloseTime_;
	float probLeft_, probRight_;
	ArrayList<Road> roads_;

public:
	Semaphore(int freq, float probLeft, float probRight, Road source, Road right, Road left, Road front);

	Semaphore();

	~Semaphore();
	bool isOpen();
	void change(int t);
	int getFreq();
	int getNextOpenTime();
	int getNextCloseTime();
	float getProbLeft();
	float getProbRight();
	Road& getSource();
	Road& getLeft();
	Road& getRight();
	Road& getFront();
};
#endif
