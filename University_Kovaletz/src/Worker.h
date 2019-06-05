#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include "Persone.h"
#include "Recordbook.h"
#include "Student.h"
#include "Profession.h"
#include "Teacher.h"

class Persone;// Абстарактний клас людина
class Recordbook;// клас Заліковка, дружній з класом студент
class Student;// клас Студент, дочірній клас класу Людина, дружній з класом Заліковка і Викладач

class Profession;// клас Професія, дружній з классами Працівник і Викладач

class Teacher;// клас Викладач, дочірній класа Працівник, дружній до класів Професія і Студент
class Worker: public Persone// клас Працівник, дочірній до Людини, дружній до класу Професія
{
protected:
    Profession Prof;
    int seniority;
    int degree;
    string surname;
private:
    double coefficient1;
    double coefficient2;
public:
   friend class Profession;

    Worker(){};
    Worker(string n, int x, int y, double a, double b, Profession p):surname(n), seniority(x), degree(y), coefficient1(a),
    coefficient2(b),Prof(p)
    {
        surname=n;
        seniority=x;
        degree=y;
        coefficient1=a;
        coefficient2=b;
        Prof=p;
    };
    virtual ~Worker(){};
    int get_seniority();
    Profession get_Prof();
    string get_surname();
    double get_wage();
    double get_c1();
    double get_c2();
    void output();
    void input();
    void inputTextFile(ifstream &fileIn);
    void outputTextFile(ofstream &fileOut);
};
#endif // WORKER_H_INCLUDED
