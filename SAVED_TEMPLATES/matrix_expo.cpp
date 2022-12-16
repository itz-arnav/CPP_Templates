#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
#define mod 1000000000
#define ll long long
 
ll k;
vector <ll> a,b,c;
 
vector<vector<ll>> multiply(vector<vector<ll>>A, vector<vector<ll>>B){
    
    vector<vector<ll>> C(k+1,vector<ll>(k+1));
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=k; j++){
            for(int x = 1; x<=k; x++){
            C[i][j]=(C[i][j] + (A[i][x]*B[x][j])%mod)%mod;
        }
        }
    }
    return C;
    
}
 
vector<vector<ll>> power(vector<vector<ll>> A, ll p){
    if(p == 1)
    return A;
    
    else if(p&1){
        return multiply(A,power(A,p-1));
    }
    else{
        vector<vector<ll>>X = power(A,p/2);
        return multiply(X,X);
    }
}
 
 
 
ll compute(ll n){
    if(n == 0)
    return 0;
    if(n <= k)
    return b[n-1];
    
    // otherwise use matrix exponentiation
   
   //F1 matrix 
    vector<ll> F1(k+1);
    
    for(int i = 1; i<=k; i++)
    F1[i] = b[i-1];
    
    // now create Transformation matrix
    
    vector<vector<ll>> T(k+1, vector<ll>(k+1));
    
    for(int i = 1; i<=k; i++){
       
        for(int j = 1; j<=k; j++){
             if(i<k){
                 
            if(j == i+1)
            T[i][j] = 1;
            
            else
            T[i][j] = 0;
        }
        else {
            T[i][j] = c[k-j];
        }
    }
    }
    
    //now find T^n-1
    
    T = power(T, n-1);
    
    // now multiply T with F1
    
    ll res = 0;
    for(int i = 1; i<=k; i++){
        res = (res + (T[1][i]*F1[i])%mod)%mod;
    }
    return res;
    
}
 
int main(){
    
    
    ll t,n,num;
    cin>>t;
 
    while(t--){
       cin>>k;
       
       // value of b, F1 vector
       
       for(int i = 0; i<k; i++)
       {
           cin>>num;
           b.push_back(num);
       }
       
       //coefficients
       
       for(int i = 0; i<k; i++)
       {
           cin>>num;
           c.push_back(num);
       }
       
       cin>>n;
       cout<<compute(n)<<endl;
       b.clear();
       c.clear();
        
    }
	
	return 0;
}
