/*
Berozgaar hu, naukri chahye!
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define all(a) (a).begin(), (a).end()

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const int mod = 1000000007;
const int N = 1000005;


inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }

int power(ll x, ll i,ll p)
{
    int ans = 1;
    while(i > 0){
    if(i&1)ans = (ans*x)%p;
     i >>=1;
     x = (x*x)%p;
   }
    return ans;
}

int modular_inverse(int n, int p){
    return power(n, p-2, p);
}



int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int LCM(int a, int b){
    return (a/gcd(a,b))*b;
}



bool cmpv(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool cmpp(pair<int,int> &a, pair<int,int> &b){
    
    return a.second - a.first < b.second - b.first;
}

int dp[505][130000];
int solve(int i, int n, vector<int> &arr, int sum){
    if(sum == 0){
        return 1;
    }
    if(i >= n){
        return 0;
    }
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    else{
        int pick = 0, notpick = 0;
        if(sum >= arr[i]){
            pick = solve(i+1, n, arr, sum - arr[i]);
        }
        notpick = solve(i+1,n,arr, sum);

        return dp[i][sum] = (pick + notpick)%mod;
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t = 1;
    // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i<505; ++i){
            for(int j=  0; j<130000; ++j){
                dp[i][j] = -1;
            }
        }
        vector<int> arr;
        int sum = n*(n+1)/2;
        for(int i = 1; i<=n; ++i){
            arr.emplace_back(i);
        }
        if(sum&1){
            cout<<0<<endl;
            break;
        }
        else{
            int ans = solve(0, n, arr, sum/2);
            ans = (ans * (modular_inverse(2, mod))%mod)%mod;
            cout<<ans<<endl;
        }
        
    }

    return 0;
}

