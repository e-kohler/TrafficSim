//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include "road.h"
#include "semaphore.h"
#include "../structures/linked_list.h"
#include "../structures/linked_queue.h"


class Semaphore {
 private:
	bool isOpen_;
    int freq_;
    float probEast_, probWest_;
    Road west_, east_, front_;

 public:
	Semaphore(int freq, float probEast, float probWest, Road west, Road east, Road front);

    Semaphore();

    ~Semaphore();
	bool isOpen();
	void change();
    int getFreq();
    float getProbEast();
    float getProbWest();
    Road& getEast();
    Road& getWest();
    Road& getFront();
};
#endif
