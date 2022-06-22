/*
 * author: Seyed Sadra Setarehdan
 * Problem: 1153c Serval and Parenthesis Sequence
 * Date: 12/11/2020
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int c, t, a;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> s;
    for (char i : s)
        if (i == '(')
            t++;

    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] == '?') {
            if (2 * t < c) {
                s[i] = '(';
                t++;
            } else
                s[i] = ')';
        }
        if (s[i] == '(')
            a++;
        if ((2 * a < i + 1) or (i == c - 1 && 2 * a != i + 1) or (i != c - 1 && 2 * a == i + 1)) {
            cout<<":(\n";
            return 0;
        }
    }

    cout << s << '\n';
    return 0;
}