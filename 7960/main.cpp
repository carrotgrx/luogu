#include <iostream>
#include <cmath>
using namespace std;

bool containsSeven(int number) {
    while (number != 0) {
        int digit = number % 10;
        if (digit == 7) { 
            return true;
        }
        number /= 10;
    }
    return false;
}

bool isSeven(int n) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 10; j++) {
            if (n % (7 * int(pow(10, i)) + j) == 0) 
                return true;
        }
    }
}

int main() {
    int T;
    cin >> T;
    int x[T];

    for (int i = 0; i < T; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < T; i++) {
        if (isSeven(x[i])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
