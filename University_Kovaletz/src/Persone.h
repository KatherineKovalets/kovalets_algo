#ifndef PERSONE_H_INCLUDED
#define PERSONE_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>

#include "University_Kovaletz.h"
#include "Teacher.h"
#include "Recordbook.h"
#include "Student.h"
#include "Profession.h"
#include "Worker.h"
class Persone// Абстарактний клас людина
{
public:
    Persone(){};
    virtual ~Persone(){};
    virtual void output() = 0;
    virtual void input() = 0;
    virtual void outputTextFile(ofstream &fileOut) = 0;
    virtual void inputTextFile(ifstream &fileIn)=0;
};
class Recordbook;// клас Заліковка, дружній з класом студент
class Student;// клас Студент, дочірній клас класу Людина, дружній з класом Заліковка і Викладач
class Profession;// клас Професія, дружній з классами Працівник і Викладач
class Worker;// клас Працівник, дочірній до Людини, дружній до класу Професія
class Teacher;// клас Викладач, дочірній класа Працівник, дружній до класів Професія і Студент

#endif // PERSONE_H_INCLUDED
