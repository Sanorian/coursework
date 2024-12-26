#pragma once
#ifndef STUDENTSERIALIZER_H
#define STUDENTSERIALIZER_H

#include "Student.h"
#include <string>
#include <vector>

class StudentSerializer {
public:
    std::vector<Student> student_vector;

    StudentSerializer(std::vector<Student> student_vector);
    std::vector<Student> getSerializedStudents();
};
#endif
