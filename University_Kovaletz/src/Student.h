#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include "University_Kovaletz.h"
#include "Persone.h"
#include "Recordbook.h"
#include "Teacher.h"
#include "Profession.h"
#include "Worker.h"
class Persone;// Абстарактний клас людина
class Recordbook;// клас Заліковка, дружній з класом студент
class Profession;// клас Професія, дружній з классами Працівник і Викладач
class Worker;// клас Працівник, дочірній до Людини, дружній до класу Професія
class Teacher;// клас Викладач, дочірній класа Працівник, дружній до класів Професія і Студент
class Student:public Persone// клас Студент, дочірній клас класу Людина, дружній з класом Заліковка і Викладач
{
protected:

    double coefficient;
    int base;
    string name;
    Recordbook book;
public:
    Student(){};
    Student(string x, int y, Recordbook b):name(x), coefficient(b.middle_mark()),base(y),book(b)
    {
        name=x;
        base=y;
        book=b;
        coefficient=b.middle_mark()/100;
    };
    friend class Recordbook;
    friend class Teacher;
    Recordbook get_recordbook();
    int get_base();
    string get_name();
    double get_coefficient();
    double get_bursary();//стипендія
    void output();
    void input();
    void inputTextFile(ifstream &fileIn);
    void outputTextFile(ofstream &fileOut);
};
#endif // STUDENT_H_INCLUDED
