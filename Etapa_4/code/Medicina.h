#ifndef MEDICINA_H
#define MEDICINA_H

#include "Item.h"
#include <string>

class Medicina : public Item {
public:
    Medicina(int id, std::string nombre, int cantidad) : Item(id, nombre, cantidad) {}
    void itemAplicado(Mascota& mascota) override;
};

#endif
