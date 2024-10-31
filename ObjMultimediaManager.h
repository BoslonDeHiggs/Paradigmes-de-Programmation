#ifndef OBJMULTIMEDIAMANAGER_H
#define OBJMULTIMEDIAMANAGER_H

#include <map>

#include "ObjMultimedia.h"
#include "Group.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

using namespace std;

class ObjMultimediaManager {

private:
    map<string, ObjMultimediaPtr> obj_map{};
    map<string, GroupPtr> group_map{};

public:
	ObjMultimediaManager() {}
	
	virtual ~ObjMultimediaManager() {}

    const shared_ptr<ObjMultimedia> & createPhoto(string name, string obj_path, float latitude, float longitude);
    const shared_ptr<ObjMultimedia> & createVideo(string name, string obj_path, int duration);
    const shared_ptr<ObjMultimedia> & createFilm(string name, string obj_path, int duration, const int* chapter_durations, int num_chapters);
    const shared_ptr<Group> & createGroup(string name, list<ObjMultimediaPtr> obj_list);

    void destroyObj(string name, ostream& output);
    void destroyGroup(string name, ostream& output);

    void printObj(string name, ostream& output) const;
    void printGroup(string name, ostream& output) const;

    void play(string name, ostream& output) const;
};

#endif