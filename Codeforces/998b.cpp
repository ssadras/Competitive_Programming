/*
 * author: Seyed Sadra Setarehdan
 * Problem: 998b Cutting
 * Date: 11-7-2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 110;
int n, b, a[maxn], c, temp, ans;
vector<int> v;

int abs(int a) {
    if (a < 0)
        return -a;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            c--;
        else
            c++;
        if (c == 0 and i < n - 1)
            v.push_back(abs(a[i + 1] - a[i]));
    }
    sort(v.begin(), v.end());
    while (b and temp < v.size()) {
        if (b - v[temp] >= 0)
            ans++;
        b -= v[temp];
        temp++;
    }
    cout << ans << '\n';
    return 0;
}