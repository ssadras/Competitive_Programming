/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1000d Yet Another Problem On a Subsequence
 * Date: 11-12-2020
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
#define GraphM1(g, n) g[n][n]
#define GraphM2(g, n) vi g[n]

// Const variables here
const int maxn = 1009;
const int MOD = 998244353;

// Global variables here
int n;
int a[maxn], dp[maxn], C[maxn][maxn];

// Functions here


// Main here
int main() {
    IOS

    for0(i, maxn) {
        C[i][0] = C[i][i] = 1;
        fora(j, 1, i)C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }

    cin >> n;
    for0(i, n)cin >> a[i];

    dp[n] = 1;
    rof0(i,n-1){
        if (a[i] <= 0)
            continue;

        fora(j,i+a[i],n+1)
            dp[i] = (dp[i] + (dp[j] * 1LL * C[j - i - 1][a[i]]) % MOD) % MOD;

    }

    int sum = 0;
    for0(i,n)
        sum = (sum + dp[i]) % MOD;

    cout << sum << "\n";

    return 0;
}