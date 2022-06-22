/*
 * author: Seyed Sadra Setarehdan
 * Problem: 891b Gluttony
 * Date: 11-12-2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 23;
int n, ans[maxn];
pair<int ,int> a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        ans[a[(i+1)%n].second] = a[i].first;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << "\n";

    return 0;
}