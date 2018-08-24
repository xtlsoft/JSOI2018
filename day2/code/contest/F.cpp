#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct delta {
    int id;
    int value;
};

int cmp ( delta a, delta b ) {
    return a.value < b.value;
}

int main() {

    int n, c;
    cin >> n >> c;

    vector<int> slots;
    vector<delta> deltas;

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        slots.push_back(v);
    }

    sort(slots.begin(), slots.end());

    for (int i = 0; i < (n - 1); ++ i) {
        delta d;
        d.value = slots[i + 1] - slots[i];
        d.id = i;
        deltas.push_back(d);
    }

    sort(deltas.begin(), deltas.end(), cmp);

    for (int i = 0; i < (n - c); ++ i) {
        slots.erase(slots.begin() + deltas[i].id);
    }

    deltas.clear();

    for (int i = 0; i < (n - 1); ++ i) {
        delta d;
        d.value = slots[i + 1] - slots[i];
        d.id = i;
        deltas.push_back(d);
    }

    sort(deltas.begin(), deltas.end(), cmp);

    cout << (*deltas.begin()).value ;

    return 0;

}