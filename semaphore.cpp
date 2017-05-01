//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#include <cstdint>
#include <stdlib.h>
#include <semaphore.h>

Semaphore::isOpen() {
	return isOpen_;
}
