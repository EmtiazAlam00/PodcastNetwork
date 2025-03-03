#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>
using namespace std;

class Episode{
    public:
    //constructor
    Episode(const string& podcast, int number, const string& name, const string& content);
    //functions
    void play();
    void print();

    private:
    //member variables
    string name;
    string content;
    string podcast;
    int number;

};
#endif
