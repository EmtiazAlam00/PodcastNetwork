#include "Network.h"
using namespace std;

Network:: Network(){
    name = "Network name";
    podarray = new PodArray;
    Subscriber * subs[MAX_SUBS];
    numSubs = 0;
}

Network::~Network(){
    for(int i = 0; i < numSubs; ++i){
        delete subs[i];
    }
    delete podarray;
}

bool Network:: getPodcast(const string& title, Podcast** pod){
    return podarray-> getPodcast(title, pod)
}

bool Network:: addPodcast(const string& podcastTitle, const string& host){
    if(podarray->isFull()){
        std::cout << "Error: PodArray is full. Cannot add the podcast." << std::endl;
        return false;
    }
    //Create a new Podcast object with the provided title and host name
    Podcast* newPodcast = new Podcast(podcastTitle, host);
    //Add the new Podcast to the PodArray
    if (podarray->addPodcast(newPodcast)){
        return true;
    }
    delete newPodcast;
    return false;
}

bool Network::removePodcast(const string& title){
    Podcast* podcastToRemove = nullptr;
    //attempt to remove the podcast from Podarray
    if(podarray->removePodcast(title, &podcastToRemove)){
        delete podcastToRemove;
        return true;
    }
    std::cout<<"Error: Podcast with title '" << title << "' not found." << std::endl; 
    return false;
}

bool Network::addEpisode(const string& podcastTitle, const string& episodeTitle, const string& content){
    Podcast* podcast = nullptr;
    if (getPodcast(podcastTitle, &podcast)){
        if (podcast->addEpisode(episodeTitle, content)){
            return true;
        }
    }
    std::cout << "Error: Unable to add episode to podcast '" << podcastTitle << "'." << std::endl;
    return false;
}

bool Network:: addSubscriber(const string& name, const string* creditcard){
    if(numSubs >= MAX_SUBS){
        return false;
    }
    subs[numSubs] = new Subscriber(name, creditcard);
    ++numSubs;
    return true;
}


bool Network::download(const string& subscriber, const string& podcastTitle, Podcast** podcast) {
    // Step 1: Check if the subscriber exists
    bool subscriberFound = false;
    Subscriber* sub = nullptr;
    
    for (int i = 0; i < numSubs; ++i) {
        if (subs[i]->matches(subscriber)) {
            sub = subs[i];
            subscriberFound = true;
            break;
        }
    }

    if (!subscriberFound) {
        cout << "Error: No such subscriber found: " << subscriber << endl;
        return false;  // Return false if subscriber not found
    }

    // Step 2: Check if the podcast exists
    Podcast* pod = nullptr;
    for (int i = 0; i < podarray->size(); ++i) {
        if (podarray->getPodcast(i)->getTitle() == podcastTitle) {
            pod = podarray->getPodcast(i);
            break;
        }
    }

    if (pod == nullptr) {
        cout << "Error: No such podcast found: " << podcastTitle << endl;
        return false;  // Return false if podcast not found
    }

    // Step 3: Assign the podcast to the output parameter and return true
    *podcast = pod;
    return true;  // Successfully returned the podcast
}

bool Network::stream(const string& subscriber, const string& podcastTitle, int episodeNum, Episode** ep) {
    // Step 1: Check if the subscriber exists
    bool subscriberFound = false;
    Subscriber* sub = nullptr;
    
    for (int i = 0; i < numSubs; ++i) {
        if (subs[i]->matches(subscriber)) {
            sub = subs[i];
            subscriberFound = true;
            break;
        }
    }

    if (!subscriberFound) {
        cout << "Error: No such subscriber found: " << subscriber << endl;
        return false;  // Return false if subscriber not found
    }

    // Step 2: Get the podcast using PodArray's getPodcast function
    Podcast* pod = nullptr;
    if (!podarray->getPodcast(podcastTitle, &pod)) {
        cout << "Error: No such podcast found: " << podcastTitle << endl;
        return false;  // Return false if podcast not found
    }

    // Step 3: Check if the episode number is valid
    if (episodeNum < 1 || episodeNum > pod->getNumEpisodes()) {
        cout << "Error: Invalid episode number " << episodeNum << " for podcast " << podcastTitle << endl;
        return false;  // Return false if episode number is invalid
    }

    // Step 4: Get the episode from the podcast
    *ep = pod->getEpisode(episodeNum - 1);  // Assuming episode number is 1-based and getEpisode takes 0-based index

    // Step 5: Successfully found and returned the episode
    return true;
}


bool Network::hasSubscriber(const string& name) {
    // Loop through all the subscribers in the array
    for (int i = 0; i < numSubs; ++i) {
        if (subs[i]->matches(name)) {  // Assuming Subscriber has a matches function
            return true;  // Subscriber found, return true
        }
    }
    return false;  // No matching subscriber found, return false
}

void Network::print() {
    // Print the name of the network
    cout << "Network: " << name << endl;

    // Print all the podcasts in the network
    cout << "Podcasts:" << endl;
    for (int i = 0; i < podarray->size(); ++i) {
        podarray->getPodcast(i)->print();  // Assuming getPodcast(i) returns a pointer to a Podcast
    }

    // Print all the subscribers in the network
    cout << "Subscribers:" << endl;
    for (int i = 0; i < numSubs; ++i) {
        subs[i]->print();  // Assuming Subscriber has a print() method
    }
}
