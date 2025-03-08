#include "Client.h"

Client::Client(const string& name){
    this->name = name;
    podArray = new PodArray();
}

Client::~Client(){
    delete podArray;
}

// download function
bool Client::download(Network* network, const string& podcastTitle) {
    Podcast* podcast = nullptr;

    // Check if the podcast exists in the network
    if (!network->getPodcast(podcastTitle, &podcast)) {
        cout << "Error: Podcast with title '" << podcastTitle << "' not found in the network." << endl;
        return false;
    }

    // Check if there is room in the PodArray of the Client
    if (podArray->isFull()) {
        cout << "Error: No room to download the podcast '" << podcastTitle << "'." << endl;
        return false;
    }

    // Add the podcast to the Client's PodArray
    if (podArray->addPodcast(podcast)) {
        cout << "Podcast '" << podcastTitle << "' downloaded successfully." << endl;
        return true;
    } else {
        cout << "Error: Failed to download podcast '" << podcastTitle << "'." << endl;
        return false;
    }
}

// stream function
bool Client::stream(Network* network, const string& podcastTitle, int episodeNumber) {
    Episode* episode = nullptr;

    // Attempt to stream the episode from the Network
    if (network->stream(subscriberName, podcastTitle, episodeNumber, &episode)) {
        // If the episode was successfully found and streamed, play it
        episode->play();  // Assuming there's a play method in Episode class
        return true;
    }

    // If the stream failed, the Network should have printed an error
    return false;
}

// playLocal function
void Client::playLocal(const string& podcastTitle, int episodeNumber) {
    // Attempt to find the podcast in the local PodArray
    Podcast* podcast = nullptr;

    // Search for the podcast in the local PodArray
    for (int i = 0; i < podArray->size(); ++i) {
        if (podArray->getPodcast(i)->getTitle() == podcastTitle) {
            podcast = podArray->getPodcast(i);  // If found, assign the podcast
            break;
        }
    }

    // Check if the podcast exists
    if (!podcast) {
        cout << "Error: No podcast found with title \"" << podcastTitle << "\"." << endl;
        return;
    }

    // Now check if the episode exists in the found podcast
    Episode* episode = podcast->getEpisode(episodeNumber);  // Assuming there's a getEpisode method

    // Check if the episode exists
    if (!episode) {
        cout << "Error: No episode " << episodeNumber << " found in podcast \"" << podcastTitle << "\"." << endl;
        return;
    }

    // If the episode is found, play it
    episode->play();  // Assuming there's a play method in Episode class
}
//pull me
