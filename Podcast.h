#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Episode.h"
#include "defs.h"
using namespace std;

class Podcast{
    public:
    //constructors with default arguments
    Podcast(const string& = "Sports", const string& = "TSN");
    //Copy constructor
    Podcast(Podcast&);
    //destructor
    ~Podcast();

    //functions
    string getTitle() const;
    string getHost() const;
    int getNumEpisodes();

    bool addEpisode(const string& title, const string& content);
    bool getEpisode(int index, Episode** ep);
    bool lessThan(Podcast& pod);

    void print();

    private:
    string title;
    string host;
    Episode** episodes;
    int numEps;

};
#endif