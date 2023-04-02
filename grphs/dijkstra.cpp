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

// implementing dijkstra algo having overall timecomplexity of O((V+E)*log(V))

void solve()
{
    int n,m,src; cin >> n >> m >> src;

    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    vector<int> dist(n,INT_MAX), vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});

    dist[src] = 0;

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        vis[node] = 1;
        pq.pop();

        for(auto it: adj[node]){
            if(!vis[it.first]){
                if(d + it.second < dist[it.first]){
                    dist[it.first] = d + it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << dist[i] << " ";
    }cout << endl;
}

int32_t main()
{
    solve();
}