#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "road.h"
#include "semaphore.h"

int main () {
    int texec = 30;

    int freq = 15;
    wayIn* O1leste = new wayIn(2000, 80, "O1 leste",10,2);
    wayIn* S1norte = new wayIn(500, 60, "S1 norte",30,7);
    wayIn* N1sul = new wayIn(500, 60, "N1 sul",20,5);
    wayIn* C1oeste = new wayIn(300, 60, "C1 oeste",10,5); //na verdae, é uma middleway, mas é apenas para testes

    wayOut* O1oeste = new wayOut(2000,80);
    wayOut* S1sul = new wayOut(500,60);
    wayOut* C1leste = new wayOut(300,60);
    wayOut* N1norte = new wayOut(500,60);

    Semaphore* O1 = new Semaphore(freq, 0.1, 0.8, *(O1leste), *(S1sul), *(N1norte), *(C1leste));
    Semaphore* S1 = new Semaphore(freq, 0.1, 0.8, *(S1norte), *(C1leste), *(O1leste), *(N1norte));
    Semaphore* C1 = new Semaphore(freq, 0.4, 0.3, *(C1leste), *(N1norte), *(S1sul), *(O1oeste));
    Semaphore* N1 = new Semaphore(freq, 0.8, 0.1, *(N1sul), *(O1oeste), *(C1leste), *(S1sul));



	return 0;
}
