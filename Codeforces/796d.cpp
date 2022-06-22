/*
 * author: Seyed Sadra Setarehdan
 * Problem: 796d Police Stations
 * Date: 2/5/2021
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
#define fora(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define forla(i, a, b) for(ll (i)=(a);(i)<(b);(i)++)
#define for0(i, b) fora((i),0,(b))
#define forl0(i, b) forla((i),0,(b))
#define rofa(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define rofla(i, a, b) for(ll (i)=(a);(i)>=(b);(i)--)
#define rof0(i, a) rofa((i),(a),0)
#define rofl0(i, a) rofla((i),(a),0)
#define forag(i, a, b, g) for(int (i)=(a);(i)<(b);(i)+=(g))
#define forlag(i, a, b, g) for(ll (i)=(a);(i)<(b);(i)+=(g))
#define for0g(i, b, g) forag((i),0,(b),(g))
#define forl0g(i, b, g) forlag((i),0,(b),(g))
#define rofag(i, a, b, g) for(int (i)=(a);(i)>=(b);(i)-=(g))
#define roflag(i, a, b, g) for(ll (i)=(a);(i)>=(b);(i)-=(g))
#define rof0g(i, a, g) rofag((i),(a),0,(g))
#define rofl0g(i, a, g) roflag((i),(a),0,(g))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define T third
#define GraphM1(g, n) int (g)[(n)][(n)]
#define GraphM2(g, n) vi (g)[(n)]

// Const variables here
const int maxn = 3e5 + 10;

// Global variables here
int n, k, d;
int dp[maxn], p[maxn];
vector<pii> g[maxn];
queue<int> Q;
set<int> st;

// Functions here
void bfs() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto i : g[v]) {
            if (dp[i.F] == -1) {
                p[i.F] = v;
                dp[i.F] = dp[v] + 1;
                Q.push(i.F);
            } else if (p[v] != i.F && v != 0)
                st.insert(i.S);
        }
    }

}


// Main here
int main() {
    IOS

    cin >> n >> k >> d;
    for0(i,k) {
        int x;
        cin >> x;
        g[0].pb(MP(x, 0));
    }

    fora(i,1,n) {
        int u, v;
        cin >> u >> v;
        g[u].pb(MP(v, i));
        g[v].pb(MP(u, i));
    }

    bfs();

    cout << st.size() << '\n';

    for (auto i : st)
        cout << i << ' ';
    cout<<"\n";

    return 0;
}