#include "CourseWork.h"
#include "Student.h"
#include "CourseWorkSerializer.h"
#include "StudentSerializer.h"
#include "CourseWorkDistributor.h"

#include <string>
#include <vector>
#include <iostream>

int main(){
    std::vector<CourseWork> coursework_vector{
        CourseWork("Первая курсовая"),
        CourseWork("Вторая курсовая"),
        CourseWork("Третья курсовая"),
        CourseWork("Четвертая курсовая"),
        CourseWork("Пятая курсовая")
    };
    std::vector<Student> student_vector{
        Student("Иванов Иван Иванович", "ПИб-2306а", "08.12.2004"),
        Student("Петров Петр Петрович", "ПИб-2306а", "06.01.2005"),
        Student("Алексеев Юрий Сергеевич", "ПИб-2306а", "23.12.2004"),
        Student("Хрыкин Илья Вячеславович", "ПИб-2306а", "08.01.2005"),
        Student("Кирилин Сергей Иванович", "ПИб-2306а", "08.10.2003"),
        Student("Серегин Кирилл Алексеевич", "ПИб-2306а", "03.06.2005"),
        Student("Николаев Игорь Сергеевич", "ПИб-2306а", "15.09.2005"),
        Student("Кадышева Ольга Васильевна", "ПИб-2306а", "02.08.2005"),
        Student("Кин Валерия Давлатовна", "ПИб-2306а", "08.03.2005")
    };

    std::string command;
    while(true){
        std::cout<<std::endl;
        std::cout<<"Выберите команду:"<<std::endl<<"student - для добавления студента"<<std::endl<<"coursework - для добавления студента"<<std::endl<<"exit - для выхода"<<std::endl;
        std::cout<<"Введите команду >>";
        std::cin>>command;
        if (command=="coursework"){
            CourseWork coursework = CourseWork();
            std::cout<<"Введите тему курсовой работы >>";
            std::cin>>coursework.name;
            coursework_vector.push_back(coursework);
        } else if (command=="student"){
            Student student = Student();
            std::cout << "Введите ФИО студента >> ";
            std::cin.ignore();
            std::getline(std::cin, student.name);
            std::cout<<"Введите группу студента >>";
            std::cin.ignore();
            std::getline(std::cin, student.group);
            std::cout<<"Введите дату рождения студента >>";
            std::cin.ignore();
            std::getline(std::cin, student.birth_date);
            student_vector.push_back(student);
        } else if (command=="exit"){
            std::cout<<"Продолжаем алгоритм!"<<std::endl;
            break;
        } else {
            std::cout<<"Вы ввели что-то не то";
        }
    }


    StudentSerializer student_serializer = StudentSerializer(student_vector);
    student_vector = student_serializer.getSerializedStudents();

    CourseWorkSerializer coursework_serializer = CourseWorkSerializer(coursework_vector);
    coursework_vector = coursework_serializer.getSerializedCourseWorks();


    student_vector[2].set_CourseWork(1, coursework_vector);
    student_vector[5].set_CourseWork(3, coursework_vector);


    CourseWorkDistributor distributor = CourseWorkDistributor();
    student_vector = distributor.distribute_course_works(student_vector, coursework_vector);

    for (Student student : student_vector){
        std::cout<<student.id<<"-"<<student.course_work_id<<std::endl;
    }


    return 0;
}
