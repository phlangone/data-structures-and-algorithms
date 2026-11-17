#pragma once

#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    int id;  
    string name;
    string brand;        
    double price;  
    
    inline static int nextId = 1;

public:
    Product(const string& name, const string& brand, double price) 
        : id(nextId++), name(name), brand(brand), price(price)
    {
    }

    int getId() const {
        return this->id;
    }

    const string& getName() const {
        return this->name;
    }

    const string& getBrand() const {
        return this->brand;
    }

    double getPrice() const {
        return this->price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void print() const {
        cout << "ID: "    << id    << endl;
        cout << "Nome: "  << name  << endl;
        cout << "Marca: " << brand << endl;
        cout << "Preço: " << price << endl;
    }
};