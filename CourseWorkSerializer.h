#ifndef COURSEWORKSERIALIZER_H
#define COURSEWORKSERIALIZER_H


#include "CourseWork.h"

#include <string>
#include <vector>

class CourseWorkSerializer{
public:
    std::vector<CourseWork> coursework_vector{};

    CourseWorkSerializer(std::vector<CourseWork> coursework_vector);
    std::vector<CourseWork> getSerializedCourseWorks();
};
#endif
