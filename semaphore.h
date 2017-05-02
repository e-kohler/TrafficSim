//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include "structures/linked_list.h"
#include "structures/linked_queue.h"


class Semaphore {
 private:
	bool isOpen_;
	structures::LinkedList<structures::LinkedQueue<Vehicle>> waysOut_;  // Lista de pistas de saída
	structures::LinkedList<structures::LinkedQueue<Vehicle>> waysIn_;  // Lista de pistas de entrada

 public:
	Semaphore();
	~Semaphore();
	bool isOpen();
	void close();
	void open();
};
#endif
