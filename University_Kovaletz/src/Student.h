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
class Persone;// ������������ ���� ������
class Recordbook;// ���� ��������, ������ � ������ �������
class Profession;// ���� �������, ������ � �������� ��������� � ��������
class Worker;// ���� ���������, ������� �� ������, ������ �� ����� �������
class Teacher;// ���� ��������, ������� ����� ���������, ������ �� ����� ������� � �������
class Student:public Persone// ���� �������, ������� ���� ����� ������, ������ � ������ �������� � ��������
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
    double get_bursary();//��������
    void output();
    void input();
    void inputTextFile(ifstream &fileIn);
    void outputTextFile(ofstream &fileOut);
};
#endif // STUDENT_H_INCLUDED
