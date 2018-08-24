#include <iostream>
#include <set>

using namespace std;

int dict[4] = {2, 3, 5, 7};
int wei = 0;
int warr[9999] = {2};
int curr = 0;

long long genChou() {

    long long rslt = 1;
    curr %= 4;
    for(int i = 0; i <= wei; ++i){
        rslt *= dict[curr++];
    }
    cout << rslt << endl;
    return rslt;

}

int main() {

    int n;
    cin >> n;

    set<long long> vs;

    for(int i=0; i<n; ++i) {
        vs.insert(genChou());
        vs.insert(genChou());
        vs.insert(genChou());
        vs.insert(genChou());
        wei ++;
    }

}