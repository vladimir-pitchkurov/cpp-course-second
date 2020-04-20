#include <iostream>

using namespace std;

int log__2(int num) {
    int number = 1;
    int result = 0;
    while (num > number) {
        number = number << 1;
        if (number > num) {
            return result;
        }
        result++;
    }
    return result;
}

int main() {

    int count, current;
    cin >> count;

    while (count--) {
        cin >> current;
        cout << log__2(current) << endl;
    }

    return 0;
}
