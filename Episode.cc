#include "Episode.h"

//init member variables
Episode::Episode(const string& podcast, int number, const string& name, const string& content):podcast(podcast), number(number), name(name), content(content){

}  

void Episode:: play(){
    std::cout << "Podcast: "<< podcast << endl;
    std::cout << "Episode name: "<< name << endl;
    std::cout << "Episode number: " << number << endl;
    std::cout << "Episode content: "<< content << endl;
}

void Episode::print(){
    play();
}

