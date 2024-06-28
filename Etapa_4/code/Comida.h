#ifndef COMIDA_H
#define COMIDA_H

#include "Item.h"

class Comida : public Item {
public:
    Comida(int id, std::string nombre ,int cantidad) : Item(id, nombre, cantidad) {}
    void itemAplicado(Mascota& mascota) override;
};

#endif