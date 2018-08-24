#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void doTask();

int main() {

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        doTask();
    }

    return 0;

}

struct treasure {
    float count;
    float valueTotal;
    float value;
};

int compareFunc(treasure a, treasure b) {
    return a.value < b.value;
}

void doTask() {

    int w, s, curr = 0;
    cin >> w >> s;

    treasure ts[10002];

    float total = 0;

    for (int i = 0; i < s; ++i) {
        cin >> ts[i].count >> ts[i].valueTotal;
        ts[i].value = ts[i].valueTotal / ts[i].count;
    }

    sort(ts, ts+s, compareFunc);

    curr = s - 1;

    while (curr >= 0) {
        if (w >= ts[curr].count) {
            w -= ts[curr].count;
            total += ts[curr].valueTotal;
        } else {
            total += ts[curr].value * w;
            break;
        }
        --curr;
    }

    cout << fixed << setprecision(2) << total << endl;

}