#include <bits/stdc++.h>
using namespace std;
#define int            long long int
const int mod = 1e9+7;
#define endl "\n"

int bruteforce(string &num)
{
	int n = num.size();
	vector<int>digits(10,0);
	for(int i = 0; i < n; i++)
	{
		digits[num[i]-'0']++;
	}
	int ans = (digits[3] == digits[6] && digits[6] == digits[9] && digits[3] >= 1) ? 1 : 0;
	return ans;
}


int dp[57][57][57][57][2];
int func(string &num, int curr, int n, int c3, int c6, int c9, bool tight)
{
	if((curr == n) && (c3 == c6) && (c6 == c9) && (c9 >= 1)) 
		return 1;
	if(curr == n) 
		return 0;
	if(c3 > n/3 or c6 > n/3 or c9 > n/3){
		return 0;
	}
	
	
	if(dp[curr][c3][c6][c9][tight] != -1)
	    return dp[curr][c3][c6][c9][tight];

	int ub = tight ? num[curr]-'0' : 9;
	int ans = 0;

	for(int dig = 0; dig <= ub; dig++)
	{
		int n3 = c3 + (dig == 3);
		int n6 = c6 + (dig == 6);
		int n9 = c9 + (dig == 9);
		ans = (ans + func(num,curr+1,n, n3, n6, n9, tight & (dig == ub)))%mod;
	}

	return dp[curr][c3][c6][c9][tight] = ans;
}

void MainCode()
{
	string a,b;
	cin >> a >> b;
	int as = a.size()+5;
	int bs = b.size()+5;
	for(int i = 0; i<=bs; ++i){
		for(int j = 0; j<=bs; ++j){
			for(int k = 0; k<=bs; ++k){
				for(int l = 0; l<=bs; ++l){
					for(int m = 0; m<2; ++m)
					dp[i][j][k][l][m] = -1;
				}
			}
		}
	}
	int ans = func(b,0,b.size(),0,0,0,1);
	for(int i = 0; i<=as; ++i){
		for(int j = 0; j<=as; ++j){
			for(int k = 0; k<=as; ++k){
				for(int l = 0; l<=as; ++l){
					for(int m = 0; m<2; ++m)
					dp[i][j][k][l][m] = -1;
				}
			}
		}
	}
	ans -= func(a,0,a.size(),0,0,0,1);
	ans = ((ans + mod)%mod + bruteforce(a))%mod;
	cout << ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
    #endif

	int t = 1;
	cin>>t;
	cin>>ws;
	while(t--)
	{
		MainCode();
	}

	return 0;
}