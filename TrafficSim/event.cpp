#include "event.h"

Event::Event() = default;

Event::Event(int t) {
	t_ = t;  // teste
}

Event::~Event() {}

bool Event::operator>(Event event) {
    return t_ > event.t_;
}

bool Event::operator=(Event event) {
    return t_ == event.t_;
}

structures::LinkedList<Event>  Event::run(structures::LinkedList<Event> events) {
    throw ("Não serve pra nada, que nem você");
}

newVehicle::newVehicle() = default;

newVehicle::newVehicle(int t, wayIn& road) {
	t_ = t;
	road_ = road;
}

/**
 * @brief Recebe a lista de eventos do sistema, adiciona um carro à pista, e coloca o evento de quando essa
 *        pista recebe um outro carro, com um tempo baseado na frequência da rua.
 * @param events Lista de eventos do sistema.
 * @return Lista de eventos atualizada.
 */
structures::LinkedList<Event> newVehicle::run(structures::LinkedList<Event> events) {
    int timeInRoad = road_.getSize() / road_.getSpeed();
    Vehicle vehicle;
	if(road_.add(vehicle)) {
        events.insert_sorted((const Event &) new newVehicle(t_ + road_.getFreq(), road_));
    }
    return events;
}

changeSem::changeSem() = default;

changeSem::changeSem(int t, Semaphore& semaphore) {
	t_ = t;
	semaphore_ = semaphore;
}
/**
 * @brief Recebe a lista de eventos do sistema, muda o estado do semáforo, e coloca o evento de quando esse semáforo
 *        mudará de estado de novo, a partir da frequência.
 * @param events Lista de eventos do sistema.
 * @return Lista de eventos atualizada.
 */
structures::LinkedList<Event> changeSem::run(structures::LinkedList<Event> events) {
    int nextChange = t_ + semaphore_.getFreq();
	semaphore_.change();
    events.insert_sorted((const Event &) new changeSem(nextChange, semaphore_));
}

carInSem::carInSem() = default;

carInSem::carInSem(int t, Semaphore& semaphore, Vehicle& vehicle) {
	t_ = t;
	semaphore_ = semaphore;
	vehicle_ = vehicle;
}

structures::LinkedList<Event> carInSem::run(structures::LinkedList<Event> events) {
	//To do
}

changeRoad::changeRoad() = default;

changeRoad::changeRoad(int t, Road& road, Vehicle& vehicle) {
	t_ = t;
    road_ = road;
    vehicle_ = vehicle;
}

structures::LinkedList<Event> changeRoad::run(structures::LinkedList<Event> events) {
	//To do
}


