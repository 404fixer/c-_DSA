#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<pair<string, string>> chef_country;

    for (int i = 0; i < n; i++)
    {
        string chef, country;
        cin >> chef >> country;

        chef_country.push(make_pair(chef, country));
    }

    priority_queue<string> emails;
    for (int i = 0; i < m; i++)
    {
        string email;
        cin >> email;
        emails.push(email);
    }

    map<string, int> chef_votes; //map to store votes of individual chef

    for (int i = 0; i < m; i++)
    {
        chef_votes[emails.top()]++;
        emails.pop();
    }

    pair<string, int> winner_chef("", -1);
    for (auto itr = chef_votes.begin(); itr != chef_votes.end(); itr++)
    {
        if (itr->second > winner_chef.second)
        {
            winner_chef = make_pair(itr->first, itr->second);
        }
    }

    map<string, int> country_votes;
    for (int i = 0; i < n; i++)
    {
        if (chef_country.top().first == chef_votes.find(chef_country.top().first)->first)
            country_votes[chef_country.top().second] += chef_votes.find(chef_country.top().first)->second;
        chef_country.pop();
    }

    pair<string, int> winner_country("", -1);
    for (auto itr = country_votes.begin(); itr != country_votes.end(); itr++)
    {
        if (itr->second > winner_country.second)
            winner_country = make_pair(itr->first, itr->second);
    }

    cout << winner_country.first << endl
         << winner_chef.first << endl;
}