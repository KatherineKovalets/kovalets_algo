#ifndef QUATERNION_KOVALETZ_H_INCLUDED
#define QUATERNION_KOVALETZ_H_INCLUDED

// Усі стандартні функції, що стосуються виводу-вводу прописані в кінці цього файлу
// Усі дії відбуваються в Декартовій правій системі координат
typedef struct {
    double Coordinates[3];
}vector3D;//3Д-вектор, допоміжна структура
vector3D summ(vector3D a, vector3D b);//сума векторів
vector3D subtraction  (vector3D a, vector3D b);//різниця векторів
vector3D Scalar_mult(vector3D a, double b);//множення вектора на скаляр
double Dot_product(vector3D a,vector3D b);//Скалярний добуток
vector3D Cross_product(vector3D a, vector3D b);//Векторний добуток
double norm (vector3D a);//модуль
//Структура Кватерніон
typedef struct
{
    double Im[3];
    double Re;
}Quaternion;
// Допоміжні операції: знаходження спраженного, оберненого та модулю кватерніона,ділення та множення кватерніона на скаляр
Quaternion Conjudation (Quaternion a);//спряжений
Quaternion Scalar_div(Quaternion a,double b);//ділення кватерніона на скаляр
Quaternion scalar_mult(Quaternion a, double b);//множення кватерніона на скаляр
double Norm (Quaternion a);//модуль
Quaternion  Reciprocal (Quaternion a);//обернений
//Стандартні операції
Quaternion Sum (Quaternion a, Quaternion b);//сума
Quaternion Subtraction (Quaternion a,Quaternion b);//різниця
Quaternion Multiplication(Quaternion a, Quaternion b);//множення кватерніона на кватерніон
Quaternion Division(Quaternion a, Quaternion b);//ділення кватерніона на кватерніон
Quaternion Multiplication_Vector(Quaternion a, vector3D b);//множення кватерніона на вектор
 typedef struct //3Д-точка
{
    vector3D Rad_vec;//радіус-вектор точки, що має початок в початку координат і кінець в точці;
    //який задає Декартові координати точки
}Point3D ;
Point3D spherical(Point3D x);//перехід від декартових координат до сферичних
Point3D cylindrical (Point3D x);//перехід від декартових координат до циліндричних
Point3D Spherical(Point3D x);//від сферичних до Декартових
Point3D Cylindrical(Point3D x);//від циліндричних до Декартових
Point3D mult_scalar(Point3D x, double a);// множення на скаляр
Point3D add (Point3D x, Point3D movement);
//Структура - кут повороту. Задається віссю обертання та, власне, кутом повороту навколо неї
typedef struct
{
    double angle;
    vector3D axis;
}Angle3D;
//Сферичний кут - кут між двома площинами, отже, представляється як кут між двома векторами. Вісь обертання задається
//як вектор, перпендикулярний до цих двох верторів, і такий, що утворює с ними праву трійку. Тобто як векторний добуток
//у правій Декартовій системі координат.
//Кут повороту визначається як кут між такими векторами
Angle3D get_angle(vector3D a, vector3D b);
// Структура - 3Д фігура
typedef struct
{   int num_points;
    int num_edges;
    Point3D *points;
    Point3D *edges[2];
} Figure3D;
Figure3D turn3D(Figure3D f, Angle3D a, Point3D p);// поворот фігури
Figure3D projection3D(Figure3D f, Point3D p);//проекція фігури
//Функції вводу-виводу
int inputDec(double *x,int len);
int inputExp(double *x,int len);
void inputBinFile(double *x, int len,FILE *file);
void inputTextFile(double *x, int len,FILE *file);//ввід з текстового файлу
int outputDec(double *x,int len);
int outputExp(double *x,int len);
void outputBinFile(double *x, int len, FILE *file);
void outputTextFile(double *x, int len, FILE *file);
// для структури вектор
vector3D input_DecV3D();
vector3D input_ExpV3D();
vector3D inputTextFileV3D(FILE *file);
vector3D inputBinFileV3D(FILE *file);
void output_DecV3D(vector3D x);
void outputBinFileV3D(vector3D x, FILE *file);
//для структури Quaternion
Quaternion input_DecQuater();
Quaternion input_ExpQuater();
Quaternion inputTextFileQuater(FILE *file);
Quaternion inputBinFileQuater(FILE *file);
void output_DecQuater(Quaternion x);
void output_ExpQuater(Quaternion x);
void outputBinFileQuater(Quaternion x, FILE *file);
void outputTextFileQuater(Quaternion x, FILE *file);
//Для стурктури Point3D
Point3D input_DecP3D();
Point3D input_ExpP3D();
Point3D inputTextFileP3D(FILE *file);
Point3D inputBinFileP3D(FILE *file);
void output_DecP3D(Point3D x);
void output_ExpP3D(Point3D x);
void outputBinFileP3D(Point3D x, FILE *file);
void outputTextFileP3D(Point3D x, FILE *file);
// Для структури Angle3D
Angle3D input_DecAngle3D();
Angle3D input_ExpAngle3D();
Angle3D inputTextFileAngle3D(FILE *file);
Angle3D inputBinFileAngle3D(FILE *file);
void output_DecAngle3D(Angle3D x);
void output_ExpAngle3D(Angle3D x);
void outputBinFileAngle3D(Angle3D x, FILE *file);
void outputTextFileAngle3D(Angle3D x, FILE *file);
// Для структури Figure3D
Figure3D input_DecFigure3D();
Figure3D input_ExpFigure3D();
Figure3D inputTextFileFig3D(FILE *file_points, FILE *file_edges);
Figure3D inputBinFileFig3D(FILE *file_points, FILE *file_edges);
void output_DecFig3D(Figure3D x);
void output_ExpFig3D(Figure3D x);
void outputTextFileFig3D(Figure3D x, FILE *file_points, FILE *file_edges);
void outputBinFileFig3D(Figure3D x, FILE *file_points, FILE *file_edges);


#endif // QUATERNION_KOVALETZ_H_INCLUDED
