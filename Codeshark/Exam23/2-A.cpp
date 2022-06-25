// Created by:
// Sadra Setarehdan
// Linkedin = https://www.linkedin.com/in/seyed-sadra-setarehdan-b67b391b7/
// Date: 6-25-2022

#include<bits/stdc++.h>

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
const int delta = 10937;
const int maxn = 100;
const int maxn2 = 1e5;

// Before structs global variables and functions here


// Structs here


// Global variables here
ll fact[maxn];
int a[maxn];
bool sieve[maxn2];

// Functions here
inline int add(int x, int y) {
    int c = x + y;

    if (c >= delta)
        c -= delta;

    while (c < 0)
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

int divCount(int n) {
    int res = 1;

    fora(p, 2, n + 1)
        if (sieve[p]) {
            int cnt = 0;

            if (n % p == 0) {
                while (n % p == 0) {
                    n = n / p;
                    cnt++;
                }

                res = res * (cnt + 1);
            }
        }


    return res;
}

void showCube() {
    fora(i, 0, 3) {
        cout << "         ";
        fora(j, 1, 4) {
            if (a[i * 3 + j] < 10)
                cout << '0';
            cout << a[i * 3 + j] << ' ';
        }
        cout << "\n";
    }

    for0(i, 3) {
        fora(j, 1, 13) {
            if (a[i * 12 + j - 1 + 10] < 10)
                cout << '0';
            cout << a[i * 12 + j - 1 + 10] << ' ';
        }
        cout << "\n";
    }

    fora(i, 0, 3) {
        cout << "         ";
        fora(j, 1, 4) {
            if (a[45 + i * 3 + j] < 10)
                cout << '0';
            cout << a[45 + i * 3 + j] << ' ';
        }
        cout << "\n";
    }

}

void turn(int x, int y) {
    if (x == 0 and y == 0) {
        int tmp[4] = {0, a[1], a[2], a[3]};
        a[1] = a[18];
        a[2] = a[30];
        a[3] = a[42];

        a[18] = a[54];
        a[30] = a[53];
        a[42] = a[52];

        a[54] = a[34];
        a[53] = a[22];
        a[52] = a[10];

        a[34] = tmp[1];
        a[22] = tmp[2];
        a[10] = tmp[3];

        int tmp2[3] = {a[19], a[20], a[21]};
        a[19] = a[21];
        a[20] = a[33];
        a[21] = a[45];
        a[33] = a[44];
        a[45] = a[43];
        a[44] = a[31];
        a[43] = tmp2[0];
        a[31] = tmp2[1];

        return;
    }

    if (x == 0 and y == 1) {
        int tmp[4] = {0, a[4], a[5], a[6]};
        a[4] = a[17];
        a[5] = a[29];
        a[6] = a[41];

        a[17] = a[51];
        a[29] = a[50];
        a[41] = a[49];

        a[51] = a[35];
        a[50] = a[23];
        a[49] = a[11];

        a[35] = tmp[1];
        a[23] = tmp[2];
        a[11] = tmp[3];

        return;
    }

    if (x == 0 and y == 2) {
        int tmp[4] = {0, a[7], a[8], a[9]};
        a[7] = a[16];
        a[8] = a[28];
        a[9] = a[40];

        a[16] = a[48];
        a[28] = a[47];
        a[40] = a[46];

        a[48] = a[36];
        a[47] = a[24];
        a[46] = a[12];

        a[36] = tmp[1];
        a[24] = tmp[2];
        a[12] = tmp[3];

        int tmp2[3] = {a[13], a[14], a[15]};
        a[13] = a[15];
        a[14] = a[27];
        a[15] = a[39];
        a[27] = a[38];
        a[39] = a[37];
        a[38] = a[25];
        a[37] = tmp2[0];
        a[25] = tmp2[1];

        return;
    }
}

// Main here
int main() {
    memset(sieve, true, sizeof(sieve));

    for (int p = 2; p * p < maxn2; p++)
        if (sieve[p])
            for (int i = p * 2; i < maxn2; i += p)
                sieve[i] = false;

    fora(i, 1, 55)a[i] = i;

    fora(i, 1, 101) {
        int tmp = divCount(i);
        turn(0, tmp % 3);

    }


    int ans = 0;

    fora(i, 1, 55) {
        ans = add(ans, pwr(i - a[i], 4));
    }

    cout << ans << "\n";
}
