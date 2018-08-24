#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool compareSet(multiset<int> a, multiset<int> b) {
    set<int>::iterator ita, itb;
    ita = a.begin();
    itb = b.begin();
    while ((*ita) == (*itb)) {
        ++ita; ++itb;
    }
    return (*ita) < (*itb);
}

int main() {

    int n;
    cin >> n;

    multiset<int> arr[n + 1];

    for (int i = 0; i < n; ++i) {
        int sum;
        cin >> sum;
        for(int j =0; j < sum; ++j){
            int tmp;
            cin >> tmp;
            arr[i].insert(tmp);
        }
    }

    sort(arr, arr + n, compareSet);

    for (int i = 0; i < n; ++i) {

        multiset<int>::iterator it;

        for (it = arr[i].begin(); it != arr[i].end(); ++ it) {
            cout << (*it) << " ";
        }

        cout << endl;

    }

    return 0;

}