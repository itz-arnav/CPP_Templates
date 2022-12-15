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

class Rect {
public:
	int x1, y1, x2, y2;
	int area() {
		return (y2 - y1) * (x2 - x1); 
	}
};

//check if 2 rectangles intersect

bool intersect(Rect s1, Rect s2) {
	int bl_a_x = s1.x1, bl_a_y = s1.y1, tr_a_x = s1.x2, tr_a_y = s1.y2;
	int bl_b_x = s2.x1, bl_b_y = s2.y1, tr_b_x = s2.x2, tr_b_y = s2.y2;
	
	// no overlap
	if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x 
			|| bl_a_y >= tr_b_y || tr_a_y <= bl_b_y) {
		return false;
	} else {
		return true;
	}
}

void solve(Rect &a, Rect b){
	//left
	if(b.x1 <= a.x1 and b.x2 >= a.x1){
		if(b.y1 <= a.y1 and b.y2 >= a.y2){
			a.x1 = min(b.x2, a.x2);
		}
	}
	//top
	if(b.x1 <= a.x1 and b.x2 >= a.x2){
		if(b.y1 <= a.y2 and b.y2 >= a.y2){
			a.y2 = max(b.y1, a.y1);
		}
	}

	//right
	if(b.x1 <= a.x2 and b.x2 >= a.x2){
		if(b.y1 <= a.y1 and b.y2 >= a.y2){
			a.x2 = max(b.x1, a.x1);
		}
	}
	//bot
	if(b.x1 <= a.x1 and b.x2 >= a.x2){
		if(b.y1 <= a.y1 and b.y2 >= a.y1){
			a.y1 = min(b.y2, a.y2);
		}
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
		
		
	}

	return 0;
}