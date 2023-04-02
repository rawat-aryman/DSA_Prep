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
    int nodes,edges;
    cin >> nodes >> edges;

    // using adjacency matrix
    int adj[1000][1000];

    // given edges:
    // 0->1, 1->2, 2->0

    for(int i=0;i<edges;i++){
        int nodeA, nodeB; cin >> nodeA >> nodeB;
        adj[nodeA][nodeB] = 1;
        adj[nodeB][nodeA] = 1;
    }


    // using adjacency list

    vector<int> adj2[100005];

    for(int i=0;i<edges;i++){
        int nA, nB; cin >> nA >> nB;
        adj2[nA][nB] = 1;
        adj2[nB][nA] = 1;
    }
}
int32_t main()
{
    w(t) solve();
}