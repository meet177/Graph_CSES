/**
 *    author:  Meet
 *    created: 13.01.2026 21:53:51
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

vector<vector<ll>> adj, rev_adj, dag_adj;
vector<ll> coins, dp, comp;
vector<bool> vis;
vector<ll> indeg;
vector<ll> coins_in_comp;

stack<ll> stk;

void dfs1(ll ver) {
    vis[ver] = 1;

    for(auto& child : adj[ver]) {
        if(vis[child]) continue;
        dfs1(child);
    }

    stk.push(ver);
}

void dfs2(ll ver, ll num) {
    vis[ver] = 1;

    comp[ver] = num;

    for(auto& child : rev_adj[ver]) {
        if(vis[child]) continue;
        dfs2(child, num);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n,m;
    cin >> n >> m;

    coins.assign(n+1,0);
    adj.assign(n+1, {});
    rev_adj.assign(n+1, {});
    comp.assign(n+1, 0);
    vis.assign(n+1, 0);

    for(ll i=1; i<=n; ++i) cin >> coins[i];

    for(ll i=0; i<m; ++i) {
        ll u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for(ll i=1; i<=n; ++i) {
        if(vis[i]) continue;
        dfs1(i);
    }

    for(ll i=1; i<=n; ++i) vis[i] = 0;

    ll comp_num = 0;
    while(!stk.empty()) {
        ll ver = stk.top(); stk.pop();
        if(vis[ver]) continue;
        ++comp_num;
        dfs2(ver, comp_num);
    }

    ll c = comp_num;
    dag_adj.assign(c+1, {});
    //max coins we can collect ending at the ith scc
    dp.assign(c+1, 0);
    indeg.assign(c+1, 0);
    coins_in_comp.assign(c+1, 0);


    //building the dag adj
    {
        for(ll i=1; i<=n; ++i) {
            coins_in_comp[comp[i]] += coins[i];
            for(auto& child : adj[i]) {
                if(comp[i] == comp[child]) continue;
                ++indeg[comp[child]];
                dag_adj[comp[i]].push_back(comp[child]);
            }
        }
    }

    queue<ll> q;
    for(ll i=1; i<=c; ++i) {
        if(indeg[i] == 0) {
            q.push(i);
            dp[i] = coins_in_comp[i];
        }
    }

    while(!q.empty()) {
        ll ver = q.front(); q.pop();
        for(auto& child : dag_adj[ver]) {
            dp[child] = max(dp[child], dp[ver] + coins_in_comp[child]);
            if(--indeg[child] == 0) q.push(child);
        }
    }

    ll ans = 0;
    for(ll i=1; i<=c; ++i) ans = max(ans, dp[i]);

    cout << ans << "\n";
    return 0;
}