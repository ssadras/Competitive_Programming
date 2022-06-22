/*
 * author: Seyed Sadra Setarehdan
 * Problem: 616d Longest k-Good Segment
 * Date: 12/10/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


const ll maxn = 5e5 + 10;
ll n, k, a[maxn], cnt[1000010], sum, l, r, ansL, ansR;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];


    while (r < n) {
        if (sum > k) {
            l++;
            cnt[a[l]]--;

            if (cnt[a[l]] == 0)
                sum--;

        } else {
            r++;
            cnt[a[r]]++;

            if (cnt[a[r]] == 1)
                sum++;

            if (sum <= k and ansR - ansL < r - l) {
                ansR = r;
                ansL = l;
            }
        }
    }

    cout << ansL + 1 << ' ' << ansR<<"\n";

    return 0;
}
