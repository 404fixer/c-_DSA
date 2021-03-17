// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


 // } Driver Code Ends
// The main function to convert infix expression
//to postfix expression

int prec(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

    string infixToPrefix(string s)
    {
        // Your code here
        stack <char> operators;
        string prefix = "";
        
        for(int i=(s.length()-1); i>=0; i--) {
            if((s[i] >= 'a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
                prefix.push_back(s[i]);
            } else {
                if(operators.empty()) operators.push(s[i]);
                else if(prec(s[i]) > prec(operators.top())) operators.push(s[i]);
                else {
                    if(s[i] == ')') operators.push(s[i]);
                    else if(s[i] == '('){
                        while(operators.top() != ')'){
                        prefix.push_back(operators.top());
                        operators.pop();
                        }
                        operators.pop();
                    } else {
                        while(!operators.empty()) {
                            if(operators.top() == ')') break;
                            prefix.push_back(operators.top());
                            operators.pop();
                        }
                        operators.push(s[i]);
                    }
                }
            }
        }
        
        while(!operators.empty()) {
            prefix.push_back(operators.top());
            operators.pop();
        }
        
        reverse(prefix.begin(), prefix.end());

        return prefix;
    }


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    string infix;
    cin>>infix;

    cout<<infixToPrefix(infix)<<endl;
    return 0;
}
  // } Driver Code Ends