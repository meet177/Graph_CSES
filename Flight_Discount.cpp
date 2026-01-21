/**
 *    author:  Meet
 *    created: 06.01.2026 21:53:44
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
vector<vector<ll>> dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    adj.assign(n+1,{});
    dp.assign(n+1, vector<ll>(2,INF));

    dp[1][0] = 0;

    for(ll i=0; i<m; ++i) {
        ll u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
    }
    
    priority_queue<array<ll,3>, vector<array<ll,3>>, greater<array<ll,3>>> pq;
    pq.push({0,1,0});

    while(!pq.empty()) {
        auto [d, ver, used] = pq.top(); pq.pop();

        if(d > dp[ver][used]) continue;

        for(auto& [child, dis] : adj[ver]) {
            if(used) {
                if(dp[ver][used] + dis < dp[child][used]) {
                    dp[child][used] = dp[ver][used] + dis;
                    pq.push({dp[child][used], child, used});
                }
            }else {
                if(dp[ver][0] + dis < dp[child][0]) {
                    dp[child][0] = dp[ver][0] + dis;
                    pq.push({dp[child][0], child, 0});
                }
                if(dp[ver][0] + dis/2 < dp[child][1]) {
                    dp[child][1] = dp[ver][0] + dis/2;
                    pq.push({dp[child][1], child, 1});
                }
            }
        }
    }

    ll ans = dp[n][1];

    cout << ans << "\n";
    return 0;
}