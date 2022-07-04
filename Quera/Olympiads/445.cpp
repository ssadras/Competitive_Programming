// Created by:
// Sadra Setarehdan
// Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
// Date: 7-4-2022

#include <bits/stdc++.h>

using namespace std;

// Pragmas here
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

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
const int maxn = 1e6 + 10;

// Before structs global variables and functions here


// Structs here


// Global variables here
ll n, k;
ll a[maxn], b[maxn], temp1[5 * maxn], temp2[maxn];
bool flag[maxn];

// Functions here
void build(int u, int l, ll r) {
    if (l == r) {
        if (flag[l])
            temp1[u] = maxn;

        else
            temp1[u] = l;

    } else {
        int mid = (l + r) / 2;

        build(2 * u, l, mid);
        build(2 * u + 1, mid + 1, r);

        temp1[u] = min(temp1[2 * u + 1], temp1[2 * u]);
    }
}

void update(int u, ll l, ll r, int x, int w) {
    if (l == r)
        temp1[u] = w;

    else {
        int mid = (l + r) / 2;

        if (l <= x and x <= mid)
            update(2 * u, l, mid, x, w);
        else
            update(2 * u + 1, mid + 1, r, x, w);

        temp1[u] = min(temp1[2 * u], temp1[2 * u + 1]);
    }
}


// Main here
int main() {
    IOS

    cin >> k >> n;
    for0(i, k) {
        cin >> a[i];

        if (a[i] <= k + 1) {
            flag[a[i]] = true;
            temp2[a[i]]++;
        }
    }

    build(1, 1, k + 1);

    b[0] = temp1[1];
    temp2[temp1[1]]++;

    update(1, 1, k + 1, temp1[1], maxn);

    fora(i, 1, k + 1) {
        if (a[i - 1] <= k + 1) {
            temp2[a[i - 1]]--;

            if (!temp2[a[i - 1]])
                update(1, 1, k + 1, a[i - 1], a[i - 1]);
        }

        b[i] = temp1[1];
        temp2[temp1[1]]++;

        update(1, 1, k + 1, temp1[1], maxn);
    }

    cout << b[n % (k + 1)] << "\n";
    return 0;
}
