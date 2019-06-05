#ifndef UNIVERSITY_KOVALETZ_H_INCLUDED
#define UNIVERSITY_KOVALETZ_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>
/*
�����-���� ������� "University".
�����:
������ ������ ������� �����: 4 ������, 3 �������.
������ �������� ������ � ���� Persone(������), �� ����������� � �� ���� ��� ��������� ����� Student(�������)
� Worker(���������). �� ��� ����� Worker ����������� 4-� �������� ���� - Teacher(��������).
�� ��������� ����� �������� Recordbook(��������), Profession(�������) �� ��������� ���� ����� ������� MyStudent
(�������� ���������). ���� MyStudent ����������� �� ��� ����� �������.
��������� ���� �������� ������ � ������ �������, ����� ���� ������� ������ ��'��� ����� ��������.
���� ������� ����� ������ � ������ ��������.
��������� ���� ������� ������ � ������� ��������� � ��������, ����� ���� ��������� ������ ��'��� ����� �������.
���� �������� ����� ������ �� ����� �������, ������ ���� ������� ���� MyStudent � ������ ������, �� ���������� � ��������
����� MyStudent.
����ֲ�:
���� ������ ������ 4 ����� �������� �������(���� ���������� �����-������ �/�� ������� �� �/� ��������� ����)
 �� ���������� ����������.
³��������� ����������, ���� ����, ������ ���� ���������.
ֳ 4 �������� ������� � ���������� ���������������� ������� ������� � ���������.
����, ����� ���� ������ ������� �����-������ �/�� ������� �� �/� ��������� ����. ����� ����� ���� ������ �������� ���������
�� ���� �����.
��� ����, ���� �������� ������ ������� ��������� ���������� ���� ��������, ������� ������ ������� ���������
�� ������䳿. ���� ��������� ������ ������� ��������� �������� ����������.
���� �������� ������ ������� ����������� ���������� ���� ��������, �� ���������� � ������ ���������, ������������� �������
add ��������� �������� ���������: ������ ������ 1 �������� � ���� �������, ������ ������ �����, ������� ��� ��� ��� �
������, ������ ������ ������ � �����. � ������� �����-������ �������� �/�� ������� �� �/� ��������� ����.
*/
using namespace std;

void inputTextFile(double &a, ifstream &fileIn);
void outputTextFile(double a, ofstream &fileOut);
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
            double middle_mark();//������� ������
            void output();
            void input();
            void inputTextFile(ifstream &fileIn);
            void outputTextFile(ofstream &fileOut);

        private:
            vector<string> disciplines;//���������
            vector<int> marks;//������
            friend class Student;
        };
class Student:public Persone// ���� �������, ������� ���� ����� ������, ������ � ������ �������� � ��������
{
protected:

    double coefficient;//����������, �� �������� �� ���������� ���� ��������
    int base;//������ ��������
    string name;//��'�
    Recordbook book;//��������
public:
    Student(){};
    Student(string x, int y, Recordbook b):name(x), coefficient(b.middle_mark()),base(y),book(b)
    {
        name=x;
        base=y;
        book=b;
        coefficient=b.middle_mark()/100;
    };
    ~Student(){};
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
class Profession// ���� �������, ������ � �������� ��������� � ��������
    {
        string name;//�����
        int base_wage;//������ ��������
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
class Worker: public Persone// ���� ���������, ������� �� ������, ������ �� ����� �������
{
protected:
    Profession Prof;//�������
    int seniority;//����
    int degree;//������
    string surname;//�����
private:
    double coefficient1;//���������� ���� �����
    double coefficient2;//���������� ���� ������
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
    double get_wage();//��������� ��������
    double get_c1();
    double get_c2();
    void output();
    void input();
    void inputTextFile(ifstream &fileIn);
    void outputTextFile(ofstream &fileOut);
};
class Teacher: public Worker// ���� ��������, ������� ����� ���������, ������ �� ����� ������� � �������
{
   public:
    class MyStudent: public Student//���� �������� ���������
    {
    public:
    MyStudent(){};
    MyStudent(string x, int y, Recordbook b):Student(x, y, b)
    {
    };
    ~MyStudent(){};
    } ;
     double count1;//������� ����
     double count2;//� ���� �������� ������� ������ �������� ������ ���������
    vector<class MyStudent> Students;//�������� ������ ���������
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
    void add(Student s);//������� ��������� ��������
    void add(int number);//��������� ������� � ������
    void add(int number, ifstream &fileIn);//��������� ������� � �����
    void output_Students();//���� �������� �� �������
    void input_Students();//����������� ������� � ������
    void outputTextFile_Students(ofstream &fileOut);//����� � ���� ��������
    void inputTextFile_Students(ifstream &fileIn);//����������� ������� � �����
    double middlemark();//������� ��� �������� ���������
       friend class Profession;
       friend class Student;
};
#endif // UNIVERSITY_KOVALETZ_H_INCLUDED
