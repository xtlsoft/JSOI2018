#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

struct Node {
    int data;
    multiset<int> next;
};

vector<Node> nodes;

queue<int> q;

int vis[99999];

void bfs(int x){
   q.push(x);
   vis[x] = 1;
   while(!q.empty()){
        x = q.front();
        cout << (x + 1) << " ";
        q.pop();
        set<int>::iterator it;
        for (it = nodes[x].next.begin(); it != nodes[x].next.end(); ++ it) {
	        int newx = nodes[*it].data - 1;
            if (!vis[newx]) {
                q.push(newx);
                vis[newx] = 1;
            }
        }
    }
}

bool check(int a, int b) {
    return nodes[a].next.count(b);
}

void dfs(int x, int maxn){
	vis[x] = 1;
    cout << (x + 1) << " ";
	for (int i = 0 ; i < maxn; i ++) if(!vis[i] && check(x, i)) dfs(i, maxn); 
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        Node nd;
        nd.data = i + 1;
        for (int j = 0; j < n; ++ j) {
            int tmp;
            cin >> tmp;
            
            if (tmp == 1) {
                nd.next.insert(j);
            }
        }
        nodes.push_back(nd);
    }

    for (int i=0; i < n; i ++)  if(!vis[i]) dfs(i, n);

    memset(vis, false, sizeof(vis));

    cout << endl;

    for (int i=0; i < n; i ++)  if(!vis[i]) bfs(i);

    return 0;

}

