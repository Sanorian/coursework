#include "Student.h"
#include "StudentSerializer.h"

StudentSerializer::StudentSerializer(std::vector<Student> student_vector) {
    for (int i = 0; i < student_vector.size(); i++) {
        Student current_student = student_vector[i];
        current_student.set_id(i + 1);
        this->student_vector.push_back(current_student);
    }
}

std::vector<Student> StudentSerializer::getSerializedStudents() {
    return this->student_vector;
}
