#include "Comida.h"

void Comida::itemAplicado(Mascota&  mascota) {
    mascota.addEnergia(20);
    mascota.addSalud(20);
    this->cantidad -= 1;
    std::cout << "\nUsando comida: " << getNombre() <<"\n";
}