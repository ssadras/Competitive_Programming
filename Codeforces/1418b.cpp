/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1418b Negative Prefixes
 * Date: 11-7-2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3 * 1e5 + 10;
int t, n, j;
int a[maxn], l[maxn];
vector<int> al;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        while (!al.empty())
            al.pop_back();

        for (int i = 0; i < n; i++) {
            cin >> l[i];
            if (l[i] == 0)
                al.push_back(a[i]);
        }

        sort(al.begin(), al.end(), greater<int>());

        j = 0;

        for (int i = 0; i < n; i++) {
            if (l[i] == 0) {
                cout << al[j] << ' ';
                j++;
            } else
                cout << a[i] << ' ';
        }
        cout << "\n";
    }


    return 0;
}
