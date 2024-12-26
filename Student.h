#ifndef STUDENT_H
#define STUDENT_H

#include "CourseWork.h"
#include <string>
#include <vector>

class Student {
public:
    int id, course_work_id;
    std::string name, group, birth_date;
    CourseWork* course_work;

    Student();
    Student(std::string name, std::string group, std::string birth_date);
    CourseWork* get_CourseWork();
    void set_id(int id);
    void set_CourseWork(int id, std::vector<CourseWork>& course_work_vector);

};
#endif
