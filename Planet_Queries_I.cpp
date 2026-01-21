/**
 *    author:  Meet
 *    created: 09.01.2026 22:38:45
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
ll dp[N][31];
vector<ll> succ;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,q;
    cin >> n >> q;

    succ.assign(n+1,-1);

    for(ll i=1; i<=n; ++i) {
        cin >> succ[i];
    }

    for(ll i=1; i<=n; ++i) {
        dp[i][0] = succ[i];
    }

    for(ll i=1; i<=30; ++i) {
        for(ll j=1; j<=n; ++j) {
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    while(q--) {
        ll x,k;
        cin >> x >> k;

        for(ll i=0; i<=30; ++i) {
            if((k >> i) & 1) {
                x = dp[x][i];
            }
        }

        cout << x << "\n";
    }
    return 0;
}