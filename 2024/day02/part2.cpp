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

void solve()
{
    string s;
    int res = 0;
    while(getline(cin,s))
    {
        vector<int>v;
        string tmp = "";
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                v.ep(stoll(tmp));
                tmp.clear();
            }
            else
            {
                tmp += s[i];
            }
        }
        v.ep(stoll(tmp));
        for (size_t x = 0; x < v.size(); ++x)
        {
            vector<int>vv;
            for (int k = 0; k < v.size(); ++k)
            {
                if (k != x)
                {
                    vv.ep(v[k]);
                }
            }
            bool f = (is_sorted(all(vv)) || is_sorted(all(vv),greater<int>()));
            for (size_t i = 1; i < vv.size() && f; ++i)
            {
                f &= (abs(vv[i]-vv[i-1]) >= 1 && abs(vv[i]-vv[i-1]) <= 3);
            }
            if (f)
            {
                res++;
                break;
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
