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

int foo(int n) {
    cout << "1" << endl;
    if (n <= 0)
        return 1;
    return foo((n * 2) / 3) + foo(n - 2);
}

void recursion(int i) {
    if (i == 0)return;
    int a;
    cin >> a;
    recursion(a);
    cout << i << " ";
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate(int a[], unsigned size, int shift) {
    for (int n = 0; n < shift; n++) {
        for (int i = 0; i < size - 1; i++) {
            swap(&a[i], &a[(i + 1) % size]);
        }
    }
}

//Очень часто для работы со строками нам нужно сначала вычислить длину строки. Для C-style строк длина нигде явно не хранится, но её можно вычислить. Напишите функцию, которая вычисляет длину C-style строки. Учтите, что завершающий нулевой символ считать не нужно.
//Требования к реализации: при выполнении этого задания вы можете создавать любые вспомогательные функции. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.

unsigned strlen(const char *str) {
    int len = 0;
    while (*(str + len) != 0) {
        len++;
    }
    return len;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const char str[] = "dsfsdfsdf";

    cout << str << " lan: " << strlen(str);

    return 0;
}
