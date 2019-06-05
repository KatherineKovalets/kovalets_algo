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
class Persone// ������������ ���� ������
{
public:
    Persone(){};
    virtual ~Persone(){};
    virtual void output() = 0;
    virtual void input() = 0;
    virtual void outputTextFile(ofstream &fileOut) = 0;
    virtual void inputTextFile(ifstream &fileIn)=0;
};
class Recordbook;// ���� ��������, ������ � ������ �������
class Student;// ���� �������, ������� ���� ����� ������, ������ � ������ �������� � ��������
class Profession;// ���� �������, ������ � �������� ��������� � ��������
class Worker;// ���� ���������, ������� �� ������, ������ �� ����� �������
class Teacher;// ���� ��������, ������� ����� ���������, ������ �� ����� ������� � �������

#endif // PERSONE_H_INCLUDED
