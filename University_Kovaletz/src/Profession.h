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
class Persone;// ������������ ���� ������
class Recordbook;// ���� ��������, ������ � ������ �������
class Student;// ���� �������, ������� ���� ����� ������, ������ � ������ �������� � ��������
class Worker;// ���� ���������, ������� �� ������, ������ �� ����� �������

class Teacher;// ���� ��������, ������� ����� ���������, ������ �� ����� ������� � �������
class Profession// ���� �������, ������ � �������� ��������� � ��������
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
