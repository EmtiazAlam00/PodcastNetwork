#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Subscriber{
    public:
    //Two argument constructor
    Subscriber(string name, string creaditcard);
    //functions
    bool matches(const string& name);
    void print();

    private:
    //member variables
    string name;
    string creditcard;

};
#endif