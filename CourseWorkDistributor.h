#pragma once
#ifndef COURSEWORKDISTRIBUTOR_H
#define COURSEWORKDISTRIBUTOR_H

#include "Student.h"
#include "CourseWork.h"
#include <vector>

class CourseWorkDistributor{
public:
    CourseWorkDistributor();
    std::vector<Student> distribute_course_works(std::vector<Student> student_vector, std::vector<CourseWork> coursework_vector);
private:
    std::vector<CourseWork> delete_taken_course_works(std::vector<CourseWork> all_course_works, std::vector<CourseWork*> taken_course_works);
};

#endif
