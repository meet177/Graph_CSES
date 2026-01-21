/**
 *    author:  Meet
 *    created: 06.01.2026 14:17:19
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

vector<vector<ll>> dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m,q;
    cin >> n >> m >> q;

    dp.assign(n, vector<ll>(n,INF));

    for(ll i=0; i<n; ++i) dp[i][i] = 0;

    for(ll i=0; i<m; ++i) {
        ll u,v,c;
        cin >> u >> v >> c;
        --u,--v;
        dp[u][v] = min(dp[u][v], c);
        dp[v][u] = min(dp[v][u], c);
    }

    //floyd - warshell
    for(ll k=0; k<n; ++k) {
        for(ll i=0; i<n; ++i) {
            for(ll j=0; j<n; ++j) {
                if(dp[i][k] != INF && dp[k][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<n; ++j) {
            if(dp[i][j] == INF) dp[i][j] = -1;
        }
    }

    while(q--) {
        ll u,v;
        cin >> u >> v;
        --u,--v;

        cout << dp[u][v] << "\n";
    }
    return 0;
}