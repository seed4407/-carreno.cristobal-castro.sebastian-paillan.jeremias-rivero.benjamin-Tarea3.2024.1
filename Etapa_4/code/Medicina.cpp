#include "Medicina.h"
#include <iostream>

void Medicina::itemAplicado(Mascota& mascota) {
    mascota.addSalud(40);
    this->cantidad -= 1;
    std::cout << "\nUsando medicina: " << getNombre() <<"\n";
}
