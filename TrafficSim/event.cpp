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

LinkedList<Event>  Event::run(LinkedList<Event> events) {
    throw ("Não deve ser usado.");
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
LinkedList<Event> newVehicle::run(LinkedList<Event> events) {
    int timeToLine = road_.getAvailable() / road_.getSpeed();
    Vehicle vehicle;
	if(road_.fits(vehicle)) {
        events.insert_sorted((const Event &) new carInLine(t_ + timeToLine, road_, vehicle));
    } else {
        std::cout << "Tentando nova adição na rua: " << road_.getName() << "em 3 segundos" << "\n";
        events.insert_sorted((const Event &) new newVehicle(t_ + 3, road_));  // Caso não haja espaço, tenta de novo na frequencia da pista
    }
    return events;
}

carInLine::carInLine() = default;

carInLine::carInLine(int t, wayIn& road, Vehicle& vehicle) {
    t_ = t;
    road_ = road;
    vehicle_ = vehicle;
}

LinkedList<Event> carInLine::run(LinkedList<Event> events) {
    road_.add(vehicle_);
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
LinkedList<Event> changeSem::run(LinkedList<Event> events) {
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

LinkedList<Event> carInSem::run(LinkedList<Event> events) {
	float i = float((rand()/RAND_MAX));
    if(semaphore_.isOpen()) {
        if (i <= semaphore_.getProbEast()) {
            events.insert_sorted((const Event &) new changeRoad(t_, semaphore_.getSource(), semaphore_.getEast(), vehicle_));
        } else if (i <= (semaphore_.getProbEast() + semaphore_.getProbWest()) && i > semaphore_.getProbEast()) {
            events.insert_sorted((const Event &) new changeRoad(t_, semaphore_.getSource(), semaphore_.getWest(), vehicle_));
        } else {
            events.insert_sorted((const Event &) new changeRoad(t_, semaphore_.getSource(), semaphore_.getFront(), vehicle_));
        }
        return events;
    } else {
        events.insert_sorted((const Event &) new carInSem(t_+1, semaphore_, vehicle_));
        return events;
    }
}

changeRoad::changeRoad() = default;

changeRoad::changeRoad(int t, Road& roadFrom, Road& roadTo, Vehicle& vehicle) {
	t_ = t;
    roadFrom_ = roadFrom;
    roadTo_ = roadTo;
    vehicle_ = vehicle;
}

LinkedList<Event> changeRoad::run(LinkedList<Event> events) {
    if (roadTo_.getAvailable() == 0) {
        changeRoad(t+1, roadFrom_, roadTo_, vehicle_)
    } else {
        roadFrom_.pop();
        vehicle_.setSpeed(roadTo_.getSpeed());
        roadTo_.add(vehicle_);    ////////////INCOMPLETo
    }
}



