/*
Berozgaar hu, naukri chahye!
*/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


#define ll long long
#define int            long long 
#define vi             vector <int>
#define pii            pair <int, int>
#define endl           "\n"
#define double         long double

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const int N = 2000005;
int mod = 1000000007 ;




int32_t main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
	int t = 1;
	// cin>>t;
	while(t--)
	{
		ordered_set st;
		int n;
		cin>>n;
		for(int i = 0; i<n; ++i){
			int x;
			cin>>x;
			st.insert(x);
		}
		int key;
		cin>>key;
		cout<<st.order_of_key(key);

	}

	return 0;
}