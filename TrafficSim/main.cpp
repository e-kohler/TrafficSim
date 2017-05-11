#include <iostream>
#include "event.h"


int main () {
    int texec = 50;
    int elapsed = 0;

    int freq = 20;
    wayIn* O1leste = new wayIn(2000, 80, "O1 leste",2, 10);
    wayIn* S1norte = new wayIn(500, 60, "S1 norte",7, 30);
    wayIn* N1sul = new wayIn(500, 60, "N1 sul",5, 20);
    wayIn* N2sul = new wayIn(500, 40, "N2 sul",5, 20);
    wayIn* L1oeste = new wayIn(400, 30, "L1 oeste",5, 20);
    wayIn* S2norte = new wayIn(500, 40, "S2 norte",5, 20);

    middleRoad* C1oeste = new middleRoad(300, 60, "C1oeste"); //na verdade, é uma middleway, mas é apenas para testes
    middleRoad* C1leste = new middleRoad(300, 60, "C1leste");

    wayOut* O1oeste = new wayOut(2000,80, "O1oeste");
    wayOut* S1sul = new wayOut(500,60, "S1sul");
    wayOut* N1norte = new wayOut(500,60, "N1norte");
    wayOut* N2norte = new wayOut(500,40, "N2norte");
    wayOut* L1leste = new wayOut(500,30, "L1leste");
    wayOut* S2sul = new wayOut(500,40, "S2sul");

    Semaphore* O1 = new Semaphore(freq, 0.1, 0.8, *(O1leste), *(S1sul), *(N1norte), *(C1leste));
    Semaphore* S1 = new Semaphore(freq, 0.1, 0.8, *(S1norte), *(C1leste), *(O1leste), *(N1norte));
    Semaphore* C1O = new Semaphore(freq, 0.4, 0.3, *(C1leste), *(N1norte), *(S1sul), *(O1oeste));
    Semaphore* N1 = new Semaphore(freq, 0.8, 0.1, *(N1sul), *(O1oeste), *(C1leste), *(S1sul));

    Semaphore* C1L = new Semaphore(freq, 0.3, 0.3, *(C1leste), *(S2sul), *(N2norte), *(L1leste));
    Semaphore* S2 = new Semaphore(freq, 0.3, 0.4, *(S2norte), *(C1oeste), *(L1leste), *(N2norte));
    Semaphore* L1 = new Semaphore(freq, 0.3, 0.4, *(L1oeste), *(N2norte), *(S2sul), *(C1oeste));
    Semaphore* N2 = new Semaphore(freq, 0.3, 0.4, *(N2sul), *(L1leste), *(C1oeste), *(S2sul));


    LinkedList<Event> events;
    events.push_back(*new newVehicle(0, *(O1leste), *O1));
    events.push_back(*new newVehicle(0, *(S1norte), *S1));
    events.push_back(*new newVehicle(0, *(N1sul), *N1));
    events.push_back(*new newVehicle(0, *(L1oeste), *L1));


    while(elapsed < texec) {
        events = events.pop_front().run(events);

    }

}
