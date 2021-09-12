#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int act;
        string origin;

        cin >> act >> origin;

        string activity[act];

        cin.ignore();
        for (int i = 0; i < act; i++)
        {
            getline(cin, activity[i]);
        }

        int laddus = 0;
        for (int i = 0; i < act; i++)
        {
            if (activity[i][8] == 'W')
            {
                int length = activity[i].length();
                string rank = activity[i].substr(12, length - 1);
                int rankNum = stoi(rank);
                laddus += rankNum <= 20 ? (300 + (20 - rankNum)) : 300;
            }
            else if (activity[i] == "TOP_CONTRIBUTOR")
            {
                laddus += 300;
            }
            else if (activity[i][0] == 'B')
            {
                string severityString = activity[i].substr(10, activity[i].length() - 1);
                int severity = stoi(severityString);
                laddus += severity;
            }
            else
            {
                laddus += 50;
            }
        }

        int maxMonth = origin == "INDIAN" ? laddus / 200 : laddus / 400;
        cout << maxMonth << "\n";
    }
}