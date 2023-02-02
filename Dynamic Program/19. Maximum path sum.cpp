#include <bits/stdc++.h>
using namespace std;

#define quick() ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
using ll = long long;
int mod = 1e9 + 7;

int main(){
    quick();
    int n,m; cin >> n >> m;
    int a[101][101];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll dp[101][101] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0)
                dp[i][j] = a[i][j];
            else if(i == 0)
                dp[i][j] += dp[i][j - 1] + a[i][j];
            else if(j == 0)
                dp[i][j] += dp[i - 1][j] + a[i][j];
            else 
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    cout << dp[n - 1][m - 1];
}
/*

*/