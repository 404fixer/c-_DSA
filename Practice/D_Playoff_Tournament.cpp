/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        int k;
        cin >> k;
        string str;
        cin >> str;
        int q;
        cin >> q;

        // length of string i.e the number of games 2^k-1
        int n = (1 << k) - 1;
        // total number of nodes in our binary tree
        // n nodes of games + leaf nodes which consists of team numbers
        int tot = n + (1 << k);

        pair<int, char> count[tot + 1];

        // set leaf nodes as one as it only consists of team names
        rep(i, n + 1, tot + 1) { count[i].fr = 1; }

        // now update the game nodes, i.e non leaf nodes
        int in = 0;
        for (int i = k - 1; i >= 0; i--) {
            // iterating on each level
            int it = (1 << i);
            int st = (1 << i);
            while (it--) {
                if (str[in] == '1') {
                    count[st].first = count[2 * st + 1].first;
                } else if (str[in] == '0') {
                    count[st].first = count[2 * st].first;
                } else {
                    count[st].first =
                        count[2 * st + 1].first + count[2 * st].first;
                }
                count[st].second = str[in];
                in++;
                st++;
            }
        }

        // query
        while (q--) {
            int p;
            char c;
            // position and character
            // s[p]=c;
            cin >> p >> c;
            // find p(in string s) position in tree
            int treeindex;
            for (int i = k - 1; i >= 0; i--) {
                if (p <= (1 << i)) {
                    treeindex = (1 << i) + p - 1;
                    break;
                } else {
                    p -= (1 << i);
                }
            }

            // update character
            count[treeindex].second = c;
            // treeindex=treeindex/2;

            // update path containing treeindex node
            while (treeindex) {
                if (count[treeindex].second == '1') {
                    count[treeindex].first = count[2 * treeindex + 1].first;
                } else if (count[treeindex].second == '0') {
                    count[treeindex].first = count[2 * treeindex].first;
                } else {
                    count[treeindex].first = count[2 * treeindex + 1].first +
                                             count[2 * treeindex].first;
                    ;
                }
                treeindex /= 2;
            }
            // print number of possible winners i.e, int value in root
            cout << count[1].first << endl;
            // return;
        }
    }
}