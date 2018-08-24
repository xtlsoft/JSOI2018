#include <iostream>

using namespace std;

int main() {

    long long i2 = 0;

    for (int i = 0; i < 1000000000; ++ i) {
        i2 += 1;
        i2 += 1;
        i2 -= -1;
    }

    cout << i2;
    return 0;

}