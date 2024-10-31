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

int main(int argc, const char* argv[])
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
    manager.play("VacationPhoto");

    std::cout << "Playing Video:" << std::endl;
    manager.play("TravelVideo");

    std::cout << "Playing Film:" << std::endl;
    manager.play("VacationFilm");

    // Create a group with multimedia objects
    std::list<ObjMultimediaPtr> groupList = {photo, video, film};
    shared_ptr<Group> group = manager.createGroup("VacationGroup", groupList);

    // Print group details
    std::cout << "\nPrinting Group details:" << std::endl;
    manager.printGroup("VacationGroup", std::cout);

    return 0;
}
