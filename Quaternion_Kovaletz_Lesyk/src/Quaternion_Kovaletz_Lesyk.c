#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include "../headers/Quaternion_Kovaletz_Lesyk.h"
//Усі структури прописані явно в "headers/Quaternion_Kovaletz.h" з відповідними коментарями.
// В цьому файлі лише їх оголошення
// Усі стандартні функції, що стосуються виводу-вводу прописані в кінці цього файлу
// Усі дії відбуваються в Декартовій правій системі координат
struct vector3D;//допоміжна структура 3-Д вектор
vector3D summ(vector3D a, vector3D b)//сума векторів
{
    vector3D c;
    for (int i = 0; i < 3; i++)
    {
        c.Coordinates[i] = a.Coordinates[i] + b.Coordinates[i];
    }
    return c;

}
vector3D subtraction  (vector3D a, vector3D b)//різниця векторів
{
    vector3D c;
    for (int i = 0; i < 3; i++)
    {
        c.Coordinates[i] = a.Coordinates[i] - b.Coordinates[i];
    }
    return c;

}
vector3D Scalar_mult(vector3D a, double b)//множення вектора на скаляр
{
    vector3D c;
    for (int i = 0; i < 3; i++)
    {
        c.Coordinates[i] = a.Coordinates[i]*b;
    }
    return c;
}
double Dot_product(vector3D a,vector3D b)//Скалярний добуток
{
    double product = 0;
    for (int i = 0; i < 3; i++)
    {
        product += a.Coordinates[i]*b.Coordinates[i];
    }
    return product;
}
vector3D Cross_product(vector3D a, vector3D b)//Векторний добуток
{
    vector3D product;
    product.Coordinates[0] = - a.Coordinates[2] * b.Coordinates[1] + a.Coordinates[1] * b.Coordinates[2];
    product.Coordinates[1] = - a.Coordinates[0] * b.Coordinates[2] + a.Coordinates[2] * b.Coordinates[0];
    product.Coordinates[2] = - a.Coordinates[1] * b.Coordinates[0] + a.Coordinates[0] * b.Coordinates[1];
    return product;
}
double norm (vector3D a)//модуль
{
    double norm = 0;
    for (int i = 0; i < 3; i++)
    {
        norm += a.Coordinates[i] * a.Coordinates[i];
    }
    return sqrt(norm);
}
//Структура Кватерніон
struct Quaternion;
// Допоміжні операції: знаходження спраженного, оберненого та модулю кватерніона,ділення та множення кватерніона на скаляр
Quaternion Conjudation (Quaternion a)//спряжений
{
    Quaternion c;
    for (int i = 0; i < 3; i++)
    {
        c.Im[i] = -a.Im[i];
    }
    c.Re=a.Re;
    return c;
}
Quaternion Scalar_div(Quaternion a,double b)//ділення кватерніона на скаляр
{
    Quaternion c;
    for (int i = 0; i < 3; i++)
    {
        c.Im[i] = a.Im[i]/b;
    }
    c.Re=a.Re/b;
    return c;
}
Quaternion scalar_mult(Quaternion a, double b)//множення кватерніона на скаляр
{
    Quaternion c;
    for (int i = 0; i < 3; i++)
    {
        c.Im[i] = a.Im[i]*b;
    }
    c.Re=a.Re*b;
    return c;
}
double Norm (Quaternion a)//модуль
{
    double norm = 0;
    for (int i = 0; i < 3; i++)
    {
        norm += a.Im[i]*a.Im[i];
    }
    norm += a.Re*a.Re;
    return sqrt(norm);
}
Quaternion  Reciprocal (Quaternion a)//обернений
{
    Quaternion r;
    r = Scalar_div(Conjudation(a),Norm(a)*Norm(a));
    return r;
}
//Стандартні операції
Quaternion Sum (Quaternion a, Quaternion b)//сума
{
    Quaternion c;
    for (int i=0;i<3;i++)
    {
        c.Im[i] = a.Im[i] + b.Im[i];
    }
    c.Re = a.Re + b.Re;
    return c;
}
Quaternion Subtraction (Quaternion a,Quaternion b)//різниця
{
    Quaternion c;
    for (int i=0;i<3;i++)
    {
        c.Im[i] = a.Im[i] - b.Im[i];
    }
    c.Re=a.Re-b.Re;
    return c;
}
Quaternion Multiplication(Quaternion a, Quaternion b)//множення кватерніона на кватерніон
{
    Quaternion c;
    c.Re = a.Re*b.Re - a.Im[0]*b.Im[0] - a.Im[1]*b.Im[1] - a.Im[2]*b.Im[2];
    c.Im[0] = a.Re*b.Im[0] + b.Re*a.Im[0] + a.Im[1]*b.Im[2] - b.Im[1]*a.Im[2];
    c.Im[1] = a.Re*b.Im[1] + b.Re*a.Im[1] + a.Im[2]*b.Im[0] - b.Im[2]*a.Im[0];
    c.Im[2] = a.Re*b.Im[2] + b.Re*a.Im[2] + a.Im[0]*b.Im[1] - b.Im[0]*a.Im[1];
    return c;
}
Quaternion Division(Quaternion a, Quaternion b)//ділення кватерніона на кватерніон
{
    return Multiplication(a,Reciprocal(b));
}
Quaternion Multiplication_Vector(Quaternion a, vector3D b)//множення кватерніона на вектор
{
    Quaternion c;
   c.Re=0;
    for (int i=0;i<3;i++)
    {
        c.Im[i]=b.Coordinates[i];
    }
    return Multiplication(a,c);
}
struct Point3D ;
Point3D spherical(Point3D x)
{
    Point3D Sphere;
    Sphere.Rad_vec.Coordinates[0] = sqrt(x.Rad_vec.Coordinates[0] * x.Rad_vec.Coordinates[0] +
    x.Rad_vec.Coordinates[1] * x.Rad_vec.Coordinates[1] +
    x.Rad_vec.Coordinates[2] * x.Rad_vec.Coordinates[2]);
    Sphere.Rad_vec.Coordinates[1] =  atan2(sqrt(x.Rad_vec.Coordinates[0] * x.Rad_vec.Coordinates[0] +
    x.Rad_vec.Coordinates[1] * x.Rad_vec.Coordinates[1]),x.Rad_vec.Coordinates[2]);
    Sphere.Rad_vec.Coordinates[2] =  atan( x.Rad_vec.Coordinates[1]/x.Rad_vec.Coordinates[0]);

    return Sphere;
}
Point3D cylindrical (Point3D x)
{
    Point3D Cylindr;
    Cylindr.Rad_vec.Coordinates[0] = sqrt(x.Rad_vec.Coordinates[0] * x.Rad_vec.Coordinates[0] +
    x.Rad_vec.Coordinates[1] * x.Rad_vec.Coordinates[1]);
    Cylindr.Rad_vec.Coordinates[1] = atan2(x.Rad_vec.Coordinates[1],x.Rad_vec.Coordinates[0]);
    Cylindr.Rad_vec.Coordinates[2] = x.Rad_vec.Coordinates[2];
    return Cylindr;
}
Point3D Spherical(Point3D x)
{
    double r = x.Rad_vec.Coordinates[0], teta = x.Rad_vec.Coordinates[1], fi = x.Rad_vec.Coordinates[2];
    x.Rad_vec.Coordinates[0] = r * sin(teta) * cos(fi);
    x.Rad_vec.Coordinates[1] = r * sin(teta) * sin(fi);
    x.Rad_vec.Coordinates[2] = r * cos(teta);
    return x;
}
Point3D Cylindrical(Point3D x)
{
    double ro = x.Rad_vec.Coordinates[0], fi = x.Rad_vec.Coordinates[1], z = x.Rad_vec.Coordinates[2];
    x.Rad_vec.Coordinates[0] = ro * cos(fi);
    x.Rad_vec.Coordinates[1] = ro * sin(fi);
    x.Rad_vec.Coordinates[2] = z;
    return x;
}
Point3D mult_scalar(Point3D x, double a)// множення на скаляр
{
    x.Rad_vec = Scalar_mult(x.Rad_vec, a);
    return x;
}
Point3D add (Point3D x, Point3D movement)
{
    Point3D result;
    result.Rad_vec = summ(x.Rad_vec, movement.Rad_vec);
    return result;
}
//Структура - кут повороту. Задається віссю обертання та, власне, кутом повороту навколо неї
struct Angle3D;
//Сферичний кут - кут між двома площинами, отже, представляється як кут між двома векторами. Вісь обертання задається
//як вектор, перпендикулярний до цих двох верторів, і такий, що утворює с ними праву трійку. Тобто як векторний добуток
//у правій Декартовій системі координат.
//Кут повороту визначається як кут між такими векторами
Angle3D get_angle(vector3D a, vector3D b)
{
    Angle3D result;
    result.axis = Cross_product(a, b);
    result.angle = acos(Dot_product(a, b)/norm(a)/norm(b));
    return result;
}
// Структура - 3Д фігура
struct Figure3D;
Figure3D turn3D(Figure3D f, Angle3D a, Point3D p)// поворот фігури
{
    Figure3D Turn;
    Figure3D Temp;
    Turn.num_points = f.num_points;
    Turn.num_edges = f.num_edges;
    Temp.num_points = f.num_points;
    Temp.num_edges = f.num_edges;
    Turn.points = calloc(Turn.num_points, sizeof(*Turn.points));
    for (int i=0;i<2;i++)
    {
        Turn.edges[i]=calloc(Turn.num_edges, sizeof(*Turn.edges[i]));
    }
Temp.points = calloc(Temp.num_points, sizeof(*Temp.points));
for (int i=0;i<2;i++)
{
    Temp.edges[i]=calloc(Temp.num_edges, sizeof(*Temp.edges[i]));
}
    double alpha = a.angle/2;
    vector3D axis = Scalar_mult(a.axis,1/norm(a.axis));
    Quaternion q;
    q.Re = cos(alpha);
    for (int i = 0; i < 3; i++)
    {
        q.Im[i] = axis.Coordinates[i] * (double)sin(alpha);
    }

    for (int i=f.num_points;i>0;i--)
    {
        Temp.points[i-1].Rad_vec = subtraction(f.points[i-1].Rad_vec, p.Rad_vec);
    } //наразі ми змістили точку, відносно якої обертаєто фігуру в початок координат (0,0,0), відповідно, кожна точка фігури
    //зсунулась на вектор, протилежний радіус-вектору точки p

    for (int i = 0; i < f.num_edges; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Temp.edges[j][i].Rad_vec = subtraction(f.edges[j][i].Rad_vec, p.Rad_vec);
        }
    }
    Quaternion temp;

    for (int i = 0; i < Temp.num_points; i++)
    {
        temp = Multiplication(Multiplication_Vector(q, Temp.points[i].Rad_vec), Reciprocal(q));
       output_DecQuater(temp);
       for (int j = 0; j < 3; j++)
       {
            Turn.points[i].Rad_vec.Coordinates[j] = temp.Im[j];
       }
    }
    for (int i = 0; i < Temp.num_edges; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp = Multiplication(Multiplication_Vector(q, Temp.edges[j][i].Rad_vec), Reciprocal(q));
           for (int k = 0; k < 3; k++)
           {
                Turn.edges[j][i].Rad_vec.Coordinates[k] = temp.Im[k];
           }
        }
    }
    //Ми вже здійснили поворот фігури відносно початку координат. Тепер зсунемо фігуру на радіус-вектор точки р.
    // Отримана фігура є результатом повороту початкової фігури відносно заданної точки.
  for (int i = 0; i < Turn.num_points; i++)
    {
        Turn.points[i] = add(Turn.points[i], p);
    }
    for (int i = 0; i < Turn.num_edges; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Turn.edges[j][i] = add(Turn.edges[j][i], p);
        }
    }
    return Turn;
}

Figure3D projection3D(Figure3D f, Point3D p)//проекція фігури
{
    Figure3D Proj;
    Proj.num_points = f.num_points;
    Proj.num_edges = f.num_edges;
    Proj.points = calloc(Proj.num_points, sizeof(*Proj.points));
    for (int i=0;i<2;i++)
    {
        Proj.edges[i]=calloc(Proj.num_edges, sizeof(*Proj.edges[i]));
    }

    for(int i = 0; i < f.num_points; i++)
    {
        Proj.points[i].Rad_vec = subtraction(f.points[i].Rad_vec,
        Scalar_mult(p.Rad_vec,Dot_product(f.points[i].Rad_vec, p.Rad_vec)/norm(p.Rad_vec)/norm(p.Rad_vec)));
        //формулу для обчислення координат проекції точки дивитьсь за посиланням http://cyclowiki.org/wiki/Проекция_точки_на_плоскость
    }
    for (int i = 0; i < f.num_edges; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Proj.edges[j][i].Rad_vec =  subtraction(f.edges[j][i].Rad_vec,
        Scalar_mult(p.Rad_vec, Dot_product(f.edges[j][i].Rad_vec, p.Rad_vec)/norm(p.Rad_vec)/norm(p.Rad_vec)));
        }
    }
    return Proj;
}
//Функції вводу-виводу
int inputDec(double *x,int len)
{
    for(int i = 0; i<len; i++)
    {
        double n;
        scanf("%lf",&n);
        x[i] = n;
    }
    return 0;
}
int inputExp(double *x,int len)
{
    for(int i = 0; i<len; i++)
    {
        double n;
        scanf("%le",&n);
        x[i] = n;

    }
    return 0;
}
void inputBinFile(double *x, int len,FILE *file)
{
   fread(&x, sizeof(double), len, file);
   for (int i = 0;i<len;i++)
   {
       printf("%f",x[i]);
   }
}
void inputTextFile(double *x, int len,FILE *file)//ввід з текстового файлу
{
    int i=0;
    char ch;
    while((ch=getc(file))!='\n')
    {
        fscanf(file, "%lf", &(x[i]));
        printf("%10.4f", x[i]);
        i++;
        if(i == len)
        {
            break;
        }
    }
}
int outputDec(double *x,int len)
{
    for(int i = 0; i<len; i++)
    {
        printf("%10.4f%c", x[i],' ');
    }

    return 0;
}
int outputExp(double *x,int len)
{
    for(int i = 0; i<len; i++)
    {
        printf("%10.4e ",x[i]);
    }
    return 0;
}
void outputBinFile(double *x, int len, FILE *file)
{
   fwrite(&x, sizeof(double), len, file);
   //fclose(file);
}
void outputTextFile(double *x, int len, FILE *file)
{
    int i=0;
    while(1)
    {
        fprintf(file, " %f", x[i]);
        printf("%10.4f", x[i]);
        i++;
        if(i == len)
        {
            break;
        }
    }
        fprintf(file, "\n");
}
// для структури вектор
vector3D input_DecV3D()
{
    printf("\n");
    printf("\nEnter decimal vector coordinates:\n");
    vector3D result;
    inputDec(result.Coordinates, 3);
    return result;
}
vector3D input_ExpV3D()
{
    printf("\nEnter exponential vector coordinates:\n");
    vector3D result;
    inputExp(result.Coordinates, 3);
    printf("\n");
    return result;
}
vector3D inputTextFileV3D(FILE *file)
{
    printf("\nVector coordinates from text file:\n");
    vector3D result;
    inputTextFile(result.Coordinates, 3, file);
    printf("\n");
    return result;
}
vector3D inputBinFileV3D(FILE *file)
{

    printf("\nVector coordinates from bin file:\n");
    vector3D result;
    inputBinFile(result.Coordinates, 3, file);
    printf("\n");
    return result;
}
void output_DecV3D(vector3D x)
{
    printf("\nVector coordinates decimal:\n");
    outputDec(x.Coordinates, 3);
    printf("\n");
}
void output_ExpV3D(vector3D x)
{
    printf("\nVector coordinates exponential:\n");
    outputExp(x.Coordinates, 3);
    printf("\n");
}
void outputBinFileV3D(vector3D x, FILE *file)
{
    printf("\nVector coordinates are written to a binary file:\n");
    outputBinFile(x.Coordinates, 3, file);
    printf("\n");
}
void outputTextFileV3D(vector3D x, FILE *file)
{
    printf("\nVector coordinates are written to a text file:\n");
    outputTextFile(x.Coordinates, 3, file);
    printf("\n");
}
//для структури Quaternion
Quaternion input_DecQuater()
{
    Quaternion result;
    double x[4];
    printf("\nEnter quaternion Re and 3 Im parts (decimal):\n");
    inputDec(x, 4);
    result.Re = x[0];
    result.Im[0] = x[1];
    result.Im[1] = x[2];
    result.Im[2] = x[3];
    printf("\n");
    return result;
}
Quaternion input_ExpQuater()
{
    Quaternion result;
    double x[4];
    printf("\nEnter quaternion Re and 3 Im parts (exponential):\n");
    inputExp(x, 4);
    result.Re = x[0];
    result.Im[0] = x[1];
    result.Im[1] = x[2];
    result.Im[2] = x[3];
    printf("\n");
    return result;
}
Quaternion inputTextFileQuater(FILE *file)
{
    printf("\nQuaternion from text file:\n");
    Quaternion result;
    double x[4];
    //char ch;
    //if(getc(file)=='\n')
    //{
      //  fgetc(file);
    //}
    inputTextFile(x, 4, file);
    result.Re = x[0];
    result.Im[0] = x[1];
    result.Im[1] = x[2];
    result.Im[2] = x[3];
    printf("\n");
    return result;

}
Quaternion inputBinFileQuater(FILE *file)
{
    printf("\nQuaternion from bin file:\n");
    Quaternion result;
    double x[4];
    inputBinFile(x, 4, file);
    result.Re = x[0];
    result.Im[0] = x[1];
    result.Im[1] = x[2];
    result.Im[2] = x[3];
    printf("\n");
    return result;
    }
void output_DecQuater(Quaternion x)
{

    printf("\nQuaternion (decimal)\n");
    outputDec(&(x.Re), 1);
    outputDec(x.Im, 3);
    printf("\n");
}

void output_ExpQuater(Quaternion x)
{
    printf("\nQuaternion (exponential):\n");
    outputExp(&(x.Re), 1);
    outputExp(x.Im, 3);
    printf("\n");
}
void outputBinFileQuater(Quaternion x, FILE *file)
{
    printf("\nQuaternion is written to a binary file:\n");
    double y[4];
    y[0] = x.Re; y[1] = x.Im[0]; y[2] = x.Im[1]; y[3] = x.Im[2];
    outputBinFile(y, 4,file);
    printf("\n");
}
void outputTextFileQuater(Quaternion x, FILE *file)
{
    printf("\nQuaternion is written to a text file:\n");
    double y[4];
    y[0] = x.Re; y[1] = x.Im[0]; y[2] = x.Im[1]; y[3] = x.Im[2];
    outputTextFile(y, 4,file);
    printf("\n");
}
//Для стурктури Point3D
Point3D input_DecP3D()
{
    printf("\nEnter decimal point coordinates:\n");
    Point3D result;
    inputDec(result.Rad_vec.Coordinates, 3);
    printf("\n");
    return result;
}
Point3D input_ExpP3D()
{
    printf("\nEnter exponential point coordinates:\n");
    Point3D result;
    inputExp(result.Rad_vec.Coordinates, 3);
    printf("\n");
    return result;
}
Point3D inputTextFileP3D(FILE *file)
{
    printf("\nPoint coordinates from text file:\n");
    Point3D result;
    result.Rad_vec = inputTextFileV3D(file);
    printf("\n");
    return result;
}
Point3D inputBinFileP3D(FILE *file)
{

    printf("\nPoint coordinates from bin file:\n");
    Point3D result;
    inputBinFile(result.Rad_vec.Coordinates, 3, file);
    printf("\n");
    return result;
}
void output_DecP3D(Point3D x)
{
    printf("\nPoint coordinates decimal:\n");
    outputDec(x.Rad_vec.Coordinates, 3);
    printf("\n");
}
void output_ExpP3D(Point3D x)
{
    printf("\nPoint coordinates exponential:\n");
    outputExp(x.Rad_vec.Coordinates, 3);
    printf("\n");
}
void outputBinFileP3D(Point3D x, FILE *file)
{
    printf("\nPoint coordinates are written to a binary file:\n");
    outputBinFile(x.Rad_vec.Coordinates, 3, file);
    printf("\n");
}
void outputTextFileP3D(Point3D x, FILE *file)
{
    printf("\nPoint coordinates are written to a text file:\n");
    outputTextFileV3D(x.Rad_vec, file);
    printf("\n");
}
// Для структури Angle3D

Angle3D input_DecAngle3D()
{
    Angle3D result;
    printf("\nEnter Angle3D angle and 3 axis coordinates (decimal):\n");
    inputDec(&result.angle, 1);
    result.axis = input_DecV3D();
    printf("\n");
    return result;
}
Angle3D input_ExpAngle3D()
{
    Angle3D result;
    printf("\nEnter Angle3D angle and 3 axis coordidnates (exponential):\n");
    inputExp(&result.angle, 1);
    result.axis = input_ExpV3D();
    printf("\n");
    return result;
}
Angle3D inputTextFileAngle3D(FILE *file)
{
    printf("\nAngle3D from text file:\n");
    Angle3D result;
    inputTextFile(&result.angle, 1, file);
    result.axis = inputTextFileV3D(file);
    printf("\n");
    return result;

}
Angle3D inputBinFileAngle3D(FILE *file)
{
    printf("\nAngle3D from bin file:\n");
    Angle3D result;
    inputTextFile(&result.angle, 1, file);
    result.axis = inputTextFileV3D(file);
    printf("\n");
    return result;
}
void output_DecAngle3D(Angle3D x)
{
    printf("\nAngle3D (decimal):\n");
    outputDec(&(x.angle), 1);
    outputDec(x.axis.Coordinates, 3);
    printf("\n");
}

void output_ExpAngle3D(Angle3D x)
{
    printf("\nAngle3D (exponential):\n");
    outputExp(&(x.angle), 1);
    outputExp(x.axis.Coordinates, 3);
    printf("\n");
}
void outputBinFileAngle3D(Angle3D x, FILE *file)
{
    printf("\nAngle3D is written to a binary file:\n");
    outputBinFile(&(x.angle), 1, file);
    outputBinFile(x.axis.Coordinates, 3, file);
    printf("\n");
}
void outputTextFileAngle3D(Angle3D x, FILE *file)
{
    printf("\nAngle3D is written to a text file:\n");
    fprintf(file," %f",x.angle);
    printf("%10.4f",x.angle);
    outputTextFileV3D(x.axis,file);
    printf("\n");
}
// Для структури Figure3D
/*
typedef struct
{   int num_points;
    int num_edges;
    Point3D *points;
    Point3D *edges[2];
} Figure3D;*/
Figure3D input_DecFigure3D()
{
    Figure3D result;
    printf("\nEnter number of points and edges:\n");
    scanf("%d %d", &result.num_points, &result.num_edges);
    result.points = calloc(result.num_points, sizeof(*result.points));
    for (int i=0;i<2;i++)
    {
        result.edges[i]=calloc(result.num_edges, sizeof(*result.edges[i]));
    }
        printf("\ninput points(decimal):");
    for (int i = 0; i < result.num_points; i++)
    {
        result.points[i] = input_DecP3D();
    }

        printf("\ninput edge(pair of the points) (decimal), using previously entered points:");
    for (int i = 0; i < result.num_edges; i++)
    {
        for (int j = 0; j < 2;j++)
            result.edges[j][i] = input_DecP3D();
        printf("\n");
    }
    return result;
}

Figure3D input_ExpFigure3D()
{
    Figure3D result;
    printf("\n");
    printf("Enter number of points and edges:\n");
    scanf("%d %d", &result.num_points, &result.num_edges);
    result.points = calloc(result.num_points, sizeof(*result.points));
    for (int i=0;i<2;i++)
    {
        result.edges[i]=calloc(result.num_edges, sizeof(*result.edges[i]));
    }
        printf("\ninput points(exponential):");
    for (int i = 0; i < result.num_points; i++)
    {
        result.points[i] = input_ExpP3D();
    }
        printf("\ninput edge(pair of the points)(exponential), using previously entered points:");
    for (int i = 0; i < result.num_edges; i++)
    {
        for (int j = 0; j < 2;j++)
            result.edges[j][i] = input_ExpP3D();
        printf("\n");
    }
    return result;
}
Figure3D inputTextFileFig3D(FILE *file)
{
    Figure3D result;
    printf("\nEnter number of points and edges:\n");
    fscanf(file,"%d\n%d",&result.num_points,&result.num_edges);

    printf("%d %d",result.num_points,result.num_edges);
    printf("\nGetting points and edges from text file\n");
    result.points = calloc(result.num_points, sizeof(*result.points));
    for (int i=0;i<2;i++)
    {
        result.edges[i]=calloc(result.num_edges, sizeof(*result.edges[i]));
    }
        fgetc(file);//забираємо знак кінця строки, щоб він не заважав
    for (int i = 0; i < result.num_points; i++)
    {
        result.points[i] = inputTextFileP3D(file);
        fgetc(file);
    }
    printf("\nGetting edges:\n");
    for (int i = 0; i < result.num_edges; i++)
    {
        for (int j = 0; j < 2;j++)
        {
            result.edges[j][i] = inputTextFileP3D(file);
        }
        fgetc(file);
         printf("\n");
    }
    return result;
}
Figure3D inputBinFileFig3D(FILE *file)
{

    Figure3D result;
    printf("\nEnter number of points and edges:\n");
    fscanf(file,"%d\n%d",&result.num_points,&result.num_edges);

    printf("%d %d",result.num_points,result.num_edges);
    printf("\nGetting points and edges from text file\n");
    result.points = calloc(result.num_points, sizeof(*result.points));
    for (int i=0;i<2;i++)
    {
        result.edges[i]=calloc(result.num_edges, sizeof(*result.edges[i]));
    }
        fgetc(file);//забираємо знак кіінця строки, щоб він не заважав
    for (int i = 0; i < result.num_points; i++)
    {
        result.points[i] = inputBinFileP3D(file);
        fgetc(file);
    }
    printf("\nGetting edges:\n");
    for (int i = 0; i < result.num_edges; i++)
    {
        for (int j = 0; j < 2;j++)
        {
            result.edges[j][i] = inputBinFileP3D(file);
        }
        fgetc(file);
         printf("\n");
    }
    return result;
}
void output_DecFig3D(Figure3D x)
{
    printf("\nGetting points(decimal):\n");
    for(int i = 0; i<x.num_points; i++)
    {
        output_DecP3D(x.points[i]);
        printf("\n");
    }
    printf("\nGetting edges(decimal):\n");
    for(int i = 0; i<x.num_edges; i++)
    {
        for(int j = 0;j<2;j++)
            output_DecP3D(x.edges[j][i]);
        printf("\n");
    }
}
void output_ExpFig3D(Figure3D x)
{
    printf("\nGetting points(exponential):\n");
    for(int i = 0; i<x.num_points;i++)
    {
        output_ExpP3D(x.points[i]);
        printf("\n");
    }
    printf("\nGetting edges(exponential):\n");
    for(int i = 0; i<x.num_edges; i++)
    {
        for(int j = 0;j<2;j++)
            output_ExpP3D(x.edges[j][i]);
        printf("\n");
    }
}
void outputTextFileFig3D(Figure3D x, FILE *file)
{

    printf("\nWritting to a text file points and edges\n");
    printf("Writting to a text file number of points and edges\n");
    fprintf(file," %d\n%d", x.num_points, x.num_edges);
    printf(" %d\n%d", x.num_points, x.num_edges);
    for(int i = 0; i<x.num_points;i++)
    {
        outputTextFileP3D(x.points[i],file);
    }
    for(int i = 0; i<x.num_edges; i++)
    {
        for(int j = 0;j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fprintf(file," %f",x.edges[j][i].Rad_vec.Coordinates[k]);

            }
        }
        fprintf(file, "\n");
    }
    printf("\n");

}
void outputBinFileFig3D(Figure3D x, FILE *file)
{
    printf("\nWritting to a text file points and edges\n");
    printf("Writting to a text file number of points and edges\n");
    fprintf(file," %d\n%d", x.num_points, x.num_edges);
    printf(" %d\n%d", x.num_points, x.num_edges);
    for(int i = 0; i<x.num_points;i++)
    {
        outputBinFileP3D(x.points[i],file);
    }
    for(int i = 0; i<x.num_edges; i++)
    {
        for(int j = 0;j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fprintf(file," %f",x.edges[j][i].Rad_vec.Coordinates[k]);

            }
        }
        fprintf(file, "\n");
    }
    printf("\n");

/*
    printf("\nWritting to a text file points and edges\n");
    for(int i = 0; i<x.num_points;i++)
    {
        outputBinFileP3D(x.points[i],file_points);
        fprintf(file_edges,"\n");
    }
    for(int i = 0; i<x.num_edges; i++)
    {
        for(int j = 0;j<2;j++)
            outputBinFileP3D(x.edges[j][i], file_edges);
        fprintf(file_edges, "\n");
    }

    printf("\n");
*/}
