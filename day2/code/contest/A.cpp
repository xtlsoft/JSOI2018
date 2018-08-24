#include <iostream>
#include <algorithm>

using namespace std;

struct farmer {
    int price;
    int count;
};

int cmp (farmer a, farmer b) {
    return a.price < b.price;
}

int main() {

    int n, m;
    cin >> n >> m;
    farmer fs[5002];

    for (int i = 0; i < m; ++ i) {
        cin >> fs[i].price >> fs[i].count;
    }

    sort(fs, fs + m, cmp);

    int curr = 0;
    int total = 0;

    while (n != 0) {

        if (n > fs[curr].count) {
            n -= fs[curr].count;
            total += fs[curr].price * fs[curr].count;
        }else{
            total += fs[curr].price * n;
            n = 0;
        }

        ++curr;

    }

    cout << total;

    return 0;

}