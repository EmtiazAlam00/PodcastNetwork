#include "Podcast.h"
using namespace std;

//constructor
Podcast::Podcast(const string& title, const string& host):title(title), host(host){
    numEps = 0;
    episodes = new Episode*[MAX_EPS];
}
//copy constructor
Podcast::Podcast(Podcast& pod):title(pod.title), host(pod.host){
    for(int i = 0; i <pod.numEps;i++){
        episodes[i] = pod.episodes[i];
        numEps;
    }
}
//destructor
Podcast::~Podcast(){
    for(int i = 0; i<numEps; i++){
        delete episodes[i];
    }
    delete episodes;
}
//getters
string Podcast::getTitle() const { return title; }
string Podcast::getHost() const { return host; }
int Podcast:: getNumEpisodes() {return numEps; }

bool Podcast::addEpisode(const string& title, const string& content){
    if(numEps >= MAX_EPS) return false;
    episodes[numEps] = new Episode(this->title,++numEps,title,content);
    return true;
}

bool Podcast:: getEpisode(int index, Episode** ep){
    if(index < 0 || index >= numEps) return false;
    *ep = episodes[index];
    return true;
}

bool Podcast::lessThan(Podcast & pod){
    if(this->title > pod.title) return true;
    else
        return false;
}

void Podcast :: print(){
    cout << "From Podcast, " << "title: " << getTitle()<< ", host: " << getHost() << endl;
}