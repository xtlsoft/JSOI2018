#include <iostream>

using namespace std;

int vis[9999];

int main() {
	
	int n, tot = 0; cin >> n;
	
	for (int i = 0; i < n; ++ i) {
		int t1, t2;
		cin >> t1 >> t2;
		bool ok = true;
		for (int i = t1; i <= t2; ++ i) {
			if ( vis[i] ){
				ok = false;
				break;
			}
			vis[i] = true;
		}
		if(ok){
			tot += t2 - t1 + 1;
		}
	}
	
	cout << tot;
	
	return 0;

}
