#include <iostream>
#include "event.h"


int main () {
    int freq = 20;
    wayIn* O1leste = new wayIn(2000, 80, "O1 leste",10,2);
    wayIn* S1norte = new wayIn(500, 60, "S1 norte",30,7);
    wayIn* N1sul = new wayIn(500, 60, "N1 sul",20,5);
    wayIn* N2sul = new wayIn(500, 40, "N2 sul",20,5);
    wayIn* L1oeste = new wayIn(400, 30, "L1 oeste",20,5);
    wayIn* S2norte = new wayIn(500, 40, "S2 norte",20,5);

    middleRoad* C1oeste = new middleRoad(300, 60); //na verdae, é uma middleway, mas é apenas para testes
    middleRoad* C1leste = new middleRoad(300,60);

    wayOut* O1oeste = new wayOut(2000,80);
    wayOut* S1sul = new wayOut(500,60);
    wayOut* N1norte = new wayOut(500,60);
    wayOut* N2norte = new wayOut(500,40);
    wayOut* L1leste = new wayOut(500,30);
    wayOut* S2sul = new wayOut(500,40);

    Semaphore* O1 = new Semaphore(freq, 0.1, 0.8, *(O1leste), *(S1sul), *(N1norte), *(C1leste));
    Semaphore* S1 = new Semaphore(freq, 0.1, 0.8, *(S1norte), *(C1leste), *(O1leste), *(N1norte));
    Semaphore* C1O = new Semaphore(freq, 0.4, 0.3, *(C1leste), *(N1norte), *(S1sul), *(O1oeste));
    Semaphore* N1 = new Semaphore(freq, 0.8, 0.1, *(N1sul), *(O1oeste), *(C1leste), *(S1sul));

    Semaphore* C1L = new Semaphore(freq, 0.4, 0.3, *(N1sul), *(O1oeste), *(C1leste), *(S1sul));
    Semaphore* S2 = new Semaphore(freq, 0.4, 0.3, *(N1sul), *(O1oeste), *(C1leste), *(S1sul));
    Semaphore* L1 = new Semaphore(freq, 0.4, 0.3, *(N1sul), *(O1oeste), *(C1leste), *(S1sul));
    Semaphore* N2 = new Semaphore(freq, 0.4, 0.3, *(N1sul), *(O1oeste), *(C1leste), *(S1sul));


    LinkedList<Event> events;
    events.push_back(*new newVehicle(0, *(O1leste)));
    events.push_back(*new newVehicle(0, *(S1norte)));
    events.push_back(*new newVehicle(0, *(N1sul)));
    events.push_back(*new newVehicle(0, *(L1oeste)));
}
