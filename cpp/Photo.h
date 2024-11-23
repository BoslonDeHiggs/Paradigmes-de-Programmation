#ifndef PHOTO_H
#define PHOTO_H

#include "ObjMultimedia.h"

#include <iostream>

using namespace std;

class Photo : public ObjMultimedia{

    friend class ObjMultimediaManager;

private:
    float latitude{};
    float longitude{};

    Photo() : ObjMultimedia() {}
    Photo(string name, string obj_path, float latitude, float longitude) : ObjMultimedia(name, obj_path), latitude{latitude}, longitude{longitude} {}

public:
    virtual ~Photo() {};

    float getLatitude() const {return this->latitude;}
    float getLongitude() const {return this->longitude;}

    void setLatitude(float latitude){this->latitude = latitude;}
    void setLongitude(float longitude){this->longitude = longitude;}

    void print(ostream& output) const override {
        ObjMultimedia::print(output);
        output << "Latitude: " << this->latitude << ' ';
        output << "Longitude: " << this->longitude << ' ';
    }

    void play() const override {
        string arg = "imagej " + this->obj_path + " &";
        system(arg.data());
    }
};

#endif