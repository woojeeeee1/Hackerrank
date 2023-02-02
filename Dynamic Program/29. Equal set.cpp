#include <bits/stdc++.h>
using namespace std;

#define quick() ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
using ll = long long;
int mod = 1e9 + 7;

ll powMod(ll a,ll b)
{
    if(b == 0)
        return 1;
    if(b % 2 == 0)
        return powMod(a * a % mod, b / 2) % mod;
    else return a * powMod(a * a % mod,b / 2) % mod;
}

int main(){
    quick();
    int n; cin >> n;
    int s = 0;
    for(int i = 1; i <= n; i++)s += i;
    if(s % 2)
    {
        cout << 0;
        return 0;
    }
    s /= 2;
    int dp[s + 1] = {0};
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = s; j >= i; j--)
        {
            dp[j] += dp[j - i];
            dp[j] %= mod;
        }
    }
    cout << (dp[s] * powMod(2, mod - 2)) % mod;
}
/*

*/