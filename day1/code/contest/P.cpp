#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int> > pq;

    int n, total = 0; 
    cin >> n;
    for(int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        total += tmp;
        pq.push(tmp);
    }
    // cout << total << endl;
    while ( pq.size() > 1 ) {
        total += pq.top();
        pq.pop();
    }

    cout << total;

    return 0;

}