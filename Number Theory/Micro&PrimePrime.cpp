#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define eb              emplace_back
#define em              emplace
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void sieve(vector<bool>&s, int n){

    s[0] = 0; s[1] = 0;

    for(int i=2;i*i <= n-1; i++){
        if(s[i] == 1){
            for(int j = i*i; j <= n-1; j+=i) s[j] = 0;
        }
    }
}

bool prime(int x){

    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void solve()
{
    int l,r; cin >> l >> r;
    vector<bool> s(r+1,1);

    sieve(s,r+1);

    int pp = 0, cnt = 0;

    for(int i=2;i<=r;i++){
        if(s[i] == 1) cnt++;
        if(i >= l && s[cnt] == 1) pp += 1;
    }

    cout << pp << endl;
}

int32_t main()
{
w(t) solve();
}