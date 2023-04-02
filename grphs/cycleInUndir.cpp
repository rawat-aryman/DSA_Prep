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

vector<int> adj[100005];
vector<int> vis(100005,0);

bool dfs(int node, int par){

    vis[node] = 1;

    for(auto it : adj[node]){
        if(vis[it] == 1){
            if(it == par) continue;
            if(it != par) return 0;
        }
        else {
            if(!dfs(it,node)) return false;
            
        }
    }

    return true;
}

bool bfs(int node, int par){

    queue<pair<int,int>> pending;

    pending.push({node,par});
    vis[node] = 1;

    while(!pending.empty()){
        int node = pending.front().first;
        int par = pending.front().second;
        pending.pop();

        for(auto it : adj[node]){
            if(vis[it]){
                if(it == par) continue;
                else return false;
            }
            else{
                vis[it] = 1;
                pending.push({it,node});
            }
        }

        return true;
    }
}

void solve()
{
    int n,m; cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        if(vis[i] != 1){
            if(!bfs(i,-1)) {
                cout << "cycle exists";
                return;
            }
        }
    }
}
int32_t main()
{
    w(t) solve();
}