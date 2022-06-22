/*
 * author: Seyed Sadra Setarehdan
 * Problem: Leaping Tak
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
const int maxn = 2e5 + 5;
const ll mod = 998244353;

// Global variables here
ll dp[maxn], sum[maxn];
int n, k;
int l[11], r[11];

// Functions here


// Main here
int main() {
    IOS

    cin >> n >> k;
    fora(i, 1, k + 1)cin >> l[i] >> r[i];

    dp[1] = 1;
    sum[1] = 1;
    fora(i, 2, n + 1) {
        fora(j, 1, k + 1) {
            dp[i] += (sum[max(0, i - l[j])] - sum[max(0, i - r[j] - 1)] + mod) % mod;
            dp[i] %= mod;
        }
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    cout << dp[n] << "\n";

    return 0;
}