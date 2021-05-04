#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
using namespace std;
class CustomException
{
private:
    string message;
    double value;
    int code;
public:
    CustomException(string message, double value, int code)
    {
        this->message = message; // вносим измененные данные в переменные //
        this->value = value;
        this->code = code;
    }
    void display()
    {
        cout << "Код ошибки: " << code << " " << "Название ошибки: " << message << " " << "Причина: " << value << endl; // вывод причины ошибки
    };
};
double pervaya(const double& x) // первый пример
{
    double a = (3 * (sqrt(x)) - 2 / sqrt(x));
    if (3 * (a == 0)) throw CustomException("Деление на ноль ", a, 1); // кидаем ошибку и причину ошибки
    return sqrt(pow(3 * x + 2, 2) - 24 * x) / a;
}
double vtoraya(const double& x) // второй пример
{
    double b = -sqrt(x);
    if (b == 0) throw CustomException("Деление на ноль ", b, 5); // кидаем ошибку и причину ошибки
    return b;
}
int main()
{
    setlocale(LC_ALL, "Ru");
    double x;
    try // блок try
    {
        cout << "Введите x: ";
        cin >> x;
        cout << endl;
        pervaya(x);
        vtoraya(x);
        cout << pervaya(x) << endl;
        cout << pervaya(x) << endl;
    } // блок try
    catch (CustomException& p)
    {
        ((CustomException*)&p)->display();
    }
    _getch();
}