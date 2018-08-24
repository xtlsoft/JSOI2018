#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10000 + 10;
string dic[MAXN];
string str;
map<string, int> mp;

// 单词标准化
string trans(string str) {
    int len = str.size();
    for(int i = 0; i < len; ++i) {
        str[i] = tolower(str[i]);
    }
    sort(str.begin(), str.end());
    return str;
}

int main() {

    int n;
    cin >> n;
    
    string str;
    cin >> str;

    int cnt = 0;

    while(str != "#")
    {
        dic[cnt++] = str;
        mp[trans(str)] ++;
        cin >> str;
    }

    sort(dic+1, dic+cnt+1);

    for(int i = 1; i <= cnt; ++i) {
        if(mp[trans(dic[i])] == 1) {
            cout << dic[i] << " ";
        }
    }

    return 0;
    

}