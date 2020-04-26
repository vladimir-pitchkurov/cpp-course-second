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

//Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк. Функция конкатенации принимает на вход две C-style строки и дописывает вторую в конец первой так, чтобы первая строка представляла из себя одну C-style строку равную конкатенации двух исходных.
//Не забудьте, что в результирующей строке должен быть только один нулевой символ — тот, что является маркером конца строки.
//Гарантируется, что в первой строке достаточно памяти (т.е. она располагается в массиве достаточной длины), чтобы разместить конкатенацию обеих строк, но не больше.
//Требования к реализации: при выполнении задания вы можете определять любые вспомогательные функции, если они вам нужны. Выводить или вводить что-либо не нужно. Функцию main определять не нужно.

unsigned strlen(const char *str) {
    int len = 0;
    while (*(str + len) != 0) {
        len++;
    }
    return len;
}

void str_cat(char *to, const char *from) {
    int to_len = strlen(to);
    int from_len = strlen(from);
    int i = 0;
    for (; i < from_len; i++) {
        to[i + to_len] = from[i];
    }
    to[i + to_len] = 0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char str[] = "dsfsdfsdf";
    const char str2[] = "  dsfsdfsdf";


    cout << str << " str2:  " << str2 << endl;
    str_cat(str, str2);

    cout << str << " len  " << strlen(str) << endl;
    return 0;
}
