#include "Juguete.h"

void Juguete::itemAplicado(Mascota& mascota) {
    mascota.addFelicidad(30);
    this->cantidad -= 1;
    std::cout << "\nUsando Juguete: " << getNombre() <<"\n";
}