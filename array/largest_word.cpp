// largest word in a sentence

#include <iostream>
using namespace std;

int main()
{
    char sentence[500];
    cin.getline(sentence, 500);
    cin.ignore();

    int temp = 0, length = 0, initial = 0;

    for (int i = 0; i < 500; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {
            if (temp > length)
            {
                length = temp;
                initial = i - length;
            }
            // cout << temp << '\t' << i << '\t';
            temp = 0;
        }
        else
        {
            temp++;
        }
        if (sentence[i] == '\0')
        {
            break;
        }
    }

    // cout << temp << endl
    //      << length << endl
    //      << initial << endl;

    for (int i = initial; sentence[i] != ' ' && sentence[i] != '\0'; i++)
    {
        cout << sentence[i];
    }

    cout << endl;
}