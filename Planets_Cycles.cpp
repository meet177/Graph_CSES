/**
 *    author:  Meet
 *    created: 10.01.2026 17:39:00
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

vector<bool> vis;
vector<ll> succ, dp;

ll cyclept = -1;
vector<ll> curr_cycle;

void dfs(ll ver) {
    if(vis[ver]) {
        cyclept = ver;
        return;
    }
    vis[ver] = 1;

    dfs(succ[ver]);

    if(dp[succ[ver]] != -1) {
        dp[ver] = dp[succ[ver]] + 1;
        return;
    }

    curr_cycle.push_back(ver);
    if(ver == cyclept) {
        for(auto& curr : curr_cycle) dp[curr] = curr_cycle.size();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;

    dp.assign(n+1, -1);
    succ.assign(n+1, -1);
    vis.assign(n+1, 0);

    for(ll i=1; i<=n; ++i) {
        cin >> succ[i];
    }

    for(ll i=1; i<=n; ++i) {
        if(vis[i]) continue;
        cyclept = -1;
        curr_cycle.clear();
        dfs(i);
    }

    for(ll i=1; i<=n; ++i) cout << dp[i] << " ";
    cout << "\n";
    return 0;
}