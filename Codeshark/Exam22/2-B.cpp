// Created by:
// Radman Yaghubi
// Date: 6-22-2022

//                  //
//     Radmanã‚·     //
//                 //
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <fstream>
#include <assert.h>
#include <cmath>
#include <deque>
#include <bitset>

using namespace std;

//#define int long long
#define ld long double

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, int> ppi;
typedef pair<pii, pii> ppp;
#define F first
#define S second

#define _ios_ ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x,y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H) ;
    debug_out(T...);
}
#define debugn(...)  cerr << "(" << #__VA_ARGS__ << "): ", debug_out(__VA_ARGS__)

#define all(x) x.begin(), x.end()

const int MAXN = 1e6 + 5, INF = 1e9+10, MAXLG = 18;
const int DELTA = 10427;
int dp[1005][105][2], f[MAXN];

inline int add(int a, int b)
{
    int c = a + b;
    if (c >= DELTA)
        c -= DELTA;
    if (c < 0)
        c += DELTA;
    return c;
}

inline int mul(int a, int b)
{
    return (1ll * a * b) % DELTA;
}

int pwr(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int c = pwr(a, b / 2);
    c = mul(c, c);
    if (b & 1)
        c = mul(c, a);
    return c;
}

inline int inv(int a, int b)
{
    return mul(a, pwr(b, DELTA - 2));
}

inline int c(int n, int k)
{
    if (k > n)
        return 0;
    return inv(f[n], mul(f[k], f[n - k]));
}

int32_t main()
{
    _ios_
    int w = 100, n = 10;
    f[0] = 1;
    for (int i = 1; i <= w; i++)
        f[i] = mul(f[i - 1], i);
    dp[0][0][0] = 1;
    for (int i = 1; i <= w; i++)
    {
        dp[i][0][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            dp[i][j][0] = add(dp[i - 1][j][0], dp[i - 1][j][1]);
            for (int k = i-1; k >= 0; k--)
            {
                dp[i][j][1] = add(dp[i][j][1], dp[k][j - 1][0]);
                if (j > 1)
                    dp[i][j][1] = add(dp[i][j][1], mul(2, mul(c(i - k - 1, 2), dp[k][j - 2][0])));
            }
            //debugn(i, j, dp[i][j][0], dp[i][j][1]);
        }

    }
    cout << mul(add(dp[w][n][0], dp[w][n][1]), f[n]) << endl;
    return 0;
}
