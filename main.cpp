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

//Напишите функцию поиска первого вхождения шаблона в текст. В качестве первого параметра функция принимает текст (C-style строка), в которой нужно искать шаблон. В качестве второго параметра строку-шаблон (C-style строка), которую нужно найти. Функция возвращает позицию первого вхождения строки-шаблона, если он присутствует в строке (помните, что в C++ принято считать с 0), и -1, если шаблона в тексте нет.
//Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.
//Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам нужны. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.
int str_contains_str(const char *text, const char *pattern) {
    int index = 0;
    bool is_contains = false;
    if (*pattern == '\0') {
        return 0;
    } else if (*text == '\0') {
        return -1;
    }
    for (; *text != 0; ++text) {
        if (*text == *pattern) {
            for (int i = 0; pattern[i] != 0; i++) {
                if (text[i] == 0) {
                    is_contains = false;
                    break;
                } else if (text[i] == pattern[i]) {
                    is_contains = true;
                } else {
                    is_contains = false;
                    break;
                }
            }
            if (is_contains == true) return index;
        }
        index++;
    }
    return -1;
}

struct Expression {
    virtual double evaluate() const = 0;

    virtual ~Expression() {}
};

struct Number : Expression {
    Number(double value)
            : value(value) {}

    double evaluate() const {
        return value;
    }

private:
    const double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
            : left(left), op(op), right(right) {}

    double evaluate() const {
        double a = left->evaluate();
        double b = right->evaluate();
        switch (op) {
            case '+':
                return a + b;
                break;
            case '-':
                return a - b;
                break;
            case '*':
                return a * b;
                break;
            case '/':
                return a / b;
                break;
        }
    }

    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{
    int* vptr =  *(int**)left;
    int* vptr2 =  *(int**)right;

    return vptr == vptr2;
}

//struct Person{
//    Person(string const& name, int const& age):name_(name),age_(age){}
//    virtual string name() const { return name_;}
//    virtual int agee() const { return age_;}
//    virtual ~Person(){}
//private:
//    string name_;
//    int age_;
//};
//
//struct Teacher : Person {
//    Teacher(string const& nm, int const & age):Person(nm,age){
//        cout << agee();
//    }
//    int agee() const { return Person::agee()+10;}
//};
//
//struct Professor : Teacher {
//    Professor(string const& nm, int const & age):Teacher(nm,age){}
//    string name() const { return "Prof." + Person::name();}
//
//};


int main() {
    SetConsoleOutputCP(CP_UTF8);

//    Teacher p("Stroustup",23);

    Expression *ex1 = new Number(3.0);
    Expression *ex2 = new Number(2.0);

    Expression *sub_ab = new BinaryOperation(ex1, '-', ex2);

    bool is_eq = check_equals(ex1, sub_ab);

    if(is_eq){
        std::cout << "equal";
    }else{
        std::cout << "not equal";
    }

//    std::cout << sub_ab->evaluate() << std::endl;

//    delete sub_ab; // уничтожили a и b

//    struct test {
//        int ret_value;
//        const char *text;
//        const char *pattern;
//    };
//    test tests[] = {
//            {0,  "",       ""}, //0
//            {0,  "a",      ""}, //1
//            {0,  "a",      "a"}, //2
//            {-1, "a",      "b"}, //3
//            {0,  "aa",     ""}, //4
//            {0,  "aa",     "a"}, //5
//            {0,  "ab",     "a"}, //6
//            {1,  "ba",     "a"}, //7
//            {-1, "bb",     "a"}, //8
//            {0,  "aaa",    ""}, //9
//            {0,  "aaa",    "a"}, //10
//            {1,  "abc",    "b"}, //11
//            {2,  "abc",    "c"}, //12
//            {-1, "abc",    "d"}, //13
//            {-1, "a",      "aa"}, //14
//            {-1, "a",      "ba"}, //15
//            {-1, "a",      "ab"}, //16
//            {-1, "a",      "bb"}, //17
//            {-1, "a",      "aaa"}, //18
//            {-1, "aa",     "aaa"}, //19
//            {0,  "aaa",    "aaa"}, //20
//            {0,  "aaab",   "aaa"}, //21
//            {1,  "baaa",   "aaa"}, //22
//            {1,  "baaaa",  "aaa"}, //23
//            {1,  "baaab",  "aaa"}, //24
//            {-1, "abd",    "abc"}, //25
//            {2,  "ababc",  "abc"}, //26
//            {3,  "abdabc", "abc"}, //27
//            {-1, "",       "a"}, //28
//            {2,  "asasaf", "asaf"}, //29
//            {2,  "ababac", "abac"} //30
//    };
//    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
//        int ret = str_contains_str(tests[i].text, tests[i].pattern);
//        (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
//        cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
//    }

    return 0;
}
