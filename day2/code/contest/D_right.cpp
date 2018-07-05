#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
void dfs(int sum,int p,int x)
{
	if(sum>n||p>n)
	return;
	if(sum==n)
	{
		ans=max(ans,x);
		return;
	}
		dfs(sum+p,p+1,x*p);
		dfs(sum,p+1,x);
}
int main(int argc, char *argv[])
{
	sscanf(argv[1], "%d", &n);
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	 dfs(0,1,1);
	 cout<<ans;
	 return 0;
} 