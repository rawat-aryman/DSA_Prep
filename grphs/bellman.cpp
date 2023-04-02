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

// vector<int> adj[100005];
// vector<int> vis(100005,0);

void solve()
{
    int n,m; cin >> n >> m;
    vector<pair<pair<int,int>,int>> edges;
    vector<int> dis(n,INT_MAX);
    bool f = 0;
    dis[0] = 0;

    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w;
        edges.push_back({{a,b},w});
    }

    // relaxing the edges n-1 times:
    // tc -> O(n * m)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int wt = edges[j].second;

            if(dis[u] + wt < dis[v]){
                if(i == n-1){
                    f = 1;
                    break;
                }
                else{
                    dis[v] = dis[u] + wt;
                }
            }
        }
        if(f == 1) break;
    }


    if(f == 1) cout << "negative weight cycle exists in the graph" << endl;
    else {
        for(int i=0;i<n;i++){
            cout << dis[i] << " ";
        } cout << endl;
    }
}

int32_t main()
{
    solve();
}