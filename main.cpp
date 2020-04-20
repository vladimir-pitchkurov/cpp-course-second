#include <iostream>
#include <windows.h>

using namespace std;


//Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD). Для этого воспользуйтесь следующими свойствами:
//
//GCD(a, b) = GCD(b, a \bmod b)GCD(a,b)=GCD(b,amodb)
//GCD(0, a) = aGCD(0,a)=a
//        GCD(a, b) = GCD(b, a)GCD(a,b)=GCD(b,a)
//Требования к реализации: в данном задании запрещено пользоваться циклами. Вы можете заводить любые вспомогательные функции, если они вам нужны. Функцию main определять не нужно.

unsigned gcd(unsigned a, unsigned b) {
    if (a == 0) return b;
    if (b == 0)return a;

    if (a > b) {
        return gcd(b, a % b);
    }

    return gcd(b, a % b);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    unsigned int a, b;
    cout << "Введите 2 числа: " << endl;
    cin >> a >> b;
    cout << "Наибольльший общий делитель равен: " << gcd (b, a % b) << endl;

    return 0;
}
