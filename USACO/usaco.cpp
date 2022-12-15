#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define double         long double

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("cownomics.in",  "r",  stdin);
    freopen("cownomics.out", "w", stdout);
    #endif
	int t = 1;
	// cin>>t;
	while(t--)
	{
		
		int n, m;
	cin >> n >> m;
	vector<string> spotty(n);
	vector<string> plain(n);

	for (int i = 0; i < n; ++i) cin >> spotty[i];
	for (int i = 0; i < n; ++i) cin >> plain[i];


	set<string> forspotty;

	int res=0;
	string s(3, '0');
	bool good;

	for (int i = 0; i < m; ++i) {
		for (int j = i+1; j < m; ++j) {
			for (int k = j+1; k < m; ++k) {
				good = true;
				forspotty.clear();
				for (int cow = 0; cow < n; ++cow) {
					s[0] = spotty[cow][i]; s[1] = spotty[cow][j]; s[2] = spotty[cow][k];
					forspotty.insert(s);
				}

				for (int cow = 0; cow < n; ++cow) {
					s[0] = plain[cow][i]; s[1] = plain[cow][j]; s[2] = plain[cow][k];
					if (forspotty.count(s)) {
						good = false;
						break;
					}
				}

				if (good) ++res;
			}
		}
	}

	cout << res << '\n';
	}
	return 0;
}