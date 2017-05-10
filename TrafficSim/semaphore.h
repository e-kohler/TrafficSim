//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include "vehicle.h"
#include "../structures/linked_list.h"
#include "../structures/linked_queue.h"


class Semaphore {
 private:
	bool isOpen_;
    int freq_;
    float probEast_, probWest_;

 public:
	Semaphore(int freq, float probEast, float probWest);

    Semaphore();

    ~Semaphore();
	bool isOpen();
	void change();
    int getFreq();
    float getEast();
    float getWest();
};
#endif
