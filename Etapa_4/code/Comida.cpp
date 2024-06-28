#include "Comida.h"
#include <iostream>

void Comida::itemAplicado(Mascota&  mascota) {
    mascota.addEnergia(20);
    mascota.addSalud(20);
    this->cantidad -= 1;
    std::cout << "\nUsando comida: " << getNombre() <<"\n";
}
