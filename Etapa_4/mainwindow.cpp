#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "code/Mascota.h"
#include "code/Comida.h"
#include "code/Inventario.cpp"
#include "code/Comida.h"
#include "code/Juguete.h"
#include "code/Medicina.h"
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    mascota(new Mascota("Pou"))
{
    ui->setupUi(this);
    Inventario inv;
    ifstream inputFile("code/config.csv");
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::cout << mascota->getNombre() << std::endl;
}

