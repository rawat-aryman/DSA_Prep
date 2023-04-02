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

vector<pair<int,int>> adj[100005];
vector<int> vis(100005,0);

void solve()
{
    int n,m; cin >> n >> m;
    int minWt = 0;

    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    pq.push({0,{0,-1}});
    vis[0] = 1;

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;

        pq.pop();

        if(vis[node] == 1) continue;

        minWt += wt;
        vis[node] = 1;

        for(auto it : adj[node]){
            if(vis[it.first] != 1){
                pq.push({it.second,{it.first,node}});
            }
        }
    }

    bool f = 0;

    for(int i=0;i<n;i++){
        if(vis[i] != 1){
            f = 1;
            break;
        }
    }

    if(f == 1) cout << "graph is disconnected" << endl;
    else cout << minWt << endl;
}

int32_t main()
{
    solve();
}