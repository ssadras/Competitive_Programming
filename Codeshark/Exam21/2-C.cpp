// Created by:
// Sadra Setarehdan
// Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
// Date: 6-22-2022

#include <bits/stdc++.h>

using namespace std;

// Pragmas here
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")

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
typedef long double ld;
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
#define pf push_front
#define MP make_pair
#define F first
#define S second
#define GraphM1(g, n) int (g)[(n)][(n)]
#define GraphM2(g, n) vi (g)[(n)]


// Const variables here
const int delta = 10651;
const int maxn = 200;

// Before structs global variables and functions here


// Structs here


// Global variables here
int fact[maxn];
ll modd = 1e9 + 7;
ll b[maxn][maxn], c[maxn][maxn], ans[maxn][maxn], a[maxn][maxn];
bool mark[maxn][maxn];

// Functions here
inline int add(int x, int y) {
    int c = x + y;

    if (c >= delta)
        c -= delta;

    while (c < 0)
        c += delta;

    return c % delta;
}

inline int mul(int x, int y) {
    return 1ll * x * y % delta;
}

inline int pwr(int x, int y) {
    int ans = 1;

    while (y) {
        if (y & 1)
            ans = mul(ans, x);

        y /= 2;
        x = mul(x, x);
    }

    return ans;
}

int inv(int n) {
    return pwr(n, delta - 2);
}

int C(int n, int k) {
    return mul(mul(fact[n], inv(fact[k])), inv(fact[n - k])) % delta;
}

ll pwr2(ll a, ll b) {
    if (b == 0)
        return 1;
    ll x = pwr2(a, b / 2) % modd;
    if (b % 2)
        return x * x % modd * a % modd;
    return x * x % modd;
}

// Main here
int main() {
    int n = 100;

    fora(i, 1, n + 1)fora(j, 1, n + 1)c[i][j] = pwr2(7, i) * pwr2(3, j) % modd + 1e8;

    b[1][n] = b[1][1] = b[n][n] = b[n][1] = 1;

    for0(q, 200) {
        fora(i, 1, n + 1)
            fora(j, 1, n + 1)
                if (b[i][j] >= 1) {
                    if (i + 1 <= n)
                        a[i + 1][j]++;

                    if (j + 1 <= n)
                        a[i][j + 1]++;

                    if (i - 1 >= 1)
                        a[i - 1][j]++;

                    if (j - 1 >= 1)
                        a[i][j - 1]++;
                }

        fora(i, 1, n + 1)fora(j, 1, n + 1) {
                b[i][j] += a[i][j];
                a[i][j] = 0;
                ans[i][j]++;
            }
    }

    fora(q, 1, 1e4 + 11) {
        ll p = 1e17;

        fora(i, 1, n + 1) {
            fora(j, 1, n + 1) {
                int u = 0;

                if (!mark[i + 1][j] and i + 1 <= n and b[i + 1][j] > 0)
                    u++;

                if (!mark[i - 1][j] and i - 1 >= 1 and b[i - 1][j] > 0)
                    u++;

                if (!mark[i][j - 1] and j - 1 >= 1 and b[i][j - 1] > 0)
                    u++;

                if (!mark[i][j + 1] and j + 1 <= n and b[i][j + 1] > 0)
                    u++;

                if (!mark[i][j] and u > 0) {
                    ll x = c[i][j] - b[i][j];

                    if (x % u == 0)
                        x /= u;

                    else
                        x /= u, x++;

                    p = min(p, x);
                }
            }
        }

        fora(i, 1, n + 1) {
            fora(j, 1, n + 1) {
                int u = 0;

                if (!mark[i + 1][j] and i + 1 <= n and b[i + 1][j] > 0)
                    u++;

                if (!mark[i - 1][j] and i - 1 >= 1 and b[i - 1][j] > 0)
                    u++;

                if (!mark[i][j - 1] and j - 1 >= 1 and b[i][j - 1] > 0)
                    u++;

                if (!mark[i][j + 1] and j + 1 <= n and b[i][j + 1] > 0)
                    u++;

                if (!mark[i][j] and u > 0) {
                    a[i][j] += p * u;
                    ans[i][j] += p;
                }
            }
        }

        fora(i, 1, n + 1)
            fora(j, 1, n + 1) {
                b[i][j] += a[i][j];

                if (b[i][j] >= c[i][j])
                    mark[i][j] = true;

                a[i][j] = 0;
            }
    }

    ll ans2 = 0;
    fora(i, 1, n + 1)
        fora(j, 1, n + 1)
            if (b[i][j] >= c[i][j])
                ans2 = add(ans2, ans[i][j]);

    cout << pwr(ans2, 3) << "\n";
    return 0;
}
