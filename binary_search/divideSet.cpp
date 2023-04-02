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
    int n,k; cin >> n >> k;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    else {
        if(a[n-1] - a[0] <= k) {
            cout << 0 << endl;
            return;
        }

        else{
            int el = n+1;
            for(int i=0;i<n;i++){
                int key = a[i] + k;
                int ind = lower_bound(a.begin() + i + 1, a.end(), key) - a.begin();

                if(ind >= n) continue;
                else{
                    if(a[ind] - a[i] > k) continue;
                    else el = min(el, i + n - 1 - ind); 
                }
            }
            cout << el << endl;
        }
    }

}
int32_t main()
{
    solve();
}