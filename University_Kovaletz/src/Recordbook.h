#ifndef RECORDBOOK_H_INCLUDED
#define RECORDBOOK_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>

#include "University_Kovaletz.h"
#include "Persone.h"
#include "Teacher.h"
#include "Student.h"
#include "Profession.h"
#include "Worker.h"
class Persone;// Абстарактний клас людина
class Student;// клас Студент, дочірній клас класу Людина, дружній з класом Заліковка і Викладач
class Profession// клас Професія, дружній з классами Працівник і Викладач
class Worker;// клас Працівник, дочірній до Людини, дружній до класу Професія
class Teacher;// клас Викладач, дочірній класа Працівник, дружній до класів Професія і Студент
class Recordbook// клас Заліковка, дружній з класом студент
{
    public:
        int size;
        Recordbook(){};
        Recordbook(vector<string> x,vector<int>y)
        {
        size=x.size();
        if(disciplines.size()==0)
        {
            disciplines.resize(x.size());
            marks.resize(y.size());
        }
        for(int i=0; i<x.size(); i++)
        {
            disciplines[i]=x[i];
            marks[i]=y[i];
        }
        };
        ~Recordbook()
        {
            disciplines.clear();
            marks.clear();
        };
            vector<string> get_disciplines();
            vector<int> get_marks();
            double middle_mark();
            void output();
            void input();
            void inputTextFile(ifstream &fileIn);
            void outputTextFile(ofstream &fileOut);

        private:
            vector<string> disciplines;
            vector<int> marks;
            friend class Student;
        };

#endif // RECORDBOOK_H_INCLUDED
