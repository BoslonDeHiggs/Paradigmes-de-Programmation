#ifndef FILM_H
#define FILM_H

#include "Video.h"

#include <vector>

using namespace std;

class Film : public Video{

    friend class ObjMultimediaManager;

private:
    int* chapter_durations{nullptr};
    int num_chapters{};

    Film() : Video() {}
    Film(string name, string obj_path, int duration, const int* chapter_durations, int num_chapters) : Video(name, obj_path, duration) {setChapterDurations(chapter_durations, num_chapters);}

public:
    virtual ~Film() {delete[] chapter_durations;}

    const int* getChapterDurations() const {return this->chapter_durations;}
    int getNumChapters() const {return this->num_chapters;}

    void setChapterDurations(const int* chapter_durations, int num_chapters){
        delete[] this->chapter_durations;

        this->num_chapters = num_chapters;
        this->chapter_durations = new int[num_chapters];
        for(int i = 0; i < this->num_chapters; i++){
            this->chapter_durations[i] = chapter_durations[i];
        }
    }

    void print(ostream& output) const override {
        Video::print(output);
        output << "Chapter durations: ";
        for(int i = 0; i < this->num_chapters; i++){
            output << chapter_durations[i] << ' ';
        }
    }
};

#endif