/*
 * author: Seyed Sadra Setarehdan
 * Problem: 276c Little Girl and Maximum Sum
 * Date: 11-12-2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5+5;
ll n, q, l, r, a[maxn], part[maxn];
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < q; ++i) {
        cin>>l>>r;
        part[--l]++;
        part[r]--;
    }

    for (int i = 1; i < n; ++i) {
        part[i] += part[i-1];
    }

    sort(a,a+n);
    sort(part,part+n);

    for (int i = 0; i < n; ++i) {
        ans+=a[i]*part[i];
    }
    cout<<ans<<"\n";
    return 0;
}