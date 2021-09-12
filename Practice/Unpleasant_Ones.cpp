#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

// Function to convert a decimal mumber
// to its binary form
string decimalToBinary(ll n) {
    // finding the binary form of the number and
    // coneverting it to string.
    string s = bitset<64>(n).to_string();

    // Finding the first occurance of "1"
    // to strip off the leading zeroes.
    const auto loc1 = s.find('1');

    if (loc1 != string::npos) return s.substr(loc1);

    return "0";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            string str = decimalToBinary(arr[i]);

            if (str[str.length() - 1] == '1') {
                swap(arr[i], arr[n - 1]);
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}