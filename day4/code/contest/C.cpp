#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool status[10000001];

int main() {

    memset(status, 0, sizeof(status));

    int d, i1;
    cin >> d >> i1;

    int nodes = pow(2, d); // Calculate the nodes
    int flag = 0; 
    
    for (int i=1; i <= i1; i ++) { // Main loop
        
        int curr = 0;
        
        while ( curr <= nodes - 1 ) {

            if (status[curr] == 0) {
                status[curr] = 1;
                curr = 2 * curr;    
                flag = 1;
            } else {
                status[curr]=0;
                curr = 2 * curr + 1;
                flag = 2;
            }

        }

        if(i == i1) {
            if (flag = 1) cout << (curr / 2);
            else cout << (curr / 2 - 1);
        }
    }
    return 0;
}