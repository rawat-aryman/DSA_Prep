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

class DSU{

    vector<int> rank,parent,sze;

    public:
    DSU(int n){

        for(int i=0;i<=n;i++) {
            parent.push_back(i);
            rank.push_back(0);
            sze.push_back(1);
        }
    }
    int findParent(int u){
        if(u == parent[u]) return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int pu = findParent(u), pv = findParent(v);

        if(pu != pv){
            if(rank[pu] >= rank[pv]){
                parent[pv] = pu;
                rank[pu] += 1;
            }
            else {
                parent[pu] = pv;
                rank[pv] += 1;
            }
        }
    }

    void unionBySize(int u, int v){
        int pu = findParent(u), pv = findParent(v);

        if(pu != pv){
            if(sze[pu] >= sze[pv]){
                parent[pv] = pu;
                sze[pu] += sze[pv];
            }
            else {
                parent[pu] = pv;
                sze[pv] += sze[pu];
            }
        }
    }
};

void solve()
{

}

int32_t main()
{
    solve();
}