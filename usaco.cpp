#include <bits/stdc++.h>

using namespace std;
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const int mod = 1000000007;
const int N = 1000005;



int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		int ans = d - c + b - a;
		int common = 0;
		if(a <= c and b >= c){
			common += min(b,d) - c;
		}
		if(c <= a and d >= a){
			common += min(b,d) - a;
		}
		ans -= common;
		cout<<ans<<endl;
	}


}