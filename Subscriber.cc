#include <iostream>
#include <string>
using namespace std;

#include "Subscriber.h"

//consturctor to initialize member variables
Subscriber::Subscriber(const string& name, const string& creditcard){
    this->name = name;
    this->creditcard = creditcard;
}

//functions
bool Subscriber::matches(const string& name){
    if (this->name == name) return true;
    return false;
}

void Subscriber::print(){
    cout<< "Subscriber: "<<name<<", " << "Creditcard: " << creditcard<<endl;
};