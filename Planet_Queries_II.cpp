/**
 *    author:  Meet
 *    created: 10.01.2026 16:12:11
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)
 
#define ll long long int
const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)
 
#define whole(x) (x).begin(), (x).end()
 
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"
 
const ll N = 2e5 + 10;
ll dp[N][25];
 
vector<ll> succ, len;
//len[i] defines the length of the path we need to travel from i to reach the start of the cycle that it leads to
vector<bool> vis;
 
void dfs(ll ver) {
    if(vis[ver]) return;
    vis[ver] = 1;
 
    //process successor first, then while backtracking we are updating len as we can only come to any successor once it processed
    dfs(succ[ver]);
 
    len[ver] = len[dp[ver][0]] + 1;
}
 
ll jump(ll a, ll k) {
    for(ll i=0; i<25; ++i) {
        if((k >> i) & 1) {
            a = dp[a][i];
        }
    }
    return a;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,q;
    cin >> n >> q;
 
    succ.assign(n+1,-1);
    len.assign(n+1,0);
    vis.assign(n+1,0);
 
    for(ll i=1; i<=n; ++i) {
        cin >> succ[i];
    }
 
    for(ll i=1; i<=n; ++i) dp[i][0] = succ[i];
 
    for(ll i=1; i<25; ++i) {
        for(ll j=1; j<=n; ++j) dp[j][i] = dp[dp[j][i-1]][i-1];
    }
 
    for(ll i=1; i<=n; ++i) {
        if(vis[i]) continue;
        dfs(i);
    }
 
    while(q--) {
        ll a,b;
        cin >> a >> b;
 
        ll ans = -1;
        //a is in the tree of b
        if(len[a] >= len[b] && jump(a, len[a]-len[b]) == b) {
            ans = len[a] - len[b];
        }
        //both is in the cycle
        else {
            ll cyclept = jump(a, len[a]);
            if(jump(a, len[cyclept] - (len[b] - len[a])) == b) {
                ans = len[cyclept] - (len[b] - len[a]);
            }
        }
 
        cout << ans << "\n";
    }
    return 0;
}