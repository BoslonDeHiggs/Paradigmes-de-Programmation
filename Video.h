#ifndef VIDEO_H
#define VIDEO_H

#include "ObjMultimedia.h"

#include <iostream>

using namespace std;

class Video : public ObjMultimedia{

    friend class ObjMultimediaManager;
    
protected:
    int duration{};

    Video() : ObjMultimedia() {}
    Video(string name, string obj_path, int duration) : ObjMultimedia(name, obj_path), duration{duration} {}

public:
    virtual ~Video() {}

    int getDuration() const {return this->duration;}    

    void setDuration(int duration){this->duration = duration;}

    void print(ostream& output) const override {
        ObjMultimedia::print(output);
        output << "Duration: " << this->duration << ' ';
    }

    void play() const override {
        string arg = "mpv " + this->obj_path + " &";
        system(arg.data());
    }
};

#endif