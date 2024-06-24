#ifndef JUGUETE_H
#define JUGUETE_H

#include "Item.h"

class Juguete : public Item {
public:
    Juguete(int id, std::string nombre ,int cantidad) : Item(id, nombre, cantidad) {}
    void itemAplicado(Mascota& mascota) override;
};

#endif