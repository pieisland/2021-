#include <iostream>

using namespace std;

int n;
int nums[11];
int op[4];
int maxval=-1000000000;
int minval=1000000000;

void dfs(int depth, int ans, int p, int m, int mu, int d)
{
	//연산자 다 썼다면
	if(depth == n)//
	{
		if(ans<minval) minval=ans;
		if(ans>maxval) maxval=ans;
		return;
	}

	if(p>0)
		dfs(depth+1, ans+nums[depth], p-1, m, mu, d);
	if(m>0)
		dfs(depth+1, ans-nums[depth], p, m-1, mu, d);
	if(mu>0)
		dfs(depth+1, ans*nums[depth], p, m, mu-1, d);
	if(d>0)
		dfs(depth+1, ans/nums[depth], p, m, mu, d-1);
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>nums[i];
	
	for(int i=0;i<4;i++)
		cin>>op[i];

	dfs(1, nums[0], op[0], op[1], op[2], op[3]);

	cout<<maxval<<endl<<minval<<endl;

	return 0;
}
