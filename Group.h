#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <ostream>

#include "ObjMultimedia.h"

using namespace std;

class Group : public list<ObjMultimediaPtr> {

    friend class ObjMultimediaManager;

private:
    string name{};

    Group() : list<ObjMultimediaPtr>() {}
    Group(string name, list<ObjMultimediaPtr> obj_list) : list<ObjMultimediaPtr>(obj_list), name{name} {}

public:
    virtual ~Group() {}

    string getName() const {return this->name;}

    void setName(string name) {this->name = name;}

    void print(ostream& output) const {
        output << "Multimedia group: ";
        for(auto it : *this){
            output << it->getName() << ' ';
        }
    }

};

typedef shared_ptr<Group> GroupPtr;

#endif