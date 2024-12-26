#include "Student.h"
#include "CourseWork.h"

Student::Student(std::string name, std::string group, std::string birth_date) {
    this->name = name;
    this->group = group;
    this->birth_date = birth_date;
    this->course_work = nullptr;
    this->course_work_id = 0;
}

Student::Student(){}

CourseWork* Student::get_CourseWork() {
    return this->course_work;
}

void Student::set_id(int id) {
    this->id = id;
}

void Student::set_CourseWork(int id, std::vector<CourseWork>& course_work_vector) {
    if (id >= 0 && id < course_work_vector.size()) {
        this->course_work_id = course_work_vector[id].id; // Установить реальный id из объекта
        this->course_work = &course_work_vector[id];
    } else {
        this->course_work_id = 0; // Устанавливаем "нулевой" id для некорректного случая
        this->course_work = nullptr;
    }
}
