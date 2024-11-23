#include "ObjMultimedia.h"

#include <iostream>

using namespace std;

ObjMultimedia::ObjMultimedia(){};

ObjMultimedia::ObjMultimedia(string name, string obj_path){
    this->name = name;
    this->obj_path = obj_path;
}

string ObjMultimedia::getName() const{
    return this->name;
}

string ObjMultimedia::getObjPath() const{
    return this->obj_path;
}

void ObjMultimedia::setName(string name){
    this->name = name;
}

void ObjMultimedia::setObjPath(string obj_path){
    this->obj_path = obj_path;
}

void ObjMultimedia::print(ostream& output) const{
    output << "Name: " << this->name << ' ';
    output << "Path: " << this->obj_path << ' ';
}
