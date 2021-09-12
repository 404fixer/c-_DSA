#include <bits/stdc++.h>
#include <stack>
using namespace std;

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix)
{

    stack<char> letters;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        if ((int)infix[i] >= 65 && (int)infix[i] <= 90)
        {
            postfix.push_back(infix[i]);
        }
        else
        {
            if (infix[i] == '(')
            {
                letters.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (letters.top() != '(' && !letters.empty())
                {
                    postfix.push_back(letters.top());
                    letters.pop();
                }
                if (letters.top() == '(')
                    letters.pop();
            }
            else
            {
                while (!letters.empty() && ((precedence(infix[i])) <= (precedence(letters.top()))) && letters.top() != '(')
                {
                    postfix.push_back(letters.top());
                    letters.pop();
                }
                letters.push(infix[i]);
            }
        }
    }

    while (!letters.empty())
    {
        postfix.push_back(letters.top());
        letters.pop();
    }

    return postfix;
}

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int n;
        cin >> n;

        string infix;
        cin >> infix;

        cout << infixToPostfix(infix) << endl;
    }
}