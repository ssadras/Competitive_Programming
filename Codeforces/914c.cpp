/*
 * author: Seyed Sadra Setarehdan
 * Problem: 914c Travelling Salesman and Special Numbers
 * Date: 12/24/2020
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
#define mp make_pair
#define F first
#define S second
#define T third
#define GraphM1(g, n) int (g)[(n)][(n)]
#define GraphM2(g, n) vi (g)[(n)]

// Const variables here
const int maxn = 1004;
const int MOD = 1e9 + 7;

// Global variables here
int dp[maxn];
int k;
string n;
ll a[maxn][maxn];
ll temp1, ans, cnt;

// Functions here
int ones(int x) {
    int temp = 0;

    while (x) {
        if (x % 2 == 1)
            temp++;
        x /= 2;
    }

    return temp;
}

void calcncr() {
    for0(i, maxn)a[i][0] = 1;

    fora(i, 1, maxn)fora(j, 1, maxn)a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % MOD;

}

// Main here
int main() {
    IOS

    calcncr();

    dp[1] = 0;
    fora(i, 2, maxn)dp[i] = dp[ones(i)] + 1;

    cin >> n >> k;

    if (k == 0) {
        cout << "1\n";
        return 0;
    }

    for0(i, (int) n.size()) {
        if (n[i] == '0')
            continue;

        fora(j, temp1, maxn)if (dp[j] == k - 1) {
                ans = (ans + a[n.size() - i - 1][j - temp1]) % MOD;
                if (i == 0 and k == 1)
                    ans = (ans + MOD - 1) % MOD;
            }

        temp1++;
    }

    for0(i, (int) n.size())
        if (n[i] == '1')
            cnt++;

    if (dp[cnt] == k - 1)
        ans = (ans + 1) % MOD;

    cout << ans << "\n";

    return 0;
}