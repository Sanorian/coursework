#include "CourseWorkDistributor.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

CourseWorkDistributor::CourseWorkDistributor() {}

std::vector<Student> CourseWorkDistributor::distribute_course_works(
    std::vector<Student> student_vector, std::vector<CourseWork> coursework_vector) {
    std::srand(std::time(nullptr));
    std::vector<CourseWork*> taken_course_works{};
    int random_index;

    for (Student& student : student_vector) {
        if (student.course_work != nullptr) {
            taken_course_works.push_back(student.course_work);
        }
    }


    if (student_vector.size() == coursework_vector.size()) {
        coursework_vector = delete_taken_course_works(coursework_vector, taken_course_works);
        for (Student& student : student_vector) {
            if (student.course_work == nullptr) {
                random_index = std::rand() % coursework_vector.size();
                student.set_CourseWork(random_index, coursework_vector);
                coursework_vector.erase(coursework_vector.begin() + random_index);
            }
        }
    }
    else if (student_vector.size() < coursework_vector.size()) {
        coursework_vector = delete_taken_course_works(coursework_vector, taken_course_works);
        for (Student& student : student_vector) {
            if (student.course_work == nullptr) {
                random_index = std::rand() % coursework_vector.size();
                student.set_CourseWork(random_index, coursework_vector);
                coursework_vector.erase(coursework_vector.begin() + random_index);
            }
        }
    }
    else {
        while (coursework_vector.size() < student_vector.size()) {
            random_index = std::rand() % coursework_vector.size();
            coursework_vector.push_back(coursework_vector[random_index]);
        }
        for (Student& student : student_vector) {
            if (student.course_work == nullptr) {
                random_index = std::rand() % coursework_vector.size();
                student.set_CourseWork(random_index, coursework_vector);
                coursework_vector.erase(coursework_vector.begin() + random_index);
            }
        }
    }
    return student_vector;
}

std::vector<CourseWork> CourseWorkDistributor::delete_taken_course_works(
    std::vector<CourseWork> all_course_works, std::vector<CourseWork*> taken_course_works) {
    all_course_works.erase(
        std::remove_if(all_course_works.begin(), all_course_works.end(),
                       [&taken_course_works](const CourseWork& cw) {
                           return std::any_of(
                               taken_course_works.begin(), taken_course_works.end(),
                               [&cw](const CourseWork* taken_cw) { return cw.id == taken_cw->id; });
                       }),
        all_course_works.end());
    return all_course_works;
}

