#include "ObjMultimediaManager.h"

const shared_ptr<ObjMultimedia> & ObjMultimediaManager::createPhoto(string name, string obj_path, float latitude, float longitude){
    obj_map[name] = shared_ptr<Photo>(new Photo(name, obj_path, latitude, longitude));
    return obj_map[name];
}

const shared_ptr<ObjMultimedia> & ObjMultimediaManager::createVideo(string name, string obj_path, int duration){
    obj_map[name] = shared_ptr<Video>(new Video(name, obj_path, duration));
    return obj_map[name];
}

const shared_ptr<ObjMultimedia> & ObjMultimediaManager::createFilm(string name, string obj_path, int duration, const int* chapter_durations, int num_chapters){
    obj_map[name] = shared_ptr<Film>(new Film(name, obj_path, duration, chapter_durations, num_chapters));
    return obj_map[name];
}

const shared_ptr<Group> & ObjMultimediaManager::createGroup(string name, list<ObjMultimediaPtr> obj_list){
    group_map[name] = shared_ptr<Group>(new Group(name, obj_list));
    return group_map[name];
}

void ObjMultimediaManager::destroyObj(string name, ostream& output){
    auto obj = obj_map.find(name);

    if(obj != obj_map.end())
        obj_map.erase(name);
    else
        output << "This object doesn't exist!";
}

void ObjMultimediaManager::destroyGroup(string name, ostream& output){
    auto group = group_map.find(name);

    if(group != group_map.end())
        group_map.erase(name);
    else
        output << "This group doesn't exist!";
}

void ObjMultimediaManager::printObj(string name, ostream& output) const {
    auto obj = obj_map.find(name);

    if(obj != obj_map.end())
        obj->second->print(output);
    else
        output << "This object doesn't exist!";
}

void ObjMultimediaManager::printGroup(string name, ostream& output) const {
    auto group = group_map.find(name);
    
    if(group != group_map.end())
        group->second->print(output);
    else
        output << "This group doesn't exist!";
}

void ObjMultimediaManager::play(string name, ostream& output) const {
    auto obj = obj_map.find(name);

    if(obj != obj_map.end()){
        obj->second->play();
        output << "Playing " << name;
    }
    else
        output << "This object doesn't exist!";
}
