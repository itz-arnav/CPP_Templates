#include "bits/stdc++.h"
using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
#define FastandFurious ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long int // Can be reason for Run Time Error!
#define deb(x) cout << #x << "=" << x << "\n";
#define deb2(x,y) cout << #x << "=" << x << "," << #y << "=" << y << "\n";
const int N = 2e5+1;
const int mod = 1e9+7;
#define INF 1e18+9

int dp[51][51][51][51][2];
// dp[n][c3][c6][c9][1] -> total number of n digit 369 numbers where count
// of 3's = c3 , count of 6's = c6 and count of 9's = c9
// and mainatining our number is less than R

int func(string &num, int curr, int n, int c3, int c6, int c9, bool tight)
{
if(n == curr && (c3 == c6 && c6 == c9 && c9 >= 1)) return 1;
if(n == curr) return 0;

if(dp[n][c3][c6][c9][tight] != -1) return dp[n][c3][c6][c9][tight];

int ub = tight ? num[num.size()-n]-'0' : 9;
int ans = 0;

for(int dig = 0; dig <= ub; dig++)
{
ans += func(num,curr+1,n,c3 + (dig == 3),
c6 + (dig == 6), c9 + (dig == 9), tight & (dig == ub));
}

return dp[n][c3][c6][c9][tight] = ans;
}


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



void MainCode()
{
string a,b;
cin >> a >> b;
memset(dp,-1,sizeof(dp));
int ans = func(b,0,b.size(),0,0,0,1);
memset(dp,-1,sizeof(dp));
ans -= func(a,0,a.size(),0,0,0,1);
cout << ans+bruteforce(a) << "\n";
}

//------------------#Maincode ends!---------------//
signed main()
{
FastandFurious
int TestCaseS = 1;
cin >> TestCaseS;

// primeseive();
for(int TestCase = 1; TestCase <= TestCaseS ; TestCase++)
{
// cout << "Case #" << TestCase << ": "; // Google!
MainCode();
}
return 0;
}