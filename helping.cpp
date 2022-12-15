#include <bits/stdc++.h>
using namespace std;
 
int solve(string &s, vector<string> &nums, int si, vector<int> &dp)
{
    if (si == s.size())
    {
        return 0;
    }
    if (dp[si] != 10000000)
    {
        return dp[si];
    }
 
    int ans = 10000000;
 
    for (int i = 0; i < nums.size(); i++)
    {
        if (si + nums[i].size() < s.size() + 1)
        {
            if (s.substr(si, nums[i].size()).compare(nums[i]) == 0)
            {
                for (int j = 1; j <= nums[i].size(); j++)
                {
                    ans = min(ans, 1 + solve(s, nums, si + j, dp));
                }
            }
        }
    }
    return dp[si] = ans;
}
 
void printer(vector<int> &dp, int a, string &s, vector<string> &nums)
{
    if (a == 10000000)
    {
        cout << -1 << endl;
        return;
    }
    cout << a << endl;
    vector<pair<int, int>> ans;
    int si = 0;
    while (si < s.size())
    {
        cout << si << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            bool flag = false;
            if (si + nums[i].size() < s.size() + 1)
            {
                if (s.substr(si, nums[i].size()).compare(nums[i]) == 0)
                {
                    for (int j = 1; j <= nums[i].size(); j++)
                    {
                        if (dp[si] == 1 + dp[si + j])
                        {
                            ans.push_back({i, si});
                            si = si + j;
                            flag = true;
                            break;
                        }
                    }
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
 
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

long long int solution(vector<int>& arr, int n, int k){
    vector<int>temp;
    temp = arr;
    long long int counter = 0;
    sort(arr.begin(), arr.end());
    for (long long int i = 0; i < k; i++)
    {
        if(arr[i] == temp[i]){
            
        }
        else{
            counter++;
        }
    }
    return counter;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    long long int t;
    cin>>t;
    while(t--){
        long long int n, k;
        cin>>n>>k;
        vector<int>arr;
        for (int i = 0; i < n; i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        int ans = solution(arr, n, k);
        cout<<ans<<endl;
    }
    return 0;
}