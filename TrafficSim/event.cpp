#include "event.h"
#include "road.h"

Event::Event() = default;

Event::Event(int t) {
	t_ = t;  // teste
}

bool Event::operator<(const Event& e) const {
    return t_ < e.t_;
}

bool Event::operator>(const Event& e) const {
    return t_ > e.t_;
}

bool Event::operator=(const Event& e) const {
    return t_ == e.t_;
}

int Event::getTime() {
    return t_;
}

newVehicle::newVehicle() = default;

newVehicle::newVehicle(int t, wayIn& road, Semaphore& semaphore) {
	t_ = t;
	road_ = road;
    semaphore_ = semaphore;
}

/**
 * @brief Recebe a lista de eventos do sistema, adiciona um carro à pista, e coloca o evento de quando essa
 *        pista recebe um outro carro, com um tempo baseado na frequência da rua.
 * @param events Lista de eventos do sistema.
 * @return Lista de eventos atualizada.
 */
LinkedList<Event*>& newVehicle::run(LinkedList<Event*>& events) {
    int timeToLine = 1;
    Vehicle vehicle;
    vehicle.setSpeed(road_.getSpeed());
	if(road_.fits(vehicle)) {
        events.insert_sorted(new carInLine(t_ + timeToLine, road_, vehicle, semaphore_));
        events.insert_sorted(new newVehicle((t_ + road_.getFreq()), road_, semaphore_));
    } else {
        std::cout << "Tentando nova adição na rua: " << road_.getName() << "em 3 segundos" << "\n";
        events.insert_sorted(new newVehicle(t_ + road_.getFreq(), road_, semaphore_));
        // Caso não haja espaço, tenta de novo na frequencia da pista
    }
    return events;
}

carInLine::carInLine() = default;

carInLine::carInLine(int t, wayIn& road, Vehicle& vehicle, Semaphore& semaphore) {
    t_ = t;
    road_ = road;
    vehicle_ = vehicle;
    semaphore_ = semaphore;
}

LinkedList<Event*>& carInLine::run(LinkedList<Event*>& events) {
    events.insert_sorted(new carInSem(t_, semaphore_, road_.getFirst()));
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
LinkedList<Event*>& changeSem::run(LinkedList<Event*>& events) {
    if (semaphore_.isOpen()) {
        semaphore_.change(t_);
        events.insert_sorted(new changeSem(semaphore_.getNextCloseTime(), semaphore_));
    } else {
        semaphore_.change(t_);
        events.insert_sorted(new changeSem(semaphore_.getNextOpenTime(), semaphore_));
    }
    return events;
}

carInSem::carInSem() = default;

carInSem::carInSem(int t, Semaphore& semaphore, Vehicle& vehicle) {
	t_ = t;
	semaphore_ = semaphore;
	vehicle_ = vehicle;
}

LinkedList<Event*>& carInSem::run(LinkedList<Event*>& events) {
    float i = float((rand()/RAND_MAX));
    Road roadTo;
    if (i <= semaphore_.getProbLeft()) {
        roadTo = semaphore_.getLeft();
    } else if (i <= (semaphore_.getProbLeft() + semaphore_.getProbRight()) && i > semaphore_.getProbLeft()) {
        roadTo = semaphore_.getRight();
    } else {
        roadTo = semaphore_.getFront();
    }

    if (semaphore_.isOpen()) {
        events.insert_sorted(new changeRoad(t_, semaphore_.getSource(), roadTo, vehicle_, semaphore_));
    } else {
        events.insert_sorted(new changeRoad(semaphore_.getNextOpenTime(), semaphore_.getSource(), roadTo, vehicle_, semaphore_));
    }
    return events;
}

changeRoad::changeRoad() = default;

changeRoad::changeRoad(int t, Road& roadFrom, Road& roadTo, Vehicle& vehicle, Semaphore& semaphore) {
	t_ = t;
    roadFrom_ = roadFrom;
    roadTo_ = roadTo;
    vehicle_ = vehicle;
    semaphore_ = semaphore;
}

LinkedList<Event*>& changeRoad::run(LinkedList<Event*>& events) {
    if (roadTo_.getAvailable() == 0) {
        changeRoad(t_+1, roadFrom_, roadTo_, vehicle_, semaphore_);
    } else {
        roadFrom_.pop();
        vehicle_.setSpeed(roadTo_.getSpeed());
        roadTo_.add(vehicle_);
        events.insert_sorted(new carInSem(t_, semaphore_, roadFrom_.getFirst()));
    }
    return events;
}



