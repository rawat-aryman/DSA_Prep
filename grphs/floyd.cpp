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
    int n,m; cin >> n >> m;

    vector<vector<int>> grp(n,vector<int>(n,1e8));

    for(int i=0;i<n;i++) grp[i][i] = 0;

    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w;
        grp[a][b] = w;
    }

    for(int via = 0; via < n; via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (grp[i][j] > (grp[i][via] + grp[via][j])
                    && (grp[via][j] != 1e8
                        && grp[i][via] != 1e8))
                    grp[i][j] = grp[i][via] + grp[via][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grp[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    solve();
}