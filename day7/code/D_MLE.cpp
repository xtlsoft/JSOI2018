#include <bits/stdc++.h>
using namespace std;

int l2(string s)
{
		int n=s.size();
	vector<vector<int> > dp(n,vector<int>(n));
	for(int i=n-1;i>=0;i--)
	{
		dp[i][i]=1;
	    for(int j=i+1;j<n;j++)
	    {
	    	if(s[i]==s[j])
	    	  dp[i][j]=dp[i+1][j-1]+2;
	    	else
	    	  dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
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