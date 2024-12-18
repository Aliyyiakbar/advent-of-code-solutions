#ifndef ONLINE_JUDGE
#include "AkbarKING.h"
#else
#define debug(...)
#define debugArr(...)
#define debugG(...)
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define int long long
#define $AzH_TxdmN$ ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")

#define ep emplace_back
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using __indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using __indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int sz = 3e5+9;
const int LOG = 63;
const int MOD = 1e9+7;
const int INF = 1e18;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;
vector<string>a;

bool inbound(const int &x, const int &y)
{
    return (0 <= x && 0 <= y && x < n && y < m);
}

int res;
void dfs(int nodeX, int nodeY)
{
    //debug(nodeX,nodeY);
    if (a[nodeX][nodeY] == '9')
    {
        ++res;
        return;
    }
    int gox,goy;
    for (int i = 0; i < 4; ++i)
    {
        gox = nodeX + dx[i];
        goy = nodeY + dy[i];
        if (inbound(gox,goy) && (a[gox][goy] == a[nodeX][nodeY]+1))
        {
            dfs(gox,goy);
        }
    }
}

void solve()
{
    string x;
    while(getline(cin,x))
    {
        a.ep(x);
    }
    n = a.size();
    m = a[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '0')
            {
                dfs(i,j);
            }
        }
    }
    cout<<res<<'\n';
}

signed main()
{
    $AzH_TxdmN$
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
}
