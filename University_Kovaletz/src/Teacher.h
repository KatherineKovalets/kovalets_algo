#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>

#include "University_Kovaletz.h"
#include "Persone.h"
#include "Recordbook.h"
#include "Student.h"
#include "Profession.h"
#include "Worker.h"
class Persone;// Абстарактний клас людина
class Recordbook;// клас Заліковка, дружній з класом студент
class Student;// клас Студент, дочірній клас класу Людина, дружній з класом Заліковка і Викладач

class Profession;// клас Професія, дружній з классами Працівник і Викладач
class Worker;// клас Працівник, дочірній до Людини, дружній до класу Професія
class Teacher: public Worker// клас Викладач, дочірній класа Працівник, дружній до класів Професія і Студент
{
   public:
    class MyStudent: public Student
    {
    public:
    MyStudent(){};
    MyStudent(string x, int y, Recordbook b):Student(x, y, b)
    {
    };
    ~MyStudent(){};
    } ;
     double count1;
     double count2;
    vector<class MyStudent> Students;
    Teacher()
    {
        count1=0;
        count2=0;
    };
    Teacher(string n, int x, int y, double a, double b, Profession p):Worker(n, x, y, a, b, p)
    {
        count1=0;
        count2=0;
    }
        ;
    ~Teacher(){};
    void add(Student s);
    void add(int number);
    void add(int number, ifstream &fileIn);
    void output_Students();
    void input_Students();
    void outputTextFile_Students(ofstream &fileOut);
    void inputTextFile_Students(ifstream &fileIn);
    double middlemark();
       friend class Profession;
       friend class Student;
};

#endif // TEACHER_H_INCLUDED
