**Podcast Network Simulation**

This project is a C++ implementation of a Podcast Network Simulation, designed to model a network of podcasts, episodes, and subscribers. It follows Object-Oriented Programming principles and utilizes a structured approach, separating control, view, entity, and collection objects.

The application includes functionalities for:

- Managing a network of Podcasts and Episodes.

- Allowing Subscribers to stream or download podcasts.

- Implementing deep copies for local storage.

- Running automated tests through a TestControl system

**Features**

- Network Management: Add/remove podcasts, add episodes, manage subscribers.

- Client Functionality: Stream episodes from the network, download podcasts for local playback.

- Test Suite: Simulated control and view classes for testing functionality.

- Memory Management: Deep copy implementation to ensure persistence even when the original data is deleted.

- Encapsulation & Abstraction: Follows proper Object-Oriented principles with well-structured classes and functions.

**Class Descriptions**

_Network Class_:

Manages collections of Podcasts and Subscribers.

Provides streaming and downloading services to Clients.

Implements hasSubscriber() for validation.

_Client Class_:

Connects to the Network and interacts with Podcasts.

Downloads Podcasts (deep copies) for local playback.

Streams episodes directly from the Network.

_Podcast Class_:

Stores Podcast metadata (title, host) and manages a collection of Episode objects.

Supports adding and retrieving Episodes.

Implements a deep copy constructor.

_Episode Class_:

Stores episode metadata (number, title, content).

Implements play() to display content.

_Subscriber Class_:

Stores subscriber information (name, credit card details).

Validates user identity with matches().

_PodArray Class_:

Manages Podcasts using an array structure.

Supports adding, removing, and retrieving Podcasts.

TestControl & TestView Classes

Implements a testing framework for validating the system.

![image](https://github.com/user-attachments/assets/7a1dfebd-b1ae-4df0-8846-411bdf045354)


