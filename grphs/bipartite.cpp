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
vector<int> vis(100005,0), col(100005,0);

bool bfs(int node){
    queue<int> pending;
    pending.push(node);
    vis[node] = 1;
    col[node] = 1;

    while(!pending.empty()){
        int node = pending.front();
        int cl = col[node];

        for(auto it : adj[node]){

            if(vis[it] == 1){
                if(cl == col[it]) return true;
                
            }

            if(vis[it] != 1){
                vis[it] = 1;
                pending.push(it);
                col[it] = (cl == 1 ? 2 : 1);
            }
        }
    }

    return false;
}

bool dfs(int node){
    
    vis[node] = 1;
    int cl = col[node];
    for(auto it : adj[node]){
        if(vis[it] == 1){
            if(cl == col[it]) return true;
            
        }
        if(vis[it] != 1){
            
            col[it] = (cl == 1 ? 2 : 1);

        }
    }

    return false;
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
            if(bfs(i)) {
                cout << "graph cannot be bipartited...." << endl;
            }
        }
    }

}

int32_t main()
{
    w(t) solve();
}