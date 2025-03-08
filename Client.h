#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Podcast.h"
#include "Episode.h"
#include "Network.h"
#include "PodArray.h"
using namespace std;

class Client{
    public:
    Client(const string& name);
    ~Client();

    bool download(Network* network, const string& podcastTitle);
    bool stream(Network* network, const string& podcastTitle, int episode);
    bool playLocal(const string& podcastTitle, int episode);
    void print() const;


    private:
    string name;
    PodArray* podArray;
    int numDownloaded;

};
#endif