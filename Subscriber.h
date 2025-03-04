#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Subscriber{
    public:
    //Two argument constructor
    Subscriber(const string& name, const string& creaditcard);
    //functions
    bool matches(const string& name);
    void print();

    private:
    //member variables
    string name;
    string creditcard;

};
#endif