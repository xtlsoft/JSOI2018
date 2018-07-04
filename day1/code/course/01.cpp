#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

int main() {

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << v.size() << " " << v.empty() << endl;

    for (int i = 0; i < v.size(); ++ i) {
        cout << v[i] << " ";
    }

    vector<int>::iterator it;
    cout << endl;
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }

    return 0;

}