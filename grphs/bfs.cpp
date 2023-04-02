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

void bfs(int node, vector<int>adj[], vector<int>&vis){
    
    vis[node] = 1;
    queue<int> nodes;

    nodes.push(node);

    while(!nodes.empty()){
        int node = nodes.front();
        nodes.pop();

        for(auto it : adj[node]){
            if(vis[it] != 1){
                nodes.push(it);
                vis[it] = 1;
            }
        }
    }
}

void solve()
{
    int n,m,count = 0; cin >> n >> m;
    vector<int> adj[100005];
    vector<int> vis(n,0);

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis[0] = 1;

    for(int i=0;i<n;i++){
        if(vis[i] != 1){
            bfs(i,adj,vis);
            count++;
        }
    }

    cout << "Number of disconnected components in the graph are : " << count << endl;




}
int32_t main()
{
    w(t) solve();
}