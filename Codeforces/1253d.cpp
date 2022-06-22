/*
 * author: Seyed Sadra Setarehdan
 * Problem: 276c Little Girl and Maximum Sum
 * Date: 12/20/2020
 */

#include <bits/stdc++.h>

using namespace std;

// Templates here
template<typename T1, typename T2, typename T3>
class triple {
public:
    T1 first;
    T2 second;
    T3 third;

    triple() {
        first = 0;
        second = 0;
        third = 0;
    }
};

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
typedef map<string, int> mpsi;
typedef map<string, ll> mpsl;
typedef map<int, int> mpii;
typedef map<ll, ll> mpll;

// Defines here
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define fora(i, a, b) for(int i=a;i<b;i++)
#define forla(i, a, b) for(ll i=a;i<b;i++)
#define for0(i, b) fora(i,0,b)
#define forl0(i, b) forla(i,0,b)
#define rofa(i, a, b) for(int i=a;i>=b;i--)
#define rofla(i, a, b) for(ll i=a;i>=b;i--)
#define rof0(i, a) rofa(i,a,0)
#define rofl0(i, a) rofla(i,a,0)
#define forag(i, a, b, g) for(int i=a;i<b;i+=g)
#define forlag(i, a, b, g) for(ll i=a;i<b;i+=g)
#define for0g(i, b, g) forag(i,0,b,g)
#define forl0g(i, b, g) forlag(i,0,b,g)
#define rofag(i, a, b, g) for(int i=a;i>=b;i-=g)
#define roflag(i, a, b, g) for(ll i=a;i>=b;i-=g)
#define rof0g(i, a, g) rofag(i,a,0,g)
#define rofl0g(i, a, g) roflag(i,a,0,g)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define T third
#define GraphM1(g, n) int g[n][n]
#define GraphM2(g, n) vi g[n]

// Const variables here
const ll maxn = 1e6 + 10;

// Global variables here
ll n, m, ans, temp1, temp2, temp3;
GraphM2(g, maxn);
bool visited[maxn];

// Functions here
void dfs(ll v) {

    visited[v] = true;
    temp3 = max(temp3, v);

    for (auto u: g[v])
        if (!visited[u])
            dfs(u);

}

// Main here
int main() {
    IOS

    cin >> n >> m;

    for0(i, m) {
        cin >> temp1 >> temp2;
        g[temp1].pb(temp2);
        g[temp2].pb(temp1);
    }

    fora(i, 1, n + 1)if (!visited[i]) {
            if (i < temp3)
                ans++;

            dfs(i);
        }


    cout << ans << "\n";

    return 0;
}