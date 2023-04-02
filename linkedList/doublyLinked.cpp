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

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void solve()
{
    Node *head = NULL;
    Node *temp = new Node;
    temp->data = 2;
    temp->next = NULL;
    temp->prev = NULL;

    Node *temp2 = new Node;
    temp2->data = 3;
    temp2->next = NULL;
    temp2->prev = temp;
    temp->next = temp2;

    head = temp;

    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
}

int32_t main()
{
    solve();
}