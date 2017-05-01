//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#ifndef VEHICLE_H
#define VEHICLE_H

#include <cstdint>
#include <stdlib.h>
#include <ctime>

class Vehicle {
 private:
	 std::size_t size_;

 public:
	 Vehicle();
	 ~Vehicle();
	 std::size_t getSize() const;
};
#endif
