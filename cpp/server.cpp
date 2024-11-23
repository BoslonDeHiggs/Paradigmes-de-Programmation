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

int main(int argc, char* argv[])
{
  ObjMultimediaManager manager;

  manager.createVideo("gatin3", "./Videos/gatin3.mp4", 45);
  manager.createPhoto("gatin2", "./Photos/gatin2.jpg", 0, 420);
  manager.createFilm("gatin4", "./Videos/gatin4.mp4", 120, new int[3]{30, 30, 30}, 3);
  manager.createGroup("gatin", list<ObjMultimediaPtr>{manager.createPhoto("gatin1", "./Photos/gatin1.jpg", 0, 420), manager.createVideo("gatin3", "./Videos/gatin3.mp4", 45), manager.createFilm("gatin4", "./Videos/gatin4.mp4", 120, new int[3]{30, 30, 30}, 3)});

  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

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
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}

