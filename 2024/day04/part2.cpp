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
const vector<pii> dirs = {{-1,-1},{-1,1},{1,1},{1,-1}};

int n,m;

void solve()
{
    string s;
    vector<string>v;
    while(getline(cin,s))
    {
        v.ep(s);
    }
    n = v.size();
    m = v[0].size();
    int res = 0;
    for (int i = 1; i < n-1; ++i)
    {
        for (int j = 1; j < m-1; ++j)
        {
            if (v[i][j] == 'A')
            {
                string sa = "";
                string sb = "####";
                for (const pii &dir : dirs)
                {
                    sa += v[i+dir.first][j+dir.second];
                }
                bool f = 0;
                for (int m1 = 0; m1 <= 1; ++m1)
                {
                    for (int m2 = 0; m2 <= 1; ++m2)
                    {
                        if (m1)
                        {
                            sb[0] = 'M';
                            sb[2] = 'S';
                        }
                        else
                        {
                            sb[0] = 'S';
                            sb[2] = 'M';
                        }
                        if (m2)
                        {
                            sb[1] = 'M';
                            sb[3] = 'S';
                        }
                        else
                        {
                            sb[1] = 'S';
                            sb[3] = 'M';
                        }
                        f |= (sa == sb);
                    }
                }
                res += f;
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
