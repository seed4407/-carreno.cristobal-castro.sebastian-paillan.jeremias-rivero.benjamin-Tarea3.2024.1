#include "Mascota.h"
#include <iostream>
#include <algorithm>

Mascota::Mascota(std::string nombre){
    this->nombre = nombre;
    this->edad = 0;
    this->salud = 100;
    this->energia = 100;
    this->felicidad = 50;
    this->estado = Estado::Neutro;
    this->timeUnit = 0.5;
}

void Mascota::addSalud(int amt){
    this->salud = std::min(std::max(this->salud + amt,0), 100);
}

void Mascota::addEnergia(int amt){
    this->energia = std::min(std::max(this->energia + amt,0), 100);
}

void Mascota::addFelicidad(int amt){
    this->felicidad = std::min(std::max(this->felicidad + amt,0), 100);
}

void Mascota::advance(){
        edad += this->timeUnit;
        int happyDecrease, healthDecrease, energyDecrease;
        happyDecrease = healthDecrease = energyDecrease = -5;
        if(this->edad <= 5.0 && this->salud <= 10){
            happyDecrease = -20;
        }
        if(this->edad < 5.0 && this->edad <= 10.0 && this->salud <= 50){
            happyDecrease = -20;
            energyDecrease = -10;
        }
        if(this->edad > 10.0 && this->salud <=50){
            happyDecrease = -30;
            energyDecrease = -20;
        }
        addEnergia(energyDecrease);
        addFelicidad(happyDecrease);
        addSalud(healthDecrease);
        setEstado();
}

void Mascota::setEstado(){
    if(this->salud == 0 || this->energia == 0 || this->edad >= 15.0){
        this->estado = Estado::Muerto;
        return;
    }
    if(this->energia <= 15){
        this->estado = Estado::Cansado;
        return;
    }
    if(this->edad > 5.0 && this->salud <= 30 && this->energia <= 30){
        this->estado = Estado::Enojado;
        return;
    }
    if((this->salud <= 20 && this->edad <= 5.0) || (this->salud <= 50 && 5.0 < this->edad && this->edad < 10.0)){
        this->estado = Estado::Hambriento;
        return;
    }
    if(this->felicidad <= 20){
        this->estado = Estado::Triste;
        return;
    }
    if(this->felicidad >= 60){
        this->estado = Estado::Feliz;
        return;
    }
    this->estado = Estado::Neutro;
    }

void Mascota::Dormir(){
    addSalud(15);
    addFelicidad(15);
    this->energia = 100;
    std::cout << "\n" << getNombre() << " ha dormido como un tronco!\n";
}

std::string Mascota::getNombre(){
    return this->nombre;
}

float Mascota::getEdad(){
    return this->edad;
}
    
int Mascota::getSalud(){
    return this->salud;
}
    
int Mascota::getEnergia(){
    return this->energia;
}
int Mascota::getFelicidad(){
    return this->felicidad;
}

Estado Mascota::getEstado(){
    return this->estado;
}

void Mascota::mostrarEstado(){
    std::cout << "Atributos\n";
    std::cout << "---------\n";
    std::cout << "Nombre: " << getNombre() << "\n";
    std::cout << "Edad: " << getEdad() << "\n";
    std::cout << "Salud: " << getSalud() << "\n";
    std::cout << "Energía: " << getEnergia() << "\n";
    std::cout << "Felicidad: " << getFelicidad() << "\n";

    switch (getEstado()) {
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
