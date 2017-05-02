//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <cstdint>
#include <stdlib.h>

class Semaphore {
 private:
	bool isOpen_;

 public:
	Semaphore();
	~Semaphore();
	bool isOpen();
};
#endif
