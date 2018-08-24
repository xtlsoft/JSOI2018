#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int n;
vector<int> s;
int minn = INF;

void dfs(vector<int> f, int dep, int start) {

    f[start] = f[start] + f[start + 1];
    dep += f[start];
    f.erase(f.begin() + start + 1);

    if (dep > minn) return;

    if (f.size() == 1) minn = min(minn, dep);
    else for (int i = 0; i < (f.size() - 1); ++ i) {

        vector<int> f1 = f;

        dfs(f1, dep, i);

    }

}

int main() {

    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int tmp; cin >> tmp;
        s.push_back(tmp);
    }

    for (int i = 1; i < n; ++ i) {
        vector<int> f = s;
        dfs(f, 0, (i - 1));
    }

    cout << minn;

    return 0;

}