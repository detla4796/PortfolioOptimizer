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

vector<string> srt(vector<pair<string, pair<double, pair<double, double>>>> lst, double mxr, double mxb)
{
    vector<string> new_lst;
    double sm_r = 0.0;
    double sm_b = 0.0;
    sort(lst.begin(), lst.end(), srn);
    for (auto i : lst)
    {
        if (sm_r + i.second.second.first <= mxr && sm_b + i.second.second.second <= mxb)
        {
            new_lst.push_back(i.first);
            sm_r += i.second.second.first;
            sm_b += i.second.second.second;
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
    vector<string> res = srt(lst, mxr, mxb);

    cout << "\nSelected:\n";
    for (auto i : res)
    {
        cout << i << endl;
    }
}