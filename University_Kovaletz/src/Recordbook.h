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
class Persone;// ������������ ���� ������
class Student;// ���� �������, ������� ���� ����� ������, ������ � ������ �������� � ��������
class Profession// ���� �������, ������ � �������� ��������� � ��������
class Worker;// ���� ���������, ������� �� ������, ������ �� ����� �������
class Teacher;// ���� ��������, ������� ����� ���������, ������ �� ����� ������� � �������
class Recordbook// ���� ��������, ������ � ������ �������
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
