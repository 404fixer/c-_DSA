#include <bits/stdc++.h>
using namespace std;

string ok(string s, int k) {
    int n = s.size();
    string ans = "";
    for (int i = 0; i < k; i++) ans += (char)(s[(i % n)]);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(s.substr(0, i + 1));
    }
    for (int i = 0; i < n; i++) {
        ans[i] = ok(ans[i], k);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
}

int main() { solve(); }