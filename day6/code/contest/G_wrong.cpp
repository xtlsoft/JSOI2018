#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
int n;
vector<int> s;
int minn = INF;

struct Node {

    vector<int> s;
    int start;
    int dep;

    Node(vector<int> _s, int _st, int _de): s(_s), start(_st), dep(_de) {};

};

queue<Node> q;

void bfs(vector<int> s, int dep, int start) {

    while(!q.empty()){

        Node curr = q.front();
        q.pop();

        start = curr.start;

        curr.s[start] = curr.s[start] + curr.s[start + 1];
        dep += curr.s[start];
        curr.s.erase(curr.s.begin() + start + 1);

        if (curr.s.size() == 1) {
            minn = min(minn, dep);
            return;
        }

        for (int i = 0; i < (curr.s.size() - 1); ++ i) {

            q.push(Node(curr.s, i, dep));

        }

    }

}

int main() {

    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int tmp; cin >> tmp;
        s.push_back(tmp);
    }

    for (int i = 1; i < n; ++ i) {
        while(!q.empty()) q.pop();
        vector<int> f = s;
        q.push(Node(f, (i - 1), 0));
        bfs(f, 0, (i - 1));
    }

    cout << minn;

    return 0;

}