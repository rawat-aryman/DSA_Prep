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

// tc -> O(n)
bool brute(int n){

    for(int i=2;i<n;i++){
        if(n % i == 0) return false;
    }
    return true;
}

// tc -> O(n/2) == O(n)
bool better(int n){

    for(int i = 2;i <= n/2; i++){
        if(n % i == 0) return false;
    }

    return true;
}

// tc -> sqrt(n)
bool best(int n){

    for(int i=2;i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }

    return true;
}

void solve()
{
    int n; cin >> n;

    bool prime = brute(n);
    bool isPrime = better(n);
    bool isP = best(n);

    cout << prime << " " << isPrime << " " << isP << endl;

}

int32_t main()
{
    solve();
}