#ifndef OBJMULTIMEDIA_H
#define OBJMULTIMEDIA_H

#include <string>
#include <memory>

using namespace std;

class ObjMultimedia {

    friend class ObjMultimediaManager;

protected:
    string name{};
    string obj_path{};

    ObjMultimedia();
    ObjMultimedia(string name, string obj_path);

public:
    virtual ~ObjMultimedia() {}

    string getName() const;
    string getObjPath() const;

    void setName(string name);
    void setObjPath(string obj_path);

    virtual void print(ostream& output) const;

    virtual void play() const = 0;
};

typedef shared_ptr<ObjMultimedia> ObjMultimediaPtr;

#endif