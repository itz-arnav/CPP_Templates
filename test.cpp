/*
Berozgaar hu, naukri chahye!
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const int mod = 1000000007;
const int N = 1e6;


void buildTree(vector<int> &arr, int s, int e, vector<int> &tree, int index){
    if(s == e){
        tree[index] = arr[s];
        return;
    }
    int mid = s + (e-s)/2;
    buildTree(arr, s, mid, tree, 2*index);
    buildTree(arr, mid+1, e, tree, 2*index + 1);
    tree[index] = (tree[2*index] ^ tree[2*index + 1]);
}

int query(int ss, int ee, int qs, int qe, vector<int>&tree, int index){
    if(ss > qe or qs > ee){
        return 0;
    }
    else if(qs <= ss and qe >= ee){
        return tree[index];
    }
    else{
        int mid = ss + (ee - ss)/2;
        int left = query(ss, mid, qs, qe, tree, 2*index);
        int right = query(mid+1, ee, qs, qe, tree, 2*index + 1);
        return (left + right);
    }
}

int pointUpdate(vi &tree, int s, int e, int point, int incr, int index){
    if(s > point or e < point){
        return tree[index];
    }
    if(s == e and s == point){
        tree[index] = incr;
        return tree[index];
    }
    int mid = s + (e-s)/2;
    int left = pointUpdate(tree, s, mid, point, incr, 2*index);
    int right = pointUpdate(tree, mid+1, e, point, incr, 2*index + 1);
    tree[index] = (tree[2*index] ^ tree[2*index + 1]);
}

int rangeUpdate(vi &tree, int s, int e, int l, int r, int incr, int index){
    if(s > r or e < l){
        return tree[index];
    }
    if(s == e){
        tree[index] += incr;
        return tree[index];
    }
    int mid = s + (e-s)/2;
    int left = rangeUpdate(tree, s,mid, l, r, incr, 2*index);
    int right = rangeUpdate(tree, mid+1, e, l,r,incr, 2*index +1);
    // tree[index] = min(tree[2*index], tree[2*index + 1]);
    tree[index] = min(left, right);
    return tree[index];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;

    // cin >> t;

    for(; t--; )
    {
        int n;
        cin>>n;
        int q=1;
        

        vector<int> arr(n+1);
        for(int i = 0; i<n; ++i){
            cin>>arr[i];
        }

        vector<int> tree(4*n + 5, 0);

        buildTree(arr,0, n-1, tree, 1);

        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<query(0, n-1, x, y, tree, 1)<<endl;
            
        }
        
    }

    return 0;
}