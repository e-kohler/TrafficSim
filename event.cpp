#include <cstdint>
#include <stdlib.h>
#include "event.h"

Event::Event(int t) {
	t_ = t;
}

Event::~Event() {}

newVehicle::newVehicle(int t, Road& road) {
	t_ = t;
	road_ = road;
}

newVehicle::~newVehicle() {}

void newVehicle::event() {
	//To do
}

changeSem::changeSem(int t, Semaphore& semaphore) {
	t_ = t;
	semaphore_ = semaphore;
}

changeSem::~changeSem() {}

void changeSem::event() {
	//To do
}

vehInSem::vehInSem(int t, Semaphore& semaphore, Vehicle& vehicle) {
	t_ = t;
	semaphore_ = semaphore;
	vehicle_ = vehicle;
}

vehInSem::~vehInSem() {}

void vehInSem::event() {
	//To do
}

changeRoad::changeRoad(int t, Road& road, Vehicle& vehicle) {
	t_ = t;
	road_ = road;
	vehicle_ = vehicle;
}

changeRoad::~changeRoad() {}

void changeRoad::event() {
	//To do
}


