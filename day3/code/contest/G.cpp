#include <iostream>
#include <map>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int n;
map<int, int> a;

bool check(int n) {
    
    map<int, int> b;
    b = a;
    while(!b.empty()){
        map<int, int>::iterator tmp = b.begin();
        b.erase(tmp);
        if (b.count(n - (tmp->first)) != 0) {
            return false;
        }
    }

    return true;
    
}

int main() {
    int total = 0, maxn = 0;
    cin >> n;

    for(int i = 0; i<n; ++i){
        int tmp;
        cin>>tmp;
        total += tmp;
        a.insert(make_pair(tmp, tmp));
        maxn = max(maxn, tmp);
    }
    
    while(total % maxn || !check(maxn)){
        maxn ++;
    }

    cout << maxn << endl;

    return 0;
}