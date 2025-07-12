#include <iostream>
#include <string>
using namespace std;

string timeConversion(string s)
{

    string hour = s.substr(0, 2);
    string rest = s.substr(2, 6);
    string period = s.substr(8, 2);

    int hr = stoi(hour);

    if (period == "AM")
    {
        if (hr == 12)
            hr = 0;
    }
    else
    {
        if (hr != 12)
            hr += 12;
    }

    string newHour = (hr < 10) ? "0" + to_string(hr) : to_string(hr);
    s = newHour + rest;
    return s;
}
int main()
{
    std::cout << timeConversion("07:05:45PM");
    return 0;
}