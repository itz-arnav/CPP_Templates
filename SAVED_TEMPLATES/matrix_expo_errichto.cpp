#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i = 0; i < (n); i++)
const int mod = 1e9 + 7;
int n = 4;
struct Matrix {
	vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
	Matrix operator *(const Matrix& other) {
		Matrix product;
		REP(i,n)REP(j,n)REP(k,n) {
			product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long k) {
	Matrix product;
	REP(i,n) product.a[i][i] = 1;
	while(k > 0) {
		if(k % 2) {
			product = product * a;
		}
		a = a * a;
		k /= 2;
	}
	return product;
}
int main() {
	int k;
	cin>>k;
	Matrix single;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j<n; ++j){
			if(i != j)
			single.a[i][j] = 1;
			else
			single.a[i][j] = 0;
		}
	}
	Matrix total = expo_power(single, k);
	cout << total.a[0][0] << endl;
}
