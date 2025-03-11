#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "PodArray.h"
#include "Podcast.h"
#include "Subscriber.h"
#include "Episode.h"

class Network{
    public:
    //constructor 
    Network(const string& name);
    //destructor
    ~Network();

    //functions
    //get elements from collections
    bool getPodcast(const string& title, Podcast** pod);
    bool addPodcast(const string& podcastTitle, const string& host);
    //add and remove
    bool removePodcast(const string& title);
    bool addEpisode(const string& podcastTitle, const string& episodeTitle, const string& content);
    bool addSubscriber(const string& name, const string& creditcard);

    //client services
    bool download(const string& subscriber, const string& podcasttitle, Podcast** podcast);
    bool stream(const string& subscriber, const string& podcast, int episode, Episode** ep);
    bool hasSubscriber(const string& name);
    void print();

    private:
    //member variables
    string name;
    PodArray* podarray;
    //statically allocated array of pointers
    Subscriber* subs[MAX_SUBS];
    int numSubs;
};
#endif