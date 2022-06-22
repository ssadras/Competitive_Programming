/*
 * author: Seyed Sadra Setarehdan
 * Problem: 472c Design Tutorial: Make It Nondeterministic
 * Date: 11-12-2020
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int sz = 100010;
vector<pair<string, string>> v;
vector<int> p;
pair<string, string> temp;
int n,elm;
string s1,s2,t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        if (s1 > s2) {
            t = s1;
            s1 = s2;
            s2 = t;
        }
        temp.first = s1;
        temp.second = s2;
        v.push_back(temp);
    }

    bool ans = true;

    for (int i = 0; i < n; ++i) {
        cin >> elm;
        p.push_back(elm - 1);
    }

    int idx = p[0];
    string prev = v[idx].first;

    for (int i = 1; i < n; ++i) {
        idx = p[i];
        if (prev > v[idx].first and prev > v[idx].second) {
            ans = 0;
            break;
        }

        if (prev > v[idx].first)
            prev = v[idx].second;
        else
            prev = v[idx].first;
    }

    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}