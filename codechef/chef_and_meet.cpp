#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int convertInMin(string str, string timeZone)
{
    int hrs = (10 * (str[0] - '0')) + (str[1] - '0');
    int min = (10 * (str[3] - '0')) + (str[4] - '0');

    if (hrs == 12)
    {
        if (timeZone[0] == 'A')
        {
            return (min);
        }
        else
        {
            return (720 + min);
        }
    }
    else
    {
        if (timeZone[0] == 'A')
        {
            return ((hrs * 60) + min);
        }
        else
        {
            return (720 + (hrs * 60) + min);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int idx = 0; idx < T; idx++)
    {
        string meetTime[2];
        int meetTimeInMin;
        for (int i = 0; i < 2; i++)
        {
            cin >> meetTime[i];
        }
        meetTimeInMin = convertInMin(meetTime[0], meetTime[1]);

        int N;
        cin >> N;

        string time[N * 4];
        int timeInMin[2 * N];
        int count = 0;
        for (int i = 0; i < (N * 4); i++)
        {
            cin >> time[i];
            if (i % 2 == 1)
            {
                timeInMin[count] = convertInMin(time[i - 1], time[i]);
                count++;
            }
        }

        string ans = "";
        for (int i = 0; i < (N * 2); i += 2)
        {
            if (meetTimeInMin >= timeInMin[i] && meetTimeInMin <= timeInMin[i + 1])
            {
                ans.push_back('1');
            }
            else
            {
                ans.push_back('0');
            }
        }

        cout << ans << endl;
    }
}