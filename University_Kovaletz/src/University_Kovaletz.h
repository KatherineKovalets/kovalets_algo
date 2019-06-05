#ifndef UNIVERSITY_KOVALETZ_H_INCLUDED
#define UNIVERSITY_KOVALETZ_H_INCLUDED
#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>
/*
Хедер-файл проекту "University".
КЛАСИ:
Проект містить декітька класів: 4 основні, 3 домоміжні.
Першим основним класом є клас Persone(Людина), він абстрактний і на його базі побудовані класи Student(Студент)
і Worker(Працівник). На базі класу Worker побудований 4-й основний клас - Teacher(Викладач).
До допоміжних класів належать Recordbook(Заліковка), Profession(Професія) та локальний клас класу Вчитель MyStudent
(Студенти викладача). Клас MyStudent побудований на базі класу Студент.
Допоміжний клас Заліковка дружній з класом Студент, також клас Студент містить об'єкт класу Заліковка.
Клас Студент також дружній з класом Викладач.
Допоміжний клас Професія дружній з класами Працівник і Викладач, також клас Працівник містить об'єкт класу Професія.
Клас Викладач також дружній до класу Студент, містить його дочірній клас MyStudent і містить вектор, що складається з елементів
класу MyStudent.
ФУНКЦІЇ:
Клас Людина містить 4 чисто віртуальні функції(вони стосуються вводу-виводу з/на консоль та з/в текстовий файл)
 та віртуальний деструктор.
Віртуальний деструктор, окрім того, містить клас Працівник.
Ці 4 віртуальні функції в подальшому перевизначаються класами Студент і Працівник.
Отже, кожен клас містить функції вводу-виводу з/на консоль та з/в текстовий файл. Також кожен клас містить функціїї звернення
до полів класу.
Крім того, клас Заліковка містить функцію обрахунку середнього балу студента, Студент містить функцію обрахунку
своєї стипендії. Клас Працівник містить функцію обрахунку зарплати працівника.
Клас Викладач містить функцію знаходження середнього балу студентів, що навчаються у даного викладача, перевантажену функцію
add додавання студентів викладачу: можемо додати 1 студента в самій програмі, можемо додати кілька, вводячи дані про них з
консолі, можемо ввести кількох з файлу. є функції вводу-виводу студентів з/на консоль та з/в текстовий файл.
*/
using namespace std;

void inputTextFile(double &a, ifstream &fileIn);
void outputTextFile(double a, ofstream &fileOut);
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
            double middle_mark();//середня оцінка
            void output();
            void input();
            void inputTextFile(ifstream &fileIn);
            void outputTextFile(ofstream &fileOut);

        private:
            vector<string> disciplines;//дисципліни
            vector<int> marks;//оцінки
            friend class Student;
        };
class Student:public Persone// клас Студент, дочірній клас класу Людина, дружній з класом Заліковка і Викладач
{
protected:

    double coefficient;//коефіцієнт, що залежить від середнього балу студента
    int base;//базова стипендія
    string name;//ім'я
    Recordbook book;//заліковка
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
    double get_bursary();//стипендія
    void output();
    void input();
    void inputTextFile(ifstream &fileIn);
    void outputTextFile(ofstream &fileOut);
};
class Profession// клас Професія, дружній з классами Працівник і Викладач
    {
        string name;//назва
        int base_wage;//базова зарплата
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
class Worker: public Persone// клас Працівник, дочірній до Людини, дружній до класу Професія
{
protected:
    Profession Prof;//професія
    int seniority;//стаж
    int degree;//ступінь
    string surname;//фамілія
private:
    double coefficient1;//коефіцієнт ваги стажу
    double coefficient2;//коефіцієнт ваги ступіня
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
    double get_wage();//обрахунок зарплати
    double get_c1();
    double get_c2();
    void output();
    void input();
    void inputTextFile(ifstream &fileIn);
    void outputTextFile(ofstream &fileOut);
};
class Teacher: public Worker// клас Викладач, дочірній класа Працівник, дружній до класів Професія і Студент
{
   public:
    class MyStudent: public Student//клас Студенти викладача
    {
    public:
    MyStudent(){};
    MyStudent(string x, int y, Recordbook b):Student(x, y, b)
    {
    };
    ~MyStudent(){};
    } ;
     double count1;//допоміжні змінні
     double count2;//з яких отримаємо середню оцінку студентів даного викладача
    vector<class MyStudent> Students;//студенти даного викладача
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
    void add(Student s);//функції додавання студентів
    void add(int number);//визначена кількість з консолі
    void add(int number, ifstream &fileIn);//визначена кількість з файлу
    void output_Students();//вивід студентів на консоль
    void input_Students();//невизначена кількість з консолі
    void outputTextFile_Students(ofstream &fileOut);//запис у файл студентів
    void inputTextFile_Students(ifstream &fileIn);//невизначена кількість з файлу
    double middlemark();//середній бал студентів викладача
       friend class Profession;
       friend class Student;
};
#endif // UNIVERSITY_KOVALETZ_H_INCLUDED
