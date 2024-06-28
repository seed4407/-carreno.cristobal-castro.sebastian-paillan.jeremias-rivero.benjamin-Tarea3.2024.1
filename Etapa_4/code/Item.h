#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Mascota.h"
class Item {

protected:
    int id;
    int cantidad;
    std::string nombre;

public:
    Item(int id, std::string nombre, int cantidad);

    int getId();
    void setId(int id);
    int getCantidad();
    void setCantidad(int cantidad);
    std::string getNombre();
    void setNombre(std::string nombre);
    void mostrarItem();
    virtual void itemAplicado(Mascota& mascota) = 0;
    void usar(Mascota& mascota);
};

#endif  
