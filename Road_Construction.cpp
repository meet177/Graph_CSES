/**
 *    author:  Meet
 *    created: 10.01.2026 22:04:53
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

class DSU {
    vector<ll> par, sz;
    ll comps = 0, mxc = 0;
    public :

    DSU(ll n) {
        comps = n;
        mxc = 1;
        par.assign(n+1, 0);
        sz.assign(n+1, 1);
        iota(whole(par), 0LL);
    }

    ll find(ll n) {
        if(par[n] == n) return n;
        return par[n] = find(par[n]);
    }

    void unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];

        --comps;
        mxc = max(mxc, sz[a]);
    }

    void print() {
        cout << comps << " " << mxc << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n,m;
    cin >> n >> m;

    DSU dsu(n);

    for(ll i=0; i<m; ++i) {
        ll u,v;
        cin >> u >> v;

        dsu.unite(u,v);
        dsu.print();
    }

    return 0;
}