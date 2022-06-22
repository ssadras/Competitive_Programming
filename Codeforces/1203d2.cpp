/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1203d2 Remove the Substring (hard version)
 * Date: 12/16/2020
 */

#include <bits/stdc++.h>

using namespace std;

// Typedefs here
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set<int> si;
typedef set<ll> sl;
typedef set<pii> spii;
typedef set<pll> spll;

// Defines here
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define fora(i, a, b) for(int i=a;i<b;i++)
#define forla(i, a, b) for(ll i=a;i<b;i++)
#define for0(i, b) for(int i=0;i<b;i++)
#define forl0(i, b) for(ll i=0;i<b;i++)
#define rofa(i, a, b) for(int i=a;i>=b;i--)
#define rofla(i, a, b) for(ll i=a;i>=b;i--)
#define rof0(i, a) for(int i=a;i>=0;i--)
#define rofl0(i, a) for(ll i=a;i>=0;i--)

// Const variables here


// Global variables here
string s,t;
int temp,ans,temp2;

// Functions here


// Main here
int main() {
    IOS

    cin >> s >> t;
    vi rg(t.size());


    rof0(i, int(t.size())-1) {
        temp = int(s.size()) - 1;
        if (i + 1 < int(t.size()))
            temp = rg[i + 1] - 1;
        while (s[temp] != t[i])
            --temp;
        rg[i] = temp;
    }

    ans = 0;
    temp = 0;
    for0(i,int(s.size())) {
        int temp2 = int(s.size()) - 1;
        if (temp < int(t.size()))
            temp2 = rg[temp] - 1;
        ans = max(ans, temp2 - i + 1);
        if (temp < int(t.size()) and t[temp] == s[i])
            ++temp;
    }

    cout << ans << "\n";
    return 0;
}