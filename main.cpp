#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        str.erase(0, str.find_first_not_of(' '));
        if (str.empty())
            return 0;

        int i = 1, sign = 1;
        if (str[0] == '-')
            sign = -1;
        else if (str[0] != '+')
            i = 0;

        int res = 0, boundary = INT_MAX / 10;
        for (int j = i; j < str.length(); ++j) {
            if (str[j] < '0' || str[j] > '9')
                break;

            if (res > boundary || res == boundary && str[j] > '7')
                return sign == 1 ? INT_MAX : INT_MIN;

            res = 10 * res + (str[j] - '0');
        }

        return sign * res;
    }
};


int main() {
    string str = "  -42c";

    Solution solve;
    cout << "res = " << solve.strToInt(str) << endl;

    cout << "\nFinish";
    return 0;
}