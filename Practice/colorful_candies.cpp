#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#define ll long long
#define int long long
using namespace std;

// Utility function to print the subarray formed by `A[i, j]`
void printSubarray(int A[], int i, int j, int n) {
    if (i < 0 || i > j || j >= n) {  // invalid input
        return;
    }

    for (int index = i; index < j; index++) {
        cout << A[index] << ", ";
    }

    cout << A[j] << endl;
}

// Function to print all subarrays having distinct elements
void calculate(int A[], int n) {
    // create a map to mark elements as visited in the current window
    unordered_map<int, bool> visited;

    // points to the left and right boundary of the current window;
    // i.e., the current window is formed by `A[left, right]`
    int right = 0, left = 0;

    // loop until the right index of the current window is less
    ll ans = LLONG_MIN;
    // than the maximum index
    while (right < n) {
        // keep increasing the window size if all elements in the
        // current window are distinct
        while (right < n && !visited[A[right]]) {
            visited[A[right]] = true;
            right++;
        }

        printSubarray(A, left, right - 1, n);

        // As soon as a duplicate is found (`A[right]`),
        // terminate the above loop, and reduce the window's size
        // from its left to remove the duplicate
        while (right < n && visited[A[right]]) {
            visited[A[left]] = false;
            left++;
        }
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll c[n];
    for (int i = 0; i < n; i++) cin >> c[i];

    calculate(c, n);

    return 0;
}