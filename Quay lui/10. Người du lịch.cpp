#include <bits/stdc++.h>
using namespace std;

#define quick() ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
using ll = long long;
int mod = 1e9 + 7;

int n, C[100][100], X[100];
bool visited[100];
int res = INT_MAX, cmin = INT_MAX;

void nhap()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) 
        {
            cin >> C[i][j];
            if(C[i][j]) cmin = min(cmin,C[i][j]);
        }
    }
}

void Try(int i, int cost)
{
    for(int j = 2; j <= n; j++)
    {
        if(!visited[j])
        {
            visited[j] = true;
            X[i] = j;
            cost += C[X[i - 1]][X[i]];
            if(i == n)
            {
                cost += C[1][X[i]];
                res = min(res,cost);
            }else if(cost + (n - i + 1) * cmin < res)
                Try(i + 1, cost);
            cost -= C[X[i - 1]][X[i]];
            visited[j] = false;
        }
    }
}

int main(){
    quick();
    nhap();
    X[1] = 1;
    Try(2, 0);
    cout << res;
}
/*

*/