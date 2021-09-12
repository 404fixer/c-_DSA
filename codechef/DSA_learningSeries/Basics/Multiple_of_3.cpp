// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Write C++ code here
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        long int k;
        int d0, d1;
        cin >> k;
        cin >> d0 >> d1;

        int i = 2;
        int arr[10];
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
        long int sum = d0 + d1;
        queue<int> v;
        int window = 0;
        while (true && ++i <= k)
        {
            if (arr[sum % 10] == 1)
            {
                // cout << "area " << i << " " << (sum % 10) << endl;
                // cout << v.front() << endl;
                while (v.front() != sum % 10)
                {
                    v.pop();
                }
                window = v.size();
                break;
            }
            arr[sum % 10]++;
            v.push(sum % 10);
            sum += (sum % 10);
            // cout << sum << " " << i << endl;
        }
        // cout << "window " << window << endl;

        if (i == k + 1)
        {
            // cout << sum << endl;
            if (sum % 3 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            long int sumOfwindow = 0;
            int initial = v.front();
            sumOfwindow += initial;
            v.pop();
            v.push(initial);
            while (v.front() != initial)
            {
                sumOfwindow += v.front();
                v.push(v.front());
                v.pop();
            }

            long int numOfwindows = (k - (i - 1)) / window;

            int leftover = (k - (i - 1)) % window;
            // cout << "leftover " << leftover << endl;
            int leftoverSum = 0;
            while (leftover != 0)
            {
                leftoverSum += v.front();
                v.pop();
                leftover--;
            }

            //sum = (initial sum + first window) + (num of windows * one window sum) + leftover of window (if any)
            // cout << "initial sum " << sum << endl;
            sum = sum + (numOfwindows * sumOfwindow) + leftoverSum;
            // cout << "here " << numOfwindows << " " << sumOfwindow << " " << leftoverSum << endl;
            // cout << sum << endl;
            if (sum % 3 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}