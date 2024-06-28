#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>
#include "Estado.cpp"

class Mascota {

private:
    std::string nombre;
    float edad;
    float timeUnit;
    int salud;
    int energia;
    int felicidad;
    Estado estado;

public:
    Mascota(std::string nombre);

    void advance();
    
    void addSalud(int amt);
    void addEnergia(int amt);
    void addFelicidad(int amt);
    void Dormir();
    void setEstado();

    std::string getNombre();
    float getEdad();
    int getSalud();
    int getEnergia();
    int getFelicidad();
    Estado getEstado();
    void mostrarEstado();

};

#endif
