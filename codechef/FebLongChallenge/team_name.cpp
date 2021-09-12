#include <bits/stdc++.h>
#include <string>
using namespace std;

class Node
{
public:
    string str1;
    string str2;
    Node *next;
};

Node *head = NULL;

Node *getNewNode(string str1, string str2)
{
    Node *newNode = new Node();
    newNode->str1 = str1;
    newNode->str2 = str2;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    int T;
    cin >> T;

    for (int idx = 0; idx < T; idx++)
    {
        int N;
        cin >> N;

        string s[N];
        fflush(stdin);
        for (int j = 0; j < N; j++)
        {
            cin >> s[j];
        }

        Node *temp;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                string teamName[2];
                    teamName[0] = s[i][0] + s[j];
                    teamName[0].erase(1, 1);
                    teamName[1] = s[j][0] + s[i];
                    teamName[1].erase(1, 1);
                if (head == NULL)
                {
                    head = getNewNode(teamName[0], teamName[1]);
                    temp = head;
                }
                else
                {
                    temp->next = getNewNode(teamName[0], teamName[1]);
                    temp = temp->next;
                }
            }
        }

        temp = head;
        int count = 0, num = 0;
        while (temp != NULL)
        {
            for (int i = 0; i < N; i++)
            {
                if (temp->str1 == s[i] || temp->str2 == s[i])
                {
                    break;
                }
                else
                {
                    count++;
                }
            }
            if (count == N)
            {
                num++;
            }
            temp = temp->next;
        }

        cout<<num*2<<endl;

        // int count = 0;
        // string letters[N];

        // for (int j = 0; j < N; j++)
        // {
        //     letters[j] = s[j][0];
        // }

        // for (int j = 0; j < N; j++)
        // {
        //     for (int k = j + 1; k < N; k++)
        //     {
        //         bool isSameAtEnd;

        //         string temp1 = s[j];
        //         string temp2 = s[k];
        //         temp1.erase(0, 1);
        //         temp2.erase(0, 1);

        //         if (temp1.compare(temp2) == 0)
        //         {
        //             letters[j].push_back(s[k][0]);
        //             letters[k].push_back(s[j][0]);
        //             isSameAtEnd = 1;
        //         }
        //         else
        //         {
        //             isSameAtEnd = 0;
        //         }

        //         if (!(letters[j].find(s[k][0]) >= 0 && letters[j].find(s[k][0]) < letters[j].length()) && !isSameAtEnd)
        //         {
        //             // cout << i << " " << j << " " << k << endl;
        //             count++;
        //             // make new words
        //             string teamName[2];
        //             teamName[0] = s[k][0] + s[j];
        //             teamName[0].erase(1, 1);
        //             teamName[1] = s[j][0] + s[k];
        //             teamName[1].erase(1, 1);

        //             // cout << teamName[0] << " " << teamName[1] << "\n";

        //             for (int m = j + 1; m < N; m++)
        //             {
        //                 if (s[m].compare(teamName[0]) == 0)
        //                 {
        //                     // cout << i << " " << j << " " << k << endl;

        //                     letters[j].push_back(s[m][0]);
        //                     count--;
        //                     break;
        //                 }
        //                 else if (s[m].compare(teamName[1]) == 0)
        //                 {
        //                     // cout << i << " " << j << " " << k << endl;

        //                     letters[k].push_back(s[m][0]);
        //                     count--;
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }

        // // for (int j = 0; j < N; j++)
        // // {
        // //     cout << letters[j] << endl;
        // // }
        // cout << 2 * count << "\n";
    }
}