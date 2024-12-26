#ifndef COURSEWORK_H
#define COURSEWORK_H

#include <string>

class CourseWork{
public:
    std::string name;
    int id;

    CourseWork(std::string name);
    CourseWork();
    void set_id(int id);
};

#endif
