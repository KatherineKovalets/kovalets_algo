#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<stdbool.h>
#include"../headers/Quaternion_Kovaletz_Lesyk.h"
double epsilon = 0.01;
double pi=3.14159265358979323846;
void test(double a, double b,int *res);
void testV3D(vector3D a, vector3D b, int *res);
void testQuater(Quaternion a, Quaternion b, int *res);
void testP3D(Point3D a, Point3D b, int *res);
void testAngle3D(Angle3D a, Angle3D b, int *res);
void testFig3D(Figure3D a, Figure3D b, int *res);
int main()
{
    printf("\n In this test we will check all the main, not subsidiary functions. They all are used in main functions, so we regard them as tested\n\n");
int result = 0;
int expected_result = 19;
// В цій частині тестуємо програму за допомогою файлового вводу-виводу.
// іноді програма проситиме ввести будь-який знак, щоби продовжити. В такому випадку потрібно вводити.
// Це робиться, щоби користувачу було зручніше спостерігати за роботою програми.
printf("\nNow we will test functions unsing file input-output. Results will be written to tests/TextResult.txt. Data is token from tests/Text.txt");
    printf("\nPress any key and ENTER to continue\n");
    char s;
    scanf("%c",&s);
    //Тестуємо методи для структури Vector3D
    printf("\nTesting methods for Vector3D:\n");
    vector3D vector1, vector2;

    double n;
    FILE *file = NULL, *file1=NULL;
    printf("Open file\n");
    file = fopen("tests/Test.txt","r");
    file1 = fopen("tests/TestResult.txt","w");
    if(file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    if(file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    vector1=inputTextFileV3D(file);
    fgetc(file);
    vector2=inputTextFileV3D(file);
    fgetc(file);
    inputTextFile(&n,1,file);
    fgetc(file);
        printf("Sum of 2 vectors. Expected result (50,70,90):\n");
        outputTextFileV3D(summ(vector1,vector2), file1);
        printf("Substraction of 2 vectors. Expected result (-30,-30,-30):\n");
        outputTextFileV3D(subtraction(vector1,vector2), file1);
        printf("Cross product of 2 vectors. Expected result (300,-600,300):\n");
        outputTextFileV3D(Cross_product(vector1,vector2), file1);
        printf("Product of 2 vectors and scalar. Expected result (30,60,90) and (120,150,180):\n");
        outputTextFileV3D(Scalar_mult(vector1,n), file1);
        outputTextFileV3D(Scalar_mult(vector2,n), file1);
        printf("Dot product of 2 vectors. Expected result 3200:\n");
        fprintf(file1,"%10.4f\n",Dot_product(vector1,vector2));
        printf("\nPress any key and ENTER to continue\n");

        scanf("%c",&s);
        printf("\nTesting methods for Point3D:\n");
        Point3D point;
        point=inputTextFileP3D(file);
        fgetc(file);
        double m;
        inputTextFile(&m,1,file);
        fgetc(file);
        printf("Shpherical coordinates of the point. Expected result (37.42, 63.43,36.70):\n");
        outputTextFileP3D(spherical(point),file1);
        printf("Transition back to Decart coordinates. Expected result (10,20,30):\n");
        outputTextFileP3D(Spherical(spherical(point)),file1);
        printf("Cylindrical coordinates of the point. Expected result (22.36,63.43,30):\n");
        //output_DecP3D(cylindrical(point));
        outputTextFileP3D(cylindrical(point),file1);
        printf("Transition back to Decart coordinates. Expected result (10,20,30):\n");
        //output_DecP3D(Cylindrical(cylindrical(point)));
        outputTextFileP3D(Cylindrical(cylindrical(point)),file1);
        Point3D move;
        move=inputTextFileP3D(file);
        fgetc(file);
        printf("Moving point.Expected result (11,22,33):");
        //output_DecP3D(add(point,move));
        outputTextFileP3D(add(point,move),file1);
        printf("Product of point and scalar. Expected result (20,40,60):");
        //output_DecP3D(mult_scalar(point,m));
        outputTextFileP3D(mult_scalar(point, m),file1);
        printf("\nPress any key and ENTER to continue\n");
    scanf("%c",&s);
    scanf("%c",&s);
        Quaternion quaternion1,quaternion2;
        quaternion1=inputTextFileQuater(file);
        fgetc(file);
        quaternion2=inputTextFileQuater(file);
        fgetc(file);
        printf("sum of the quaternions. Expected result [40,(40,60,80)]:\n");
        //output_DecQuater(Sum(quaternion1, quaternion2));
        outputTextFileQuater(Sum(quaternion1, quaternion2),file1);
        printf("subtraction of the quaternions. Expected result [-20,(-20,-20,-20)]:\n");
        //output_DecQuater(Subtraction(quaternion1, quaternion2));
        outputTextFileQuater(Subtraction(quaternion1, quaternion2),file1);
        printf("Product of the quaternions. Expected result [-2300,(400,1400,1200)]:\n");
        //output_DecQuater(Multiplication(quaternion1, quaternion2));
        outputTextFileQuater(Multiplication(quaternion1, quaternion2),file1);
        printf("Division of the quaternions. Expected result [0.491525, (0.033898, -0.033898, 0.101695)]:\n");
        //output_DecQuater(Division(quaternion1, quaternion2));
        outputTextFileQuater(Division(quaternion1, quaternion2),file1);
        printf("\nPress any key and ENTER to continue\n");
        scanf("%c",&s);
        //Quaternion q={1,(1,2,3)};
        Angle3D angle;
    vector3D vector3;
    vector3=inputTextFileV3D(file);
    fgetc(file);
    vector3D vector4;
    vector4=inputTextFileV3D(file);
    fgetc(file);
    angle=get_angle(vector3,vector4);
    //output_DecAngle3D(angle);
    outputTextFileAngle3D(angle,file1);
    Figure3D figure;//розглядаємо пірамідку
    figure=inputTextFileFig3D(file);
    Point3D point2;
    point2=inputTextFileP3D(file);
    fgetc(file);
    //output_DecFig3D(figure);
    printf("turn3D\n");
    //output_DecFig3D(turn3D(figure,angle,point2));
    outputTextFileFig3D(turn3D(figure,angle,point2),file1);
    printf("We get figure turned as was expected");
    printf("\nprоjection3d\n");
    point2=inputTextFileP3D(file);

    fgetc(file);
    //output_DecFig3D(projection3D(figure,point2));
    outputTextFileFig3D(projection3D(figure,point2),file1);
    printf("We get points  (0,0,0),(0,0,0),(0,3,0),(0,5,0),as was expected");
        printf("\nPress any key and ENTER to continue\n");
        scanf("%c",&s);
    fclose(file1);
    file1 = NULL;
    file1 = fopen("tests/TestResult.txt","r");
    if(file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    //Звіряємо результати
    //Для структури Вектор-3Д
    //перевірка суми векторів
    vector3D expectV3D, resultV3D;
    expectV3D = inputTextFileV3D(file);
    fgetc(file);
    resultV3D = inputTextFileV3D(file1);
    fgetc(file1);
    testV3D(expectV3D, resultV3D, &result);
    //різниці векторів
    expectV3D = inputTextFileV3D(file);
    fgetc(file);
    resultV3D = inputTextFileV3D(file1);
    fgetc(file1);
    testV3D(expectV3D, resultV3D, &result);
    //векторний добуток
    expectV3D = inputTextFileV3D(file);
    fgetc(file);
    resultV3D = inputTextFileV3D(file1);
    fgetc(file1);
    testV3D(expectV3D, resultV3D, &result);
    //добутка векторів на скаляр
    expectV3D = inputTextFileV3D(file);
    fgetc(file);
    resultV3D = inputTextFileV3D(file1);
    fgetc(file1);
    testV3D(expectV3D, resultV3D, &result);

    expectV3D = inputTextFileV3D(file);
    fgetc(file);
    resultV3D = inputTextFileV3D(file1);
    fgetc(file1);
    testV3D(expectV3D, resultV3D, &result);
    //скалярний добуток
    double exp, res;
    inputTextFile(&exp, 1, file);
    fgetc(file);
    inputTextFile(&res, 1, file1);
    fgetc(file1);
    test(exp, res, &result);
    //Для структури Точка-3Д
    Point3D expectP3D, resultP3D;
    //сферичні координати
    fgetc(file);
    expectP3D = inputTextFileP3D(file);
    fgetc(file);
    resultP3D = inputTextFileP3D(file1);
    fgetc(file1);
    testP3D(expectP3D, resultP3D, &result);
    //циліндричні координати
    expectP3D = inputTextFileP3D(file);
    fgetc(file);
    resultP3D = inputTextFileP3D(file1);
    fgetc(file1);
    testP3D(expectP3D, resultP3D, &result);
    //зі сферичних до Декартових
    expectP3D = inputTextFileP3D(file);
    fgetc(file);
    resultP3D = inputTextFileP3D(file1);
    fgetc(file1);
    testP3D(expectP3D, resultP3D, &result);
    //З цилиндричних до Декартових
    expectP3D = inputTextFileP3D(file);
    fgetc(file);
    resultP3D = inputTextFileP3D(file1);
    fgetc(file1);
    testP3D(expectP3D, resultP3D, &result);
    //Рух точки
    expectP3D = inputTextFileP3D(file);
    fgetc(file);
    resultP3D = inputTextFileP3D(file1);
    fgetc(file1);
    testP3D(expectP3D, resultP3D, &result);
    //Множення точки на скаляр
    expectP3D = inputTextFileP3D(file);
    fgetc(file);
    resultP3D = inputTextFileP3D(file1);
    fgetc(file1);
    testP3D(expectP3D, resultP3D, &result);
    //Кватерніон
    Quaternion expectQuater, resultQuater;
    //сума кватерніонів
    expectQuater = inputTextFileQuater(file);
    fgetc(file);
    resultQuater = inputTextFileQuater(file1);
    fgetc(file1);
    testQuater(expectQuater, resultQuater, &result);
    //різниця
    expectQuater = inputTextFileQuater(file);
    fgetc(file);
    resultQuater = inputTextFileQuater(file1);
    fgetc(file1);
    testQuater(expectQuater, resultQuater, &result);
    //добуток
    expectQuater = inputTextFileQuater(file);
    fgetc(file);
    resultQuater = inputTextFileQuater(file1);
    fgetc(file1);
    testQuater(expectQuater, resultQuater, &result);
    //частка
    expectQuater = inputTextFileQuater(file);
    fgetc(file);
    resultQuater = inputTextFileQuater(file1);
    fgetc(file1);
    testQuater(expectQuater, resultQuater, &result);
    //Для 3Д кута повороту
    Angle3D expectAngle3D, resultAngle3D;
    expectAngle3D = inputTextFileAngle3D(file);
    fgetc(file);
    resultAngle3D = inputTextFileAngle3D(file1);
    fgetc(file1);
    testAngle3D(expectAngle3D, resultAngle3D, &result);
    //Для фігури 3Д
    Figure3D expectFigure3D, resultFigure3D;
    //поворот
    expectFigure3D = inputTextFileFig3D(file);
    resultFigure3D = inputTextFileFig3D(file1);
    testFig3D(expectFigure3D, resultFigure3D, &result);

    //Проекція
    expectFigure3D = inputTextFileFig3D(file);
    resultFigure3D = inputTextFileFig3D(file1);
    testFig3D(expectFigure3D, resultFigure3D, &result);
    fclose(file);
    fclose(file1);
    file1 = NULL;
    file1 = fopen("tests/TestResult.txt","at");
    if(file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    if(result == expected_result)
    {
        printf("\n All tests have been passed succesfully\n");
        fprintf(file1, "\n All tests have been passed succesfully\n");
    }
    printf("\nPress any key and ENTER to continue\n");
    scanf("%c",&s);
    scanf("%c",&s);
    fclose(file1);
    result=0;
    printf("\n\n\nNow we think it's unnessary to test file input-output, because all related functions vere succesfully used\n\n\n");


// В цій частині тестуємо програму за допомогою консольного вводу-виводу.
// ВАЖЛИВО вводити ті дані, які просять ввести. Тоді ми їх зможемо протестувати.
// іноді програма проситиме ввести будь-який знак, щоби продовжити. В такому випадку потрібно вводити.
// Це робиться, щоби користувачу було зручніше спостерігати за роботою програми.
    printf("\n Testing methods with input-output.\n");
    printf("\nAttention!\n Read guides carefully.\n Enter numbers you're asked to enter, other way we won't be able to test inputed results\n");
    printf("1) Separate numbers using gap when you enter them\n 2)Separate groups of numbers(points, vectors, Quaternion, etc) using key Enter \n");
    printf("\n Testint input-output for structures\n");
    printf("\nEnter vectors (30, 0, 15), (0, 1, 2) and scalar 2. You can try other ones, but then we won't be able to test results\n");
    vector3D vector01, vector02;
    vector01 = input_DecV3D();
    vector02 = input_DecV3D();
    double n0;
    inputDec(&n0,1);
    vector3D v;
        printf("Sum of 2 vectors. Expected results (30,1,17):\n");
        v.Coordinates[0]=30; v.Coordinates[1]=1; v.Coordinates[2]=17;
        output_DecV3D(summ(vector01,vector02));
        testV3D(summ(vector01,vector02),v,&result);
        printf("Substraction of 2 vectors. Expected result (30,-1,13):\n");
        v.Coordinates[0]=30; v.Coordinates[1]=-1; v.Coordinates[2]=13;
        output_DecV3D(subtraction(vector01,vector02));
        testV3D(subtraction(vector01,vector02),v,&result);
        printf("Cross product of 2 vectors. Expected result (-15,-60,30):\n");
        v.Coordinates[0]=-15; v.Coordinates[1]=-60; v.Coordinates[2]=30;
        output_DecV3D(Cross_product(vector01,vector02));

        testV3D(v, Cross_product(vector01,vector02),&result);

        printf("Product of 2 vectors and scalar. Expected result (60,0,30) and (0,2,4):\n");
        v.Coordinates[0]=60; v.Coordinates[1]=0; v.Coordinates[2]=30;
        output_DecV3D(Scalar_mult(vector01,n0));
        output_DecV3D(Scalar_mult(vector02,n0));
        testV3D(Scalar_mult(vector01,n0),v,&result);
        v.Coordinates[0]=0; v.Coordinates[1]=2; v.Coordinates[2]=4;
        testV3D(Scalar_mult(vector02,n0),v,&result);
        printf("Dot product of 2 vectors. Expected result 30:\n");
        double d=Dot_product(vector01,vector02);
        outputDec(&d,1);
        test(Dot_product(vector01,vector02),30,&result);
    printf("\nEnter point (34, 45, 0), move (1, 2, 3) and scalar 3. You can try other ones, but then we won't be able to test results\n");
    Point3D p;
    Point3D move0;
    p=input_DecP3D();
    move0=input_DecP3D();
    Point3D p0;
    double m0;
    inputDec(&m0,1);
        printf("Shpherical coordinates of the point. Expected result (56.4003, 1, 0.9237):\n");
        p0.Rad_vec.Coordinates[0] = 56.4003; p0.Rad_vec.Coordinates[1] = 1; p0.Rad_vec.Coordinates[2] = 0.9237;
        output_DecP3D(spherical(p));
        testP3D(spherical(p),p0,&result);
        printf("Transition back to Decart coordinates. Expected result (34, 45,0):\n");
        p0.Rad_vec.Coordinates[0] = 34; p0.Rad_vec.Coordinates[1] = 45; p0.Rad_vec.Coordinates[2] = 0;
        output_DecP3D(Spherical(spherical(p)));
        testP3D(Spherical(spherical(p)),p0,&result);
        printf("Cylindrical coordinates of the point. Expected result (56.4003, 0.9237, 0):\n");
        p0.Rad_vec.Coordinates[0] = 56.4003; p0.Rad_vec.Coordinates[1] = 0.9237; p0.Rad_vec.Coordinates[2] = 0;
        output_DecP3D(cylindrical(p));
        testP3D(cylindrical(p),p0,&result);
        printf("Transition back to Decart coordinates. Expected result (34,45,0):\n");
        p0.Rad_vec.Coordinates[0] = 34; p0.Rad_vec.Coordinates[1] = 45; p0.Rad_vec.Coordinates[2] = 0;
        output_DecP3D(Cylindrical(cylindrical(p)));
        testP3D(Cylindrical(cylindrical(p)),p0,&result);
        printf("Moving point.Expected result (35,47,3):");
        p0.Rad_vec.Coordinates[0] = 35; p0.Rad_vec.Coordinates[1] = 47; p0.Rad_vec.Coordinates[2] = 3;
        output_DecP3D(add(p,move0));
        testP3D(add(p,move0),p0,&result);
        printf("Product of point and scalar. Expected result (102,135,0):");
        p0.Rad_vec.Coordinates[0] = 102; p0.Rad_vec.Coordinates[1] = 135; p0.Rad_vec.Coordinates[2] = 0;
        output_DecP3D(mult_scalar(p,m0));
        testP3D(mult_scalar(p,m0),p0,&result);

        printf("\nEnter quaternions (10, 10, 20, 30), (30, 30, 40, 50) You can try other ones, but then we won't be able to test results\n");

        Quaternion quaternion01,quaternion02,q;
            quaternion01=input_DecQuater();
            quaternion02=input_DecQuater();
            printf("sum of the quaternions. Expected result [40,(40,60,80)]:\n");
            q.Re=40; q.Im[0]=40; q.Im[1]=60; q.Im[2]=80;
            output_DecQuater(Sum(quaternion01, quaternion02));
            testQuater(Sum(quaternion01, quaternion02),q,&result);
            printf("subtraction of the quaternions. Expected result [-20,(-20,-20,-20)]:\n");
            q.Re=-20; q.Im[0]=-20; q.Im[1]=-20; q.Im[2]=-20;
            output_DecQuater(Subtraction(quaternion01, quaternion02));
            testQuater(Subtraction(quaternion01, quaternion02),q,&result);
            printf("Product of the quaternions. Expected result [-2300,(400,1400,1200)]:\n");
            q.Re=-2300; q.Im[0]=400; q.Im[1]=1400; q.Im[2]=1200;
            output_DecQuater(Multiplication(quaternion01, quaternion02));
            testQuater(Multiplication(quaternion01, quaternion02),q,&result);
            printf("Division of the quaternions. Expected result [0.491525, (0.033898, -0.033898, 0.101695)]:\n");
            q.Re=0.491525; q.Im[0]=0.033898; q.Im[1]=-0.033898; q.Im[2]=0.101695;
            output_DecQuater(Division(quaternion01, quaternion02));
            testQuater(Division(quaternion01, quaternion02),q,&result);

        printf("\nEnter vectors(0,0,1) and (0,1,0) to get angle and axis. You can try other ones, but then we won't be able to test results\n");

        Angle3D angle0, a;
            vector3D vector03;
            vector03=input_DecV3D();
            vector3D vector04;
            vector04=input_DecV3D();
            printf("\n Gettting angle. Expected result 1.57, (-1,0,0)");
            a.angle=1.57; a.axis.Coordinates[0]=-1; a.axis.Coordinates[1]=0; a.axis.Coordinates[2]=0;
            angle0=get_angle(vector03,vector04);
            testAngle3D(a,get_angle(vector03,vector04),&result);
        Figure3D Figure0,F;

        printf("\nInput figure with number of points 2 and edges 1. Points:(3,2 1),(1,2,3). Edge (3,2 1),(1,2,3). You can try other ones, but then we won't be able to test results\n");

        Figure0=input_DecFigure3D();
        printf("\nInput point (0, 0, 0). We will turn our figure using this point and previously entered angle\n");
        p=input_DecP3D();
        output_DecFig3D(turn3D(Figure0,angle0,p));
        F.num_points=2; F.num_edges=1;
        F.points = calloc(F.num_points, sizeof(*F.points));
        for (int i=0;i<2;i++)
        {
            F.edges[i]=calloc(F.num_edges, sizeof(*F.edges[i]));
        }
        F.points[0].Rad_vec.Coordinates[0]=3; F.points[0].Rad_vec.Coordinates[1]=1; F.points[0].Rad_vec.Coordinates[2]=-2;
        F.points[1].Rad_vec.Coordinates[0]=1; F.points[1].Rad_vec.Coordinates[1]=3; F.points[1].Rad_vec.Coordinates[2]=-2;
        F.edges[0][0]=F.points[0]; F.edges[1][0]=F.points[1];
        testFig3D(F,turn3D(Figure0,angle0,p),&result);
        printf("\nInput point (0, 1, 0). We will project our figure using this point as a normal vector\n");
        p=input_DecP3D();
        output_DecFig3D(projection3D(Figure0,p));
        F.points[0].Rad_vec.Coordinates[0]=3; F.points[0].Rad_vec.Coordinates[1]=0; F.points[0].Rad_vec.Coordinates[2]=1;
        F.points[1].Rad_vec.Coordinates[0]=1; F.points[1].Rad_vec.Coordinates[1]=0; F.points[1].Rad_vec.Coordinates[2]=3;
        F.edges[0][0]=F.points[0]; F.edges[1][0]=F.points[1];
        testFig3D(F,projection3D(Figure0,p),&result);
        if(result==expected_result)
        {
            printf("All the tests were passed");
        }
        //Ця частина стосується просто різних варіантів вводу-виводу з консолі
        //Можна вводити будь-які значення

        FILE *FOUT=fopen("tests/TestBin.dat","wb");
        if(FOUT == NULL)
        {
            printf("Error opening file\n");
            exit(1);
        }
    printf("\nTesting input-output functions. just enter random numbers and see the results.\n");
    vector3D vector;
    vector=input_ExpV3D();
    output_ExpV3D(vector);
    vector=input_DecV3D();
    output_DecV3D(vector);
    outputBinFileV3D(vector,FOUT);
    Point3D point1;
    point1=input_ExpP3D();
    output_ExpP3D(point1);
    point1=input_DecP3D();
    output_DecP3D(point1);
    outputBinFileP3D(point1,FOUT);
    Quaternion quaternion;
    quaternion=input_ExpQuater();
    output_ExpQuater(quaternion);
    quaternion=input_DecQuater();
    output_DecQuater(quaternion);
    outputBinFileQuater(quaternion,FOUT);
    Angle3D angle1;
    angle1=input_ExpAngle3D();
    output_ExpAngle3D(angle1);
    angle1=input_DecAngle3D();
    output_DecAngle3D(angle1);
    outputBinFileAngle3D(angle1,FOUT);
    Figure3D figure1;
    figure1=input_ExpFigure3D();
    output_ExpFig3D(figure1);
    figure1=input_DecFigure3D();
    output_DecFig3D(figure1);
    outputBinFileFig3D(figure1,FOUT);
    fclose(FOUT);
        FOUT=fopen("tests/TestBin.dat","rb");
        if(FOUT == NULL)
        {
            printf("Error opening file\n");
            exit(1);
        }
    fclose(FOUT);
    return 0;
}

void test(double a, double b,int *res)
{
    if(abs(a - b)<epsilon)
    {
        printf("\nTest passed succesfully\n");
        *res=*res+1;
    }
}
void testV3D(vector3D a, vector3D b, int *res)
{
    bool flag = true;
    for (int i=0; i < 3; i++)
    {
        if(abs(a.Coordinates[i] - b.Coordinates[i]) > epsilon)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        printf("\nTest passed succesfully\n");
        *res=*res+1;
    }
}
void testQuater(Quaternion a, Quaternion b, int *res)
{
    bool flag = true;
    if(abs(a.Re - b.Re) > epsilon)
    {
        flag = false;
    }
    for (int i=0; i < 3; i++)
    {
        if(abs(a.Im[i] - b.Im[i]) > epsilon)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        printf("\nTest passed succesfully\n");
        *res=*res+1;
    }
}
void testP3D(Point3D a, Point3D b, int *res)
{
    testV3D(a.Rad_vec, b.Rad_vec, res);
}
void testAngle3D(Angle3D a, Angle3D b, int *res)
{
    int temp_result=0;
    test(a.angle, b.angle, &temp_result);
    testV3D(a.axis, b.axis, &temp_result);
    if(temp_result == 2)
    {
        printf("\nTest passed succesfully\n");
        *res=*res+1;
    }
}
void testFig3D(Figure3D a, Figure3D b, int *res)
{
    if((a.num_points == b.num_points)&&(a.num_edges == b.num_edges))
    {
        int temp_result=0;
        bool flag = true;
        for(int i = 0; i<a.num_points;i++)
        {
            for (int j = 0; j < 3;j++)
            {
                if ((abs(a.points[i].Rad_vec.Coordinates[j] - b.points[i].Rad_vec.Coordinates[j]) > epsilon))
                {
                    flag = false;
                    break;
                };

            }
        }
        for(int i = 0; i<a.num_edges; i++)
        {
            for(int j = 0;j<2;j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(abs(a.edges[j][i].Rad_vec.Coordinates[k] - b.edges[j][i].Rad_vec.Coordinates[k]) > epsilon)
                    {
                        flag = false;
                        break;
                    };

                }
            }
        }
        if(flag)
        {
            printf("\nTest passed succesfully\n");
            *res=*res+1;
        }
    }
}
