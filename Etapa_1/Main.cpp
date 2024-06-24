#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Mascota.cpp"
#include "Item.cpp"
#include "Comida.cpp"
#include "Juguete.cpp"
#include "Medicina.cpp"

int main() {

    // Crear y mostrar estado inicial de la mascota
    Mascota miMascota("Garfield");
    miMascota.mostrarEstado();

    // Crear instancias de ítems
    Comida queso(1, "Queso", 5);
    Medicina jarabe(2, "Jarabe", 3);
    Juguete pelota(3, "Pelota", -1);  // Juguete ilimitado

    // Mostrar información de ítems
    queso.mostrarItem();
    jarabe.mostrarItem();
    pelota.mostrarItem();

    // Usar ítems en la mascota y mostrar su estado después de cada uso
    queso.usar(miMascota);
    jarabe.usar(miMascota);
    pelota.usar(miMascota);

    return 0;
}
