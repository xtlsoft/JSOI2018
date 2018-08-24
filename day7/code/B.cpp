#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void opt(int n) {

    cout << n;
    exit(0);

}

int main() {

    int fcnt = 0, bcnt = 0, tmp, ft[102] = {0}, bt[102] = {0};

    for (int i = 0; i < 5; ++ i) {
        cin >> tmp;
        ft[tmp] = 1;
    }

    for (int i = 0; i < 2; ++ i) {
        cin >> tmp;
        bt[tmp] = 1;
    }

    for (int i = 0; i < 5; ++ i) {
        cin >> tmp;
        if (ft[tmp]) ++ fcnt;
    }

    for (int i = 0; i < 2; ++ i) {
        cin >> tmp;
        if(bt[tmp]) ++ bcnt;
    }

    if (fcnt == 5 && bcnt == 2) opt(5000000);
    if (fcnt == 5 && bcnt == 1) opt(250000);
    if (fcnt == 5 && bcnt == 0) opt(3000);
    if (fcnt == 4 && bcnt == 2) opt(3000);
    if (fcnt == 4 && bcnt == 1) opt(200);
    if (fcnt == 3 && bcnt == 2) opt(200);
    if (fcnt == 4 && bcnt == 0) opt(10);
    if (fcnt == 3 && bcnt == 1) opt(10);
    if (fcnt == 2 && bcnt == 2) opt(10);
    if (fcnt == 3 && bcnt == 0) opt(5);
    if (fcnt == 1 && bcnt == 2) opt(5);
    if (fcnt == 2 && bcnt == 1) opt(5);
    if (fcnt == 0 && bcnt == 2) opt(5);
    
    cout << 0;

    return 0;

}