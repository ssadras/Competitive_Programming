/*
 * author: Seyed Sadra Setarehdan
 * Problem: 900c Remove Extra One
 * Date: 12/4/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
ll n; ll a[maxn], b[maxn], c[maxn];
vector<ll> arr;
set<ll> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        while (!arr.empty()) {
            if (a[arr.back()] < a[i])
                arr.pop_back();
            else
                break;
        }

        if (arr.empty())
            b[i] = 0;

        else {
            b[i] = arr.back();
            auto it = st.end();

            if ((int)st.size() >= 2) {
                it--;
                it--;
                if (*it < a[i])
                    c[arr.back()]++;

            } else
                c[arr.back()]++;
        }
        arr.push_back(i);
        st.insert(a[i]);
    }

    ll mark = 1, maxx = c[1] - (b[1] == 0);
    bool bb = true;

    for (int i = 1; i <= n; i++) {
        if (bb and a[i] > a[i + 1])
            bb = false;

        if (!bb or i == n) {
            if (c[i] - (b[i] == 0) > maxx) {
                mark = i;
                maxx = c[i] - (b[i] == 0);
            } else if (c[i] - (b[i] == 0) == maxx and a[i] < a[mark]) {
                mark = i;
                maxx = c[i] - (b[i] == 0);
            }
        }
    }

    cout << a[mark]<<"\n";
    return 0;
}