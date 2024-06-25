#include <vector>
#include <memory>
#include <iostream>
#include "Item.h"
#include "Mascota.h"
using namespace std;

class Inventario{
    protected:
    vector<unique_ptr<Item>> items; 
    
    public:
    
    void addItem(unique_ptr<Item> _item){
        items.push_back(move(_item));
    }

    void useItem(int n, Mascota& mascota){
        items[n].get()->usar(mascota);
        mascota.advance();
    }

    void showAll(){
        cout << "Inventario:" << endl;
        for(const auto& item: items){
            item.get()->mostrarItem();
        }
    }
};