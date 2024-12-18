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
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i-3 >= 0)
            {
                string sa = "";
                sa += v[i][j];
                sa += v[i-1][j];
                sa += v[i-2][j];
                sa += v[i-3][j];
                if ((sa == "XMAS" || sa == "SAMX"))
                {
                    res++;
                }
            }
            if (i-3 >= 0 && j-3 >= 0)
            {
                string sa = "";
                sa += v[i][j];
                sa += v[i-1][j-1];
                sa += v[i-2][j-2];
                sa += v[i-3][j-3];
                if ((sa == "XMAS" || sa == "SAMX"))
                {
                    res++;
                }
            }
            if (j-3 >= 0)
            {
                string sa = "";
                sa += v[i][j];
                sa += v[i][j-1];
                sa += v[i][j-2];
                sa += v[i][j-3];
                if ((sa == "XMAS" || sa == "SAMX"))
                {
                    res++;
                }
            }
            if (i+3 < n && j-3 >= 0)
            {
                string sa = "";
                sa += v[i][j];
                sa += v[i+1][j-1];
                sa += v[i+2][j-2];
                sa += v[i+3][j-3];
                if ((sa == "XMAS" || sa == "SAMX"))
                {
                    res++;
                }
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
