/*
 * author: Seyed Sadra Setarehdan
 * Problem: 913d Too Easy Problems
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
#define forag(i, a, b, g) for(int i=a;i<b;i+=g)
#define forlag(i, a, b, g) for(ll i=a;i<b;i+=g)
#define for0g(i, b, g) for(int i=0;i<b;i+=g)
#define forl0g(i, b, g) for(ll i=0;i<b;i+=g)
#define rofag(i, a, b, g) for(int i=a;i>=b;i-=g)
#define roflag(i, a, b, g) for(ll i=a;i>=b;i-=g)
#define rof0g(i, a, g) for(int i=a;i>=0;i-=g)
#define rofl0g(i, a, g) for(ll i=a;i>=0;i-=g)
#define all(x) x.begin(),x.end()
#define pb push_back
#define F first
#define S second

// Const variables here


// Global variables here
int low, high, mid, n, T;
vi temp, a, t;

// Functions here
bool check() {
    vpii e;
    for0(i, n)if (a[i] >= mid)
            e.pb(make_pair(t[i], i));

    sort(all(e));
    bool ok = false;

    if ((int) e.size() >= mid) {
        int sum = 0;
        for0(i, mid)sum += e[i].first;

        if (sum <= T) {
            ok = true;
            temp.resize(mid);
            for0(i, mid)temp[i] = e[i].second;
        }
    }
    return ok;
}

// Main here
int main() {
    IOS

    cin >> n >> T;
    a.resize(n);
    t.resize(n);
    for0(i, n)cin >> a[i] >> t[i];

    high = n;
    while (low < high) {
        mid = (low + high + 1) >> 1;

        if (check())
            low = mid;
        else
            high = mid - 1;
    }

    cout << temp.size() << "\n" << temp.size() << "\n";
    for0(i, (int) temp.size()) {
        if (i > 0)
            cout << ' ';
        cout << temp[i] + 1;
    }
    cout << "\n";
    return 0;
}