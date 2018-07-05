#include <iostream>
#include <algorithm>
#include <vector>

// 超时解

using namespace std;

struct mps {
    long long length;
    long long id;
};

int cmp(mps a, mps b) {
    return a.length < b.length;
}

int main() {

    long long end, n, can, last = 0, i;
    vector<mps> mp;
    cin >> end >> n >> can;

    for (i = 0; i < n; ++ i) {
        long long tmp;
        cin >> tmp;
        mps m;
        m.length = tmp - last;
        m.id = i;
        mp.push_back(m);
        last = tmp;
    }
    mps m;
    m.length = end - last;
    m.id = i + 1;
    mp.push_back(m);

    sort(mp.begin(), mp.end(), cmp);

    for (i=0; i<can; ++i) {
        int findId = mp[i].id + 1;
        int rslt;
        for(int j = 0; j < mp.size(); ++j) {
            if (mp[j].id == findId) {
                rslt = j;
                break;
            }
        }
        mp.erase(mp.begin() + rslt);
        sort(mp.begin(), mp.end(), cmp);
    }

    cout << mp[can].length;
    
    return 0;

}