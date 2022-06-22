/*
 * author: Seyed Sadra Setarehdan
 * Problem: Knapsack 1
 * Date: 2/11/2021
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
const int maxn = 1e2 + 15;
const int maxw = 1e5 + 15;

// Global variables here
int a[maxn], b[maxn], w, n;
ll dp[maxw][maxn], ans;

// Functions here


// Main here
int main() {
    cin >> n >> w;
    fora(i, 1, n + 1)cin >> a[i] >> b[i];

    fora(i, 1, n + 1) {
        for0(j, w + 1) {
            if (a[i] > j)
                dp[j][i] = dp[j][i - 1];

            else if (a[i] == j) {
                dp[j][i] = max(dp[j][i - 1], dp[j - a[i]][i - 1] + b[i]);
                ans = max(ans, dp[j][i]);

            } else if (a[i] < j and dp[j - a[i]][i - 1]) {
                dp[j][i] = max(dp[j][i - 1], dp[j - a[i]][i - 1] + b[i]);
                ans = max(ans, dp[j][i]);

            } else
                dp[j][i] = dp[j][i - 1];

        }
    }

    cout << ans << "\n";

    return 0;
}