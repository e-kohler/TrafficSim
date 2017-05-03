//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include <stdlib.h>
#include "vehicle.h"
#include "road.h"
#include "semaphore.h"
/**
 * @brief Class that specifies certain events.
 */
class Event {
 protected:
	int t_ = 0;  // Event time

 public:
	Event();
	Event(int t);
	~Event();
	void event();  // Method that performs the actual event.
};
/**
 * @brief New vehicle is added to a specific road.
 */
class newVehicle : Event {
 private:
	Road road_;

 public:
	newVehicle(int t, Road& road);
	~newVehicle();
	void event();
};
/**
 * @brief When a semaphore changes its state.
 */
class changeSem : Event {
 private:
	Semaphore semaphore_;

 public:
	changeSem(int t, Semaphore& semaphore);
	~changeSem();
	void event();
};
/**
 * @brief When a vehicle waits for a semaphore.
 */
class vehInSem : Event {
 private:
	Semaphore semaphore_;
	Vehicle vehicle_;

 public:
	vehInSem(int t, Semaphore& semaphore, Vehicle& vehicle);
	~vehInSem();
	void event();
};
/**
 * @brief When a vehicle moves to another road.
 */
class changeRoad : Event {
 private:
	Road road_;
	Vehicle vehicle_;
 public:
	changeRoad(int t, Road& road, Vehicle& vehicle);
	~changeRoad();
	void event();
};
#endif
