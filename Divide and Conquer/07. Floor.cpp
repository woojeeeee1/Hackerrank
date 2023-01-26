#include <bits/stdc++.h>
using namespace std;

#define quick() ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
using ll = long long;
int mod = 1e9 + 7;

int solve(int a[], int n, int X){
    int res = -1, l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r)/2;
        if(a[m] <= X){
            l = m + 1;
            res = m;
        }else{
            r = m - 1;
        }
    }
    return res;
}

int main(){
    quick();
    int n,X; cin >> n >> X;
    int a[n];
    for(int &x : a)cin >> x;
    int k = solve(a, n, X);
    if(k != -1)
        cout << a[k];
    else
        cout << k;
}
/*

*/