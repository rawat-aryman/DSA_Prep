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

bool check(int men, vector<pair<int,pair<int,int>>>&clan, vector<pair<int,int>>&dish, int x){
    int c = clan.size(), b = dish.size();
    int i = 0, j = 0;

    while(i < c && j < b){
        int xi = dish[j].first, pi = clan[i].first;
        int yi = dish[j].second, qi = clan[i].second.first, ri = clan[i].second.second;

        if(xi < pi){
            if(yi >= men) return false;
            else{
                //chef can move forward
                men -= yi;
                j++;
            }
        }else{
            if(qi > men){
                // skip this clan and move forward
                i++;
            }
            else{
                // add the clan members and move forward
                men += ri;
                i++;
            }
        }

    }

    // all dishes are eaten
    if(j == b) return true;

    // all clans are finished
    while(j < b){
        int yi = dish[j].second;
        if(yi >= men){
            // cannot move forward
            return false;
        }
        else{
            men -= yi;
            j++;
        }
    }

    return true;
}

void solve()
{
    int x,b,c,ans = 1;
    vector<pair<int,int>> dish;
    vector<pair<int,pair<int,int>>> clan;
    cin >> x;
    cin >> b;
    for(int i=0;i<b;i++){
        int a,b;
        cin >> a >> b;
        dish.push_back({a,b});
    }
    
    for(int i=0;i<b;i++){
        ans += dish[i].second;
    }

    cin >> c;
    if(c == 0){
        cout << ans << endl;
    }
    else{
        for(int i=0;i<c;i++){
            int p,q,r; cin >> p >> q >> r;
            clan.push_back({p,{q,r}});
        }

        int low = 1, high = ans, a = high;

        while(high - low > 1){
            int men = low + (high - low)/2;

            if(check(men,clan,dish,x)){
                a = min(a,men);
                high = men - 1;
            }
            else{
                low = men + 1;
            }
        }

        if(low < a) a = min(low,a);
        if(high < a) a = min(high,a);

        cout << a << endl;
    }
}
int32_t main()
{
    w(t) solve();
}