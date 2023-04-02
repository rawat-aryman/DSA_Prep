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
    vector<int> a, ans;

    for(int i=0;i<n;i++){
        int x; cin >> x;
        a.push_back(x);
    }

    for(int i=0;i<n;i++){
        if(ans.empty()){
            ans.push_back(a[i]);
        }
        else if(ans.size() == 1){
            if(ans[0] > a[i]) ans[0] = a[i];
            else ans.push_back(a[i]);
        }
        else{
            auto it = upper_bound(ans.begin(),ans.end(),a[i]);
            if(it == ans.end()){
                ans.push_back(a[i]);
            }
            else{
                int ind = it - ans.begin();
                ans[ind] = a[i];
            }
        }
    }

    cout << ans.size() << " ";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " "; 
    }cout << endl;
}
int32_t main()
{
    w(t) solve();
}