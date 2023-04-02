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

void solve()
{
    int n; cin >> n;
    vector<bool> sieve(n+1,1);

    sieve[1] = 0;
    sieve[0] = 0;

    for(int i = 2; i*i <= n; i++){
        if(sieve[i]){
            for(int j = i*i; j <= n; j += i){
                sieve[j] = 0;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(sieve[i]) cout << i << " ";
    }
}

int32_t main()
{
    solve();
}