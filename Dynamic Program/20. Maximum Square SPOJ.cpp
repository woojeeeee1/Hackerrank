#include <bits/stdc++.h>
using namespace std;

#define quick() ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
using ll = long long;
int mod = 1e9 + 7;

int main(){
    quick();
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1], dp[n + 1][m + 1];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(dp, 0, sizeof(dp)); int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = a[i][j];
            else{
                if(a[i][j])
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                else
                    dp[i][j] = 0;
            }
            res = max(dp[i][j], res);
        }
    }
    cout << res;
}
/*

*/