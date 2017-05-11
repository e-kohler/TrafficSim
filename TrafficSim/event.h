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

using namespace structures;

class Event {
 protected:
	int t_ = 0;  // Event time

 public:
	Event();
	Event(int t);
    bool operator<(const Event& e) const;
    bool operator>(const Event& e) const;
    bool operator=(const Event& e) const;
    int getTime();
	virtual LinkedList<Event*>& run(LinkedList<Event*>& events)=0;  // Method that performs the actual event.
};
/**
 * @brief New vehicle is added to a specific road.
 */
class newVehicle : public Event {
 private:
	wayIn road_;
	Semaphore semaphore_;

 public:
    newVehicle();
	newVehicle(int t, wayIn &road, Semaphore& semaphore);
    virtual LinkedList<Event*>& run(LinkedList<Event*>& events) override ;
};

class carInLine : public Event {
private:
	wayIn road_;
	Vehicle vehicle_;
	Semaphore semaphore_;
public:
	carInLine();
	carInLine(int t, wayIn& road, Vehicle& vehicle, Semaphore& semaphore);
	virtual LinkedList<Event*>& run(LinkedList<Event*>& events) override ;
};
/**
 * @brief When a semaphore changes its state.
 */
class changeSem : public Event {
 private:
	Semaphore semaphore_;

 public:
    changeSem();
	changeSem(int t, Semaphore& semaphore);
	virtual LinkedList<Event*>& run(LinkedList<Event*>& events) override;
};
/**
 * @brief When a vehicle waits for a semaphore.
 */
class carInSem : public Event {
 private:
	Semaphore semaphore_;
	Vehicle vehicle_;

 public:
    carInSem();
	carInSem(int t, Semaphore& semaphore, Vehicle& vehicle);
	LinkedList<Event*>& run(LinkedList<Event*>& events) override;
};
/**
 * @brief When a vehicle moves to another road.
 */
class changeRoad : public Event {
 private:
	Road roadFrom_, roadTo_;
	Vehicle vehicle_;
	Semaphore semaphore_;
 public:
    changeRoad();
	changeRoad(int t, Road& roadFrom, Road& roadTo, Vehicle& vehicle, Semaphore& semaphore);
	LinkedList<Event*>& run(LinkedList<Event*>& events) override;
};

#endif
