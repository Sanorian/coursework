#include "CourseWorkSerializer.h"
#include "CourseWork.h"

CourseWorkSerializer::CourseWorkSerializer(std::vector<CourseWork> coursework_vector){
    for (int i=0; i<coursework_vector.size(); i++){
        CourseWork current_coursework = coursework_vector[i];
        current_coursework.set_id(i+1);
        this->coursework_vector.push_back(current_coursework);
    }
}
std::vector<CourseWork> CourseWorkSerializer::getSerializedCourseWorks(){
    return this->coursework_vector;
}
