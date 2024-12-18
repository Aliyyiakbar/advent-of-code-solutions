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
    int res = 0;
    string s;
    map<int, vector<int>> mp;
    vector<int>v;
    while(getline(cin,s))
    {
        if (count(all(s),'|'))
        {
            string curr = "";
            size_t i = 0;
            while(i < s.size() && s[i] != '|')
            {
                curr += s[i];
                ++i;
            }
            int a = stoll(curr);
            curr.clear();
            ++i;
            while(i < s.size())
            {
                curr += s[i];
                ++i;
            }
            int b = stoll(curr);
            mp[a].ep(b);
        }
        else
        {
            if (s.empty())      continue;
            v.clear();
            string curr = "";
            int ln = s.size();
            for (int i = 0; i < ln; ++i)
            {
                if (s[i] == ',')
                {
                    v.ep(stoll(curr));
                    curr = "";
                }
                else
                {
                    curr += s[i];
                }
            }
            v.ep(stoll(curr));
            //debug(v);
            bool f = 1;
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = i + 1; j < v.size(); ++j)
                {
                    if (count(all(mp[v[j]]),v[i]))
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if (!f)
            {
                while(1)
                {
                    f = 0;
                    for (int i = 0; i < v.size() && !f; ++i)
                    {
                        for (int j = i + 1; j < v.size() && !f; ++j)
                        {
                            if (count(all(mp[v[j]]),v[i]))
                            {
                                f = 1;
                                swap(v[i],v[j]);
                                break;
                            }
                        }
                    }
                    if (!f)         break;
                }
                res += (v[(((int)v.size())>>1)]);
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
