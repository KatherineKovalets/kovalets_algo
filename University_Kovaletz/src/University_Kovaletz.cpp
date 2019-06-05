#include <iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
#include<fstream>
#include "University_Kovaletz.h"
using namespace std;
class Persone;
class Recordbook;
class Student;
class Profession;
class Worker;
class Teacher;

void inputTextFile(double &a, ifstream &fileIn)
{
    fileIn>>a;
}
void outputTextFile(double a, ofstream &fileOut)
{
    fileOut<<a<<endl;
}
//функції-члени класу Заліковка
vector<string> Recordbook:: get_disciplines()
{
    return disciplines;
}
vector<int> Recordbook:: get_marks()
{
    return marks;
}
void Recordbook::output()
{
    cout<<endl<<"Disciplines and marks"<<endl;
    for(int i=0;i<marks.size();i++)
    {
       cout<<disciplines[i]<<" "<<marks[i]<<endl;
    }
}
void Recordbook::input()
{
    cout<<endl<<"Enter number of disciplines"<<endl;
    int n;
    cin>>n;
    size=n;
    disciplines.resize(n);
    marks.resize(n);
    vector<int>y(n);
    for(int i=0; i<n; i++)
    {
        cout<<"Enter name of discipline"<<endl;
        getchar();
        cin>>disciplines[i];
        cout<<endl<<"Enter mark in recordbook"<<endl;
        cin>>marks[i];
    }
}
void Recordbook::inputTextFile (ifstream &fileIn)
{
    string a;
    int b;
    cout<<endl<<"Number of disciplines in recordbook from the text file"<<endl;
    fileIn>>size;
    cout<<size<<endl;
    cout<<"Disciplines and marks from the text file"<<endl;
    for(int i = 0; i < size; i++)
    {
        fileIn>>a>>b;
        cout<<a<<" "<<b<<endl;
        disciplines.push_back(a);
        marks.push_back(b);
    }
}
void Recordbook::outputTextFile(ofstream &fileOut)
{
    cout<<endl<<"Size recordbook is written to a text file"<<endl;
    fileOut<<size<<endl;
    cout<<endl<<"Disciplines and marks is written to a text file"<<endl;
    for(int i = 0; i < size; i++)
    {
        fileOut<<disciplines[i]<<" "<<marks[i]<<endl;
    }
}
double Recordbook:: middle_mark()
{
    double sum=0;
    for(int i=0; i<size; i++)
    {
        sum+=marks[i];
    }
    return sum/size;
}

//функції-члени класу Студент

Recordbook Student::get_recordbook()
{
    return book;
}
int Student::get_base()
{
    return base;
}
string Student::get_name()
{
    return name;
}
double Student::get_coefficient()
{
    return coefficient;
}
double Student::get_bursary()
{
    return base*coefficient+base;
}
void Student::output()
{
    cout<<endl<<"Name "<<name<<endl<<"Base bursary "<<base<<endl;
    cout<<"Middle mark "<<book.middle_mark()<<endl<<"Bursary "<<get_bursary()<<endl;
    cout<<"Recordbook "<<endl;
    book.output();
}
void Student::input()
{
    cout<<endl<<"Enter name, base bursary"<<endl;
    cin>>name;
    cin>>base;
    cout<<endl<<"Enter data in recordbook"<<endl;
    book.input();
    coefficient=book.middle_mark()/100;
}
void Student::inputTextFile(ifstream &fileIn)
{
    cout<<endl<<"Name, base bursary from the text file"<<endl;
    fileIn>>name;
    cout<<name<<endl;
    fileIn>>base;
    cout<<base<<endl;
    cout<<"Student's recordbook from the text file"<<endl;
    book.inputTextFile(fileIn);
    coefficient=book.middle_mark()/100;

}
void Student::outputTextFile(ofstream &fileOut)
{
    cout<<endl<<"Name, base bursary are written to a file"<<endl;
    fileOut<<name<<endl;
    cout<<name<<endl;
    fileOut<<base<<endl;
    cout<<base<<endl;
    cout<<"Student's recordbook is written to a file"<<endl;
    book.outputTextFile(fileOut);
}
//Методи класу Професія
int Profession::get_base()
{
    return base_wage;
}
string Profession::get_name()
{
    return name;
}
void Profession::output()
{
    cout<<endl<<"Profession: "<<name<<" Base wage: "<<base_wage;
}
void Profession::input()
{
    cout<<endl<<"Enter Profession and base wage "<<endl;
    cin>>name;
    cin>>base_wage;
}
void Profession::inputTextFile(ifstream &fileIn)
{
    cout<<endl<<"Profession and base wage from the text file"<<endl;
    fileIn>>name;
    fileIn>>base_wage;
    cout<<endl<<name<<" "<<base_wage<<endl;
}
void Profession::outputTextFile(ofstream &fileOut)
{
    cout<<endl<<"Profession and base wage are written to the text file"<<endl;
    fileOut<<name<<endl<<base_wage<<endl;
    cout<<name<<" "<<base_wage<<endl;
}
//Методи класу Працівник
int Worker::get_seniority()
{
    return seniority;
}
string Worker::get_surname()
{
    return surname;
}
double Worker::get_wage()
{
    return Prof.base_wage+(seniority*coefficient1+degree*coefficient2)*Prof.base_wage;
}
Profession Worker::get_Prof()
{
    return Prof;
}
double Worker::get_c1()
{
    return coefficient1;
}
double Worker::get_c2()
{
    return coefficient2;
}
void Worker::output()
{
    cout<<endl<<"Surname: "<<surname<<" Seniority: "<<seniority<<" Degree: "<<degree<<endl;
    Prof.output();
    cout<<"Factors of the seniority, dergee: "<<coefficient1<<" "<<coefficient2<<endl;
    cout<<"Wage"<<endl;
    cout<<get_wage()<<endl;
}
void Worker::input()
{
    cout<<endl<<"Enter surname, seniority, degree:"<<endl;
    cin>>surname;
    cin>>seniority;
    cin>>degree;
    Prof.input();
    cout<<endl<<"Enter factors of the seniority, degree:"<<endl;
    cin>>coefficient1;
    cin>>coefficient2;
}
void Worker::inputTextFile(ifstream &fileIn)
{
    cout<<endl<<"Surname, seniority, degree from the text file"<<endl;
    fileIn>>surname;
    fileIn>>seniority;
    fileIn>>degree;
    cout<<endl<<surname<<" "<<seniority<<" "<<degree<<endl;
    Prof.inputTextFile(fileIn);
    cout<<"Factors of the seniority, degree from the text file"<<endl;
    fileIn>>coefficient1;
    fileIn>>coefficient2;
    cout<<coefficient1<<" "<<coefficient2<<endl;
}
void Worker::outputTextFile(ofstream &fileOut)
{
    cout<<endl<<"Surname, seniority, degree are written to the text file"<<endl;
    fileOut<<surname<<endl;
    fileOut<<seniority<<endl;
    fileOut<<degree<<endl;
    cout<<surname<<" "<<seniority<<" "<<degree<<endl;
    Prof.outputTextFile(fileOut);
    cout<<"Factors of the seniority, degree from the text file"<<endl;
    fileOut<<coefficient1<<endl<<coefficient2<<endl;
    cout<<coefficient2<<" "<<coefficient2<<endl;
}


//Методи класу Викладач
void Teacher::add(Student s)
{
    MyStudent s1(s.name,s.base, s.book);
        Students.push_back(s1);
        count1+=s.book.middle_mark()*s.book.size;
        count2+=s.book.size;

};
void Teacher::add(int number)
{
    for(int i=0; i < number;i++)
    {
        MyStudent s1;
        s1.input();
        Students.push_back(s1);
        count1+=s1.book.middle_mark()*s1.book.size;
        count2+=s1.book.size;
    }
}
void Teacher::add(int number, ifstream &fileIn)
{
    for(int i=0; i < number;i++)
    {
        MyStudent s1;
        s1.inputTextFile(fileIn);
        Students.push_back(s1);
        count1+=s1.book.middle_mark()*s1.book.size;
        count2+=s1.book.size;
        //cout<<endl<<count1<<" "<<s1.book.size<<endl;
    }
}
double Teacher::middlemark()
{
    if(count2==0)
        return 0;
    return count1/count2;
}

void Teacher::output_Students()
{

    cout<<endl<<"Students of the teacher "<<surname<<endl;
    if(Students.size())
    {
        for (int i = 0; i < Students.size(); i++)
        {
            Students[i].output();
        }
    }
    else
    {
        cout<<endl<<"This teacher has no students"<<endl;
    }
}
void Teacher::input_Students()
{
    int n;
    cout<<endl<<"Enter number of students:"<<endl;
    cin>>n;
    add(n);
}
void Teacher::outputTextFile_Students(ofstream &fileOut)
{
    cout<<endl<<"Writting number of students to a text file"<<endl;
    fileOut<<Students.size()<<endl;
    cout<<Students.size()<<endl;
    for(int i = 0; i < Students.size(); i++)
    {
        Students[i].outputTextFile(fileOut);
    }
}
void Teacher::inputTextFile_Students(ifstream &fileIn)
{
    cout<<endl<<"Students of the teacher "<<surname<<" from the text file"<<endl;
    cout<<"Number of the students"<<endl;
    int n;
    fileIn>>n;
    cout<<n<<endl;
    add(n,fileIn);
}
