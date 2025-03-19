#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool srn(const pair<string, pair<double, pair<double, double>>> frst, const pair<string, pair<double, pair<double, double>>> scnd)
{
    double f = frst.second.first / frst.second.second.first;
    double s = scnd.second.first / scnd.second.second.first;
    return f > s;
}

vector<pair<string, int>> srt(vector<pair<string, pair<double, pair<double, double>>>> lst, double mxr, double mxb)
{
    vector<pair<string, int>> new_lst;
    double sm_r = 0.0;
    double sm_b = 0.0;
    sort(lst.begin(), lst.end(), srn);
    for (auto i : lst)
    {
        int srisk = (mxr - sm_r) / i.second.second.first;
        int sbudg = (mxb - sm_b) / i.second.second.second;
        int count_a = min(srisk, sbudg);
        if (count_a > 0)
        {
            new_lst.push_back({i.first, count_a});
            sm_r += count_a * i.second.second.first;
            sm_b += count_a * i.second.second.second;
        }
    }
    return new_lst;
}

int main()
{
    vector<pair<string, pair<double, pair<double, double>>>> lst;

    double mxr = 0.0;
    cout << "Enter max risk: ";
    cin >> mxr;
    double mxb = 0.0;
    cout << "Enter max budget: ";
    cin >> mxb;
    int n = 0;
    cout << "Enter a count: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        pair<string, pair<double, pair<double, double>>> ak;
        cout << "Enter name: ";
        cin >> ak.first;
        cout << "Enter income: ";
        cin >> ak.second.first;
        cout << "Enter risk: ";
        cin >> ak.second.second.first;
        cout << "Enter price: ";
        cin >> ak.second.second.second;
        cout << endl;
        lst.push_back(ak);
    }
    vector<pair<string, int>> res = srt(lst, mxr, mxb);

    cout << "\nSelected:\n";
    double tcost = 0.0;
    double trisk = 0.0;
    double tincome = 0.0;

    for (size_t i = 0; i < res.size(); i++)
    {
        string name = res[i].first;
        int s = res[i].second;

        auto inv = lst[i];
        for (const auto& item : lst)
        {
            if(item.first == name)
            {
                inv = item;
                break;
            }
        }

        double risk = s * inv.second.second.first;
        double cost = s * inv.second.second.second;
        double income = s * inv.second.first;

        cout << res[i].first << endl;
        cout << " Shares: " << s << endl;
        cout << " Cost: " << cost << endl;
        cout << " Income: " << income << endl;
        cout << " Risk: " << risk << endl;

        tcost += cost;
        trisk += risk;
        tincome += income;
    }

    cout << "\nPortfolio:\n";
    cout << "Total cost: " << tcost << endl;
    cout << "Total risk: " << trisk << endl;
    cout << "Expected income: " << tincome << endl;
}