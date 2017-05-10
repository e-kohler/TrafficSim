//  Copyright [2017] Eduardo Kohler & Lucas Suppes
#ifndef VEHICLE_H
#define VEHICLE_H

#include <cstdint>
#include <stdlib.h>
#include <ctime>


class Vehicle {
 private:
	int size_;
    int speed_;

 public:
	Vehicle();
	~Vehicle();
	int getSize() const;
    void setSpeed(int speed);
};
#endif
