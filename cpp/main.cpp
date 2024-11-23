#define SERVER

#ifdef SERVER

//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "ObjMultimediaManager.h"

const int PORT = 3331;

using namespace std;

int main(int argc, char *argv[])
{
    ObjMultimediaManager manager;

    auto gatin1 = manager.createPhoto("gatin1", "./Photos/gatin1.jpg", 878, 787);
    auto gatin2 = manager.createPhoto("gatin2", "./Photos/gatin2.jpg", 0, 420);
    auto gatin3 = manager.createVideo("gatin3", "./Videos/gatin3.mp4", 45);
    auto gatin4 = manager.createFilm("gatin4", "./Videos/gatin4.mp4", 120, new int[3]{30, 30, 30}, 3);
    manager.createGroup("group1", list<ObjMultimediaPtr>{gatin1, gatin2, gatin4});
    manager.createGroup("group2", list<ObjMultimediaPtr>{gatin3, gatin4});

    // cree le TCPServer
    auto *server =
        new TCPServer([&](std::string const &request, std::string &response)
                      {

    string command, type, name;

    istringstream request_stream(request);

    ostringstream response_stream;

    request_stream >> command;

    if(command == "info"){
      request_stream >> type;
      request_stream >> name;

      if(type == "object"){
        manager.printObj(name, response_stream);
      }
      else if(type == "group"){
        manager.printGroup(name, response_stream);
      }
      else{
        response_stream << "Type not recognized!";
      }
    }
    else if(command == "play"){
      request_stream >> name;

      manager.play(name, response_stream);
    }
    else{
      response_stream << "Command not recognized!";
    }

    response = response_stream.str();

    // return false would close the connecytion with the client
    return true; });

    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}

#endif

#ifdef OLD

//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>

#include "ObjMultimediaManager.h"
#include "ObjMultimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

using namespace std;

int main(int argc, const char *argv[])
{
    // Create an instance of ObjMultimediaManager
    ObjMultimediaManager manager;

    // Create some multimedia objects
    shared_ptr<ObjMultimedia> photo = manager.createPhoto("VacationPhoto", "./Photos/gatin1.png", 52.5200, 13.4050);
    shared_ptr<ObjMultimedia> video = manager.createVideo("TravelVideo", "./Photos/gatin2.png", 120);

    // Chapter durations for the Film
    int chapterDurations[] = {10, 20, 30};
    shared_ptr<ObjMultimedia> film = manager.createFilm("VacationFilm", "./Videos/gatin3.mp4", 60, chapterDurations, 3);

    // Print the objects
    std::cout << "Printing Photo details:" << std::endl;
    manager.printObj("VacationPhoto", std::cout);

    std::cout << "Printing Video details:" << std::endl;
    manager.printObj("TravelVideo", std::cout);

    std::cout << "Printing Film details:" << std::endl;
    manager.printObj("VacationFilm", std::cout);

    // Play the objects
    std::cout << "\nPlaying Photo:" << std::endl;
    manager.play("VacationPhoto", std::cout);

    std::cout << "Playing Video:" << std::endl;
    manager.play("TravelVideo", std::cout);

    std::cout << "Playing Film:" << std::endl;
    manager.play("VacationFilm", std::cout);

    // Create a group with multimedia objects
    std::list<ObjMultimediaPtr> groupList = {photo, video, film};
    shared_ptr<Group> group = manager.createGroup("VacationGroup", groupList);

    // Print group details
    std::cout << "\nPrinting Group details:" << std::endl;
    manager.printGroup("VacationGroup", std::cout);

    return 0;
}

#endif