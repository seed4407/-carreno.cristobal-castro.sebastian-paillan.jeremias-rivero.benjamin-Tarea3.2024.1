
#include "Item.h"

Item::Item(int id, std::string nombre, int cantidad) {
    this->id = id;
    this->cantidad = cantidad;
    this->nombre = nombre;
}

int Item::getId() {
    return this->id;
}

void Item::setId(int id) {
    this->id = id;
}

int Item::getCantidad() {
    return this->cantidad;
}

void Item::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

std::string Item::getNombre() {
    return this->nombre;
}

void Item::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Item::mostrarItem() {
    std::cout << "\nID:" << getId() << " ";
    std::cout << "\nNombre:" << getNombre() << " ";
    std::cout << "\nCantidad:" << getCantidad() << "\n";
}

void Item::usar(Mascota& mascota){
    itemAplicado(mascota);
    std::cout << "Atributos\n";
    std::cout << "---------\n";
    std::cout << "Nombre: " << mascota.getNombre() << "\n";
    std::cout << "Edad: " << mascota.getEdad() << "\n";
    std::cout << "Salud: " << mascota.getSalud() << "\n";
    std::cout << "Energía: " << mascota.getEnergia() << "\n";
    std::cout << "Felicidad: " << mascota.getFelicidad() << "\n";
    
    switch (mascota.getEstado()) {
    case Estado::Neutro:
        std::cout << "Estado: Neutro\n";
        break;
    case Estado::Feliz:
        std::cout << "Estado: Feliz\n";
        break;
    case Estado::Triste:
        std::cout << "Estado: Triste\n";
        break;
    case Estado::Hambriento:
        std::cout << "Estado: Hambriento\n";
        break;
    case Estado::Enojado:
        std::cout << "Estado: Enojado\n";
        break;
    case Estado::Cansado:
        std::cout << "Estado: Cansado\n";
        break;
    case Estado::Muerto:
        std::cout << "Estado: Muerto\n";
        break;
    default:
        break;
    }
}

