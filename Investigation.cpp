/**
 *    author:  Meet
 *    created: 09.01.2026 17:02:00
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

vector<vector<pair<ll,ll>>> adj;
vector<ll> dp, paths, mnf, mxf;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    adj.assign(n+1, {});
    dp.assign(n+1,INF);
    paths.assign(n+1,0);
    mnf.assign(n+1,INF);
    mxf.assign(n+1,0);

    for(ll i=0; i<m; ++i) {
        ll u,v,c;
        cin >> u >> v >> c;

        adj[u].push_back({v,c});
    }

    paths[1] = 1;
    dp[1] = mnf[1] = mxf[1] = 0;

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});

    while(!pq.empty()) {
        auto [d, ver] = pq.top(); pq.pop();

        if(d > dp[ver]) continue;

        for(auto& [child, dis] : adj[ver]) {
            if(dp[ver] + dis == dp[child]) {
                paths[child] = (paths[child] + paths[ver]) % M;
                mnf[child] = min(mnf[child], mnf[ver] + 1);
                mxf[child] = max(mxf[child], mxf[ver] + 1);
            }
            if(dp[ver] + dis < dp[child]) {
                dp[child] = dp[ver] + dis;
                paths[child] = paths[ver];
                mnf[child] = mnf[ver] + 1;
                mxf[child] = mxf[ver] + 1; 
                pq.push({dp[child], child});
            }
        }
    }

    cout << dp[n] << " " << paths[n] << " " << mnf[n] << " " << mxf[n] << "\n";  
    return 0;
}