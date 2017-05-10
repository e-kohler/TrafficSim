//  Copyright [2017] Eduardo Kohler & Lucas Suppes

#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include <stdlib.h>
#include "road.h"
#include "semaphore.h"
#include "../structures/linked_list.h"

/**
 * @brief Class that specifies certain events.
 */

class Event {
 protected:
	int t_ = 0;  // Event time

 public:
	Event();
	Event(int t);
    bool operator<(const Event& e) const;
    bool operator>(const Event& e) const;
    bool operator=(Event event);
	LinkedList<Event> run(LinkedList<Event> events);  // Method that performs the actual event.
};
/**
 * @brief New vehicle is added to a specific road.
 */
class newVehicle : Event {
 private:
	wayIn road_;

 public:
    newVehicle();
	newVehicle(int t, wayIn& road);
    LinkedList<Event> run(LinkedList<Event> events);
};

class carInLine : Event {
private:
	wayIn road_;
	Vehicle vehicle_;
public:
	carInLine();
	carInLine(int t, wayIn& road, Vehicle& vehicle);
	LinkedList<Event> run(LinkedList<Event> events);
};



/**
 * @brief When a semaphore changes its state.
 */
class changeSem : Event {
 private:
	Semaphore semaphore_;

 public:
    changeSem();
	changeSem(int t, Semaphore& semaphore);
	LinkedList<Event> run(LinkedList<Event> events);
};
/**
 * @brief When a vehicle waits for a semaphore.
 */
class carInSem : Event {
 private:
	Semaphore semaphore_;
	Vehicle vehicle_;

 public:
    carInSem();
	carInSem(int t, Semaphore& semaphore, Vehicle& vehicle);
	LinkedList<Event> run(LinkedList<Event> events);
};
/**
 * @brief When a vehicle moves to another road.
 */
class changeRoad : Event {
 private:
	Road roadFrom_, roadTo_;
	Vehicle vehicle_;
 public:
    changeRoad();
	changeRoad(int t, Road& roadFrom, Road& roadTo, Vehicle& vehicle);
	LinkedList<Event> run(LinkedList<Event> events);
};

#endif
