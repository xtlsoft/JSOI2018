#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int getHw(vector<int> arr, int end, int k, int start) {

    int maxn = 0;

    for (int i = start; i < end; ++ i) {
        int cnt = 0;
        int last = end;
        for (int j = last - 1; j > i; -- j) {
            if (cnt == k) break;
            if (arr[j] == arr[i]) {
                cnt ++;
                maxn = max(maxn, getHw(arr, j, k, i) + 2);
            }
        }
        if (cnt == 0 && start != end) maxn ++;
    }

    return maxn;

}

int main() {

    // freopen("C:\\Users\\geaih\\Desktop\\in.txt", "r", stdin);

    int n, k;

    vector<int> arr;

    cin >> n >> k;

    for (int i = 0; i < n; ++ i) {
        
        int tmp;
        cin >> tmp;

        arr.push_back(tmp);

    }

    cout << getHw(arr, n, k, 0);

    return 0;

}