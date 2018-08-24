#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vs;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++ i) vs.push_back(i+1);
    while (! vs.empty() ) {
        int k2 = k;
        if (k > vs.size()) {
            k2 = k % vs.size();
        }
        cout << vs[k2 - 1] << " ";
        vs.erase(vs.begin() + k2 - 1);
        k2 += k - 1;
    }

    return 0;

}