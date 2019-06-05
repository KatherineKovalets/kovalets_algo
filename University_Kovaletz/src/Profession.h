#ifndef PROFESSION_H_INCLUDED
#define PROFESSION_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>

#include "University_Kovaletz.h"
#include "Persone.h"
#include "Recordbook.h"
#include "Student.h"
#include "Teacher.h"
#include "Worker.h"
class Persone;// Абстарактний клас людина
class Recordbook;// клас Заліковка, дружній з класом студент
class Student;// клас Студент, дочірній клас класу Людина, дружній з класом Заліковка і Викладач
class Worker;// клас Працівник, дочірній до Людини, дружній до класу Професія

class Teacher;// клас Викладач, дочірній класа Працівник, дружній до класів Професія і Студент
class Profession// клас Професія, дружній з классами Працівник і Викладач
    {
        string name;
        int base_wage;
        friend class Worker;
        friend class Teacher;
    public:
        Profession(){};
        Profession(string x, int y):name(x),base_wage(y)
        {
            name=x;
            base_wage=y;
        };
        ~Profession(){};
        int get_base();
        string get_name();
        void output();
        void input();
        void inputTextFile(ifstream &fileIn);
        void outputTextFile(ofstream &fileOut);
        };
#endif // PROFESSION_H_INCLUDED
