#include <vector>
#include <string>
#include <iostream>

using namespace std;

int l2(string s)
{
	int n=s.size();
	int dp[3][100002];
	for(int i=n-1;i>=0;i--)
	{
		dp[i%2][i]=1;
	    for(int j=i+1;j<n;j++)
	    {
	    	if(s[i%2]==s[j])
	    	  dp[i%2][j]=dp[i+1][j-1]+2;
	    	else
	    	  dp[i%2][j]=max(dp[(i+1)%2][j],dp[i%2][j-1]);
		}
	}
	return dp[0][n-1];
}
int main()
{
	int t, n, k;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int b;string a;
		cin>>n>>k;
		for (int i = 0; i < n; ++ i) {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		b=l2(a);
		cout<<b<<endl;
	}
}