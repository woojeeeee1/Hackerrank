#include<bits/stdc++.h>
using namespace std;

#define quick() ios_base::sync_with_stdio(false); cin.tie(0);
using ll = long long;
int mod=1000000007;

struct Word{
    string word;
    int freq;
};

typedef struct Word Wd;

int find(Wd a[],int n,string temp)
{
    for(int i = 0; i < n; i++)
        if(a[i].word == temp)
            return i;
    return -1;
}
bool cmp(Wd a,Wd b)
{
    if(a.freq != b.freq)
        return a.freq > b.freq;
    return 
        a.word < b.word;
}
bool check(string s)
{
    if(s == "good" || s == "bad" || s == "wonderful" || s == "terrible")return true;
    return false;
}
int main(){
    quick();
    Wd a[1000];
    int n = 0;
    string s;
    while(cin >> s)
    {
        if(check(s))
        {
            int index = find(a,n,s);
            if(index == -1)
            {
                a[n].word = s;
                a[n].freq = 1;
                n++;
            }else{
                a[index].freq++;
            }
        }
    }
    stable_sort(a, a + n, cmp);
    for(int i = 0; i < n; i++)
        cout << a[i].word << " " << a[i].freq << endl;
}
/*

*/