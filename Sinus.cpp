#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    ofstream Taylor("Taylor.txt"); //потоки для вывода в текстовые документы
    ofstream sinus("sin.txt");

    const double PI = 3.14159265359;
    const double eps = 0.001;

    for (int i = 0; i < 360; ++i) { //проходимся по значениям от 0 градусов до 360
        int n = 0;
        double x0 = i * PI / 180; //переводим градусы в радианы
        double x = x0; //промежуточный x для решения
        double _sin = 0.0; //итоговое значение

        while (fabs(x) > eps) { //пока не достигли указанной точности
            _sin += x; //прибавляем в накопитель
            n++; //считаем количество итераций
            x *= -x0 * x0 / (2 * n * (2 * n + 1)); //формула ряда Тейлора для синуса
        }

        Taylor << "sin(" << i << ") = " << _sin << endl;
        sinus << "sin(" << i << ") = " << sin(x0) << endl;
    }

    return 0;
}
