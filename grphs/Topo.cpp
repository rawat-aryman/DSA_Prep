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

void solve()
{
    int n,m; cin >> n >> m;
    vector<int> indegree(n,0);

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> pending;

    for(int i=0;i<n;i++){
        if(indegree[i] == 0) {
            pending.push(i);
            vis[i] = 1;
        }
    }

    while(!pending.empty()){
        int front = pending.front();
        pending.pop();

        cout << front << " ";

        for(auto it : adj[front]){
            if(vis[it] != 1){
                indegree[it]--;
                if(indegree[it] == 0){
                    vis[it] = 1;
                    pending.push(it);
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        if(indegree[i] != 0){
            cout << "a cycle exists no topological ordering is possible here" << endl;
            break;
        }
    }



}

int32_t main()
{
    solve();
}