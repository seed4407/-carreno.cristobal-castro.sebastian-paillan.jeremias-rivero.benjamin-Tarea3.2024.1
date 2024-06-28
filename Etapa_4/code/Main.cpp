#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include "Mascota.cpp"
#include "Item.cpp"
#include "Comida.cpp"
#include "Juguete.cpp"
#include "Medicina.cpp"
#include "Inventario.cpp"
using namespace std;

int main() {
    Inventario inv;
    ifstream inputFile("config.csv");
    string line;
    int input;
    float time = 0.0f;
    string name;
    vector<string> data;
    getline(inputFile, name);

    //Añadiendo items al inventario
    while(getline(inputFile, line)){
        string temp;
        stringstream lineStream(line);
        while(getline(lineStream, temp, ';')){
            data.push_back(temp);
        }
        if(data[1]=="Juguete"){
            inv.addItem(make_unique<Juguete>(stoi(data[0]), data[2], stoi(data[3])));
        }else if(data[1]=="Comida"){
            inv.addItem(make_unique<Comida>(stoi(data[0]), data[2], stoi(data[3])));
        }else{
            inv.addItem(make_unique<Medicina>(stoi(data[0]), data[2], stoi(data[3])));
        }
        data.clear();
    }
    // Crear mascota
    Mascota miMascota(name);

    //Bucle de la simulación
    while(miMascota.getEstado()!=Estado::Muerto&&time<15.0f){
        cout << "Tiempo en la simulación " << time << endl;
        miMascota.mostrarEstado();
        inv.showAll();
        cout << "Seleccione un item del inventario por si ID: ";
        cin >> input;

        inv.useItem(input-1, miMascota);
        time+=0.5f;
    }
    cout << "La mascota murió o el tiempo alcanzo los 15 segundos!!" << endl;
    return 0;
}
