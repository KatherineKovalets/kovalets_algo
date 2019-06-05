#include <iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include "../src/University_Kovaletz.h"

double epsilon = 0.01;
void test(double a, double b,int *res);
void test_Recbook(Recordbook a, Recordbook b, int *res);
void test_Std(Student a,Student b, int *res);
void test_Prof(Profession a, Profession b, int *res);
void test_Worker(Worker a, Worker b, int *res);
void test_Teacher(Teacher a, Teacher b, int *res);
int main()
{
    //іноді програма переривається на "Введіть будь-який символ, щоби продовжити". Це потрібно, щоби дії, що відбуваються
    //у програмі міг спостерігати користувач.
    char s;
    int res=0, expected_result=10;
    //тестуємо методи, використовуючи файловий ввід-вивід.
    //Резльтат пройденого тесту "All the tests were passed" записується по закінченні в текстовий файл
    //"TestResult.txt"
    cout<<endl<<"Testing methods using input to text file and output from the text file"<<endl;
    ifstream fileIn;
    ofstream fileOut;
    fileIn.open("tests/Test.txt",ios_base::in);
    fileOut.open("tests/TestResult.txt",ios_base::trunc|ios_base::out);
    if(!fileIn.is_open())
    {
        cout<<"FileIn is not open"<<endl;
    }
    if(!fileOut.is_open())
    {
        cout<<"FileOut is not open"<<endl;
    }
    Teacher Petrova;
    Teacher Zrazhevsky;
    Petrova.inputTextFile(fileIn);
    Zrazhevsky.inputTextFile(fileIn);
    Petrova.inputTextFile_Students(fileIn);
    Zrazhevsky.inputTextFile_Students(fileIn);
    cout<<"Writing information about one of the teacher(Petrova) and his students first to a text file"<<endl;
    Petrova.outputTextFile(fileOut);
    Petrova.outputTextFile_Students(fileOut);
    cout<<"Writing wages to a  text file"<<endl;
    outputTextFile(Petrova.get_wage(),fileOut);
    outputTextFile(Zrazhevsky.get_wage(),fileOut);
    cout<<"Writing Petrova's and Zrazhevsky's studentses middle marks to a  text file"<<endl;
    cout<<" "<<Petrova.middlemark()<<" "<<Zrazhevsky.middlemark()<<endl;
    outputTextFile(Petrova.middlemark(),fileOut);
    outputTextFile(Zrazhevsky.middlemark(),fileOut);
    for (int i = 0; i < Petrova.Students.size(); i++)
    {
        outputTextFile(Petrova.Students[i].get_bursary(), fileOut);
    }
    for (int i = 0; i < Zrazhevsky.Students.size(); i++)
    {
        outputTextFile(Zrazhevsky.Students[i].get_bursary(), fileOut);

    }
    fileOut.close();
    ifstream fileIn1;
    fileIn1.open("tests/TestResult.txt",ios_base::in);
    if(!fileIn1.is_open())
    {
        cout<<"FileIn is not open"<<endl;
    }
    double expected, result;
    Teacher In;
    cout<<endl<<"Getting teacher and his students from the text file"<<endl;
    In.inputTextFile(fileIn1);
    In.inputTextFile_Students(fileIn1);
    test_Teacher(In,Petrova,&res);
    while((!fileIn.eof())&&(!fileIn1.eof()))
    {
        inputTextFile(expected,fileIn);
        inputTextFile(result,fileIn1);
       cout<<expected<<" "<<result<<endl;
        test(expected,result,&res);
    }
    fileIn1.close();
    fileOut.open("tests/TestResult.txt",ios_base::app);

    if(res == expected_result)
    {
        fileOut<<"All the tests were  passed succesfully"<<endl;
        fileOut.close();
        cout<<"All the tests were  passed succesfully"<<endl;
    }
    cout<<"Enter any char key to continue"<<endl;
    cin>>s;

    res = 0;
    expected_result=5;
    //далі тестуємо програму вводом/виводум з консолі
    // ВАЖЛИВО вводити ті дані, які просить ввести програма, а не будь-які. Тоді це можна буде протестувати
    cout<<endl<<"Testing methods using constructors and console input and output"<<endl;
    cout<<endl<<"Input exactly what you're asked to input, so we will be able to test results"<<endl;
    cout<<"Enter any char key to continue"<<endl;
    cin>>s;
    string arr[]={"Mat", "Diff", "Prog"};
    string arr1[]={"Mat", "Diff", "Prog","Mech"};
    string arr2[]={"Mat", "Diff", "Prog"};
    //string arr3[]={"Phil", "Games","UZK"};
    vector<string> x(arr,arr+3),x1(arr1,arr1+4),x2(arr2,arr2+3);
    int arr0[]={100,90,85};
    int arr01[]={90,90,90,90};
    int arr02[]={61,80,65};
    //int arr03[]={99,75,80};
    vector<int> y(arr0,arr0+3), y1(arr01,arr01+4), y2(arr02,arr02+3);
    Recordbook BookArthem(x, y);
    Recordbook BookKate(x1, y1);
    Recordbook BookEvgeniy(x2, y2);
    //Recordbook BookIliya(x3, y3);
    Student Arthem("Arthem", 1200,BookArthem);
    Student Kate("Kate", 1200,BookKate);
    Student Evgeniy("Evgeniy", 1200,BookEvgeniy);
    //Student Iliya("Iliya", 1200,BookIliya);
    Profession Teacher1("Teacher",10000);
    Teacher Petrova01("Petrova",20,3,0.07,0.02,Teacher1);
    Petrova01.add(Arthem);
    //Petrova01.add(Iliya);
    Petrova01.add(Evgeniy);
    cout<<"Petrova's students' middle mark: "<<Petrova01.middlemark()<<endl;
    cout<<"Expected result: 80.1666"<<endl;
    test(Petrova01.middlemark(),80.1666,&res);
    cout<<res<<endl;
    Petrova01.output();
    cout<<endl<<"Expected results:"<<endl<<"Surname: "<<"Petrova"<<" Seniority: "<<20<<" Degree: "<<3<<endl;
    cout<<"Profession: "<<"Teacher"<<" Base wage: "<<10000;
    cout<<"Factors of the seniority, dergee: "<<0.07<<" "<<0.02<<endl;
    cout<<"Wage"<<endl;
    cout<<10000+(0.02*3+0.07*20)*10000<<endl;
    test(Petrova01.get_wage(),10000+(0.02*3+0.07*20)*10000,&res);
    cout<<res<<endl;
    Arthem.output();
    cout<<endl<<"Expected results:"<<endl;
    cout<<"Name "<<"Arthem"<<endl<<"Base bursary "<<1200<<endl<<"Middle mark "<<91.666<<endl<<"Bursary "<<1200*91.666/100+1200<<endl;
    cout<<"Recordbook "<<endl;
    for(int i=0;i<x.size();i++)
    {
       cout<<x[i]<<" "<<y[i]<<endl;
    }

    test(Arthem.get_bursary(),1200*91.666/100+1200,&res);
    cout<<res<<endl;
    Teacher Zrazhevsky0("Zrazhevsky",30,3,0.07,0.02,Teacher1);
    Zrazhevsky0.add(Kate);
    cout<<"Zrazhevsky's students' middle mark: "<<Zrazhevsky0.middlemark()<<endl;
    cout<<"Expected result: 90"<<endl;
    test(Zrazhevsky0.middlemark(),90,&res);
    cout<<res<<endl;

    Teacher Petrova0;
    cout<<endl<<"Input information about Petrova:"<<endl<<"Surname - Petrova, seniority - 20, degree - 3"<<endl;
    cout<<"Profession:Teacher, base wage - 10000"<<endl;
    cout<<"factor of seniority - 0.07,";
    cout<<" factor of degree - 0.02"<<endl;
    cout<<endl<<"Input exactly what you're asked to input, so we will be able to test results"<<endl;
    Petrova0.input();
    Student A;
    cout<<endl<<"Input information about student:"<<endl<<"Name - Arthem, base - 1200"<<endl;
    cout<<"His recordbook with number of disciplines - 3;"<<endl;
    cout<<"Disciplines and marks: Mat - 100, Diff - 90, Prog - 85"<<endl;
    cout<<endl<<"Input exactly what you're asked to input, so we will be able to test results"<<endl;
    A.input();
    Student B;
    cout<<endl<<"Input information about student:"<<endl<<"Name - Evgeniy, base - 1200"<<endl;
    cout<<"His recordbook with number of disciplines - 3;"<<endl;
    cout<<"Disciplines and marks: Mat - 61, Diff - 80, Prog - 65"<<endl;
    cout<<endl<<"Input exactly what you're asked to input, so we will be able to test results"<<endl;
    B.input();
    Petrova0.add(A); Petrova0.add(B);
    test_Teacher(Petrova0,Petrova01,&res);
    if(res == expected_result)
    {
        cout<<endl<<endl<<"All the tests were  passed succesfully"<<endl;
    }
    cout<<"Enter any char key to continue"<<endl;
    cin>>s;
    // Ця частина програми не тестується. Ми просто додаємо викладачу нових студентів і виводимо всіх його студентів на екран.
    // можна вводити будь-які дані.
    cout<<"Add any number of students to teacher Petrova"<<endl;
    Petrova0.input_Students();
    cout<<"Show students:"<<endl;
    Petrova0.output_Students();

    return 0;
}

void test(double a, double b,int *res)
{
    if(abs(a - b)<epsilon)
    {
        printf("Test passed succesfully\n");
        *res=*res+1;
    }
}
void test_Recbook(Recordbook a, Recordbook b, int *res)
{
    int temp=0;
    if(a.size==b.size)
    {
        for(int i = 0; i < a.size; i++)
        {
            test(a.get_marks()[i],b.get_marks()[i],&temp);
            if(a.get_disciplines()[i]!=a.get_disciplines()[i])
            {
                temp=0;
                break;
            }
        }
    }
    if (temp==a.size)
    {
        printf("Test passed succesfully\n");
        *res=*res+1;
    }
};
void test_Std(Student a,Student b, int *res)
{
    int temp=0;
    test_Recbook(a.get_recordbook(),b.get_recordbook(),&temp);
    test(a.get_bursary(),b.get_bursary(),&temp);
    test(a.get_coefficient(),b.get_coefficient(),&temp);
    test(double(a.get_base()),double(b.get_base()),&temp);
    if ((temp==4)&&(a.get_name()==b.get_name()))
    {
        printf("Test passed succesfully\n");
        *res=*res+1;
    }
};
void test_Prof(Profession a, Profession b,int *res)
{
    if((a.get_name()==b.get_name())&&(a.get_base()==b.get_base()))
    {
        printf("Test passed succesfully\n");
        *res=*res+1;
    }
}
void test_Worker(Worker a, Worker b, int *res)
{
    int temp=0;
    test_Prof(a.get_Prof(),b.get_Prof(),&temp);
    test(a.get_c1(),b.get_c1(),&temp);
    test(a.get_c2(),b.get_c2(),&temp);
    test(double(a.get_seniority()), double(b.get_seniority()),&temp);
    test(double(a.get_wage()), double(b.get_wage()),&temp);
    if ((temp==5)&&(a.get_surname()==b.get_surname()))
    {
        printf("Test passed succesfully\n");
        *res=*res+1;
    }
};
void test_Teacher(Teacher a, Teacher b, int *res)
{
   int temp=0;
   test_Worker(a,b,&temp);
   if(a.Students.size()==b.Students.size())
   {
       for(int i = 0;i < a.Students.size(); i++)
       {
           test_Std(a.Students[i],b.Students[i], &temp);
       }
       if(temp == a.Students.size()+1)
       {
            printf("Test passed succesfully\n");
           *res=*res+1;
       }
   }
};
