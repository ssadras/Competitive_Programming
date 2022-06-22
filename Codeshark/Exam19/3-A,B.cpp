// Credits:
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
const int delta = 10847;
const int maxn = 1e6 + 100;

// Before structs global variables and functions here


// Structs here


// Global variables here
ll fact[maxn];

// Functions here
inline int add(int x, int y) {
    int c = x + y;

    if (c >= delta)
        c -= delta;

    if (c < 0)
        c += delta;

    return c;
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

int baseAToBase10(vi &x, int a, int n) {
    int res = 0;

    fora(i, 1, n) {
        int tmp;

        if (i == 1)
            tmp = x[n - i];
        else
            tmp = mul(x[n - i], pwr(a, i - 1));

        res = add(res, tmp);
    }

    return res;
}

// Main here
int main() {

    fact[1] = 1;
    fora(i, 2, maxn)fact[i] = fact[i - 1] * i;

    int n;
    cin >> n;

    vi a(fact[n]), b(fact[n]);
    fora(i, 1, fact[n] + 1) {
        a[i] = i;
        b[i] = i;
    }

    fora(i, 1, n) {

        fora(j, fact[i] + 1, fact[n] + 1)b[j] = a[j - fact[i]];

        fora(j, 1, fact[i] + 1)b[j] = a[fact[n] - fact[i] + j];

        fora(j, 1, fact[n] + 1)a[j] = b[j];
    }

    cout << baseAToBase10(a, fact[n] + 3, fact[n] + 1) << "\n";

}
