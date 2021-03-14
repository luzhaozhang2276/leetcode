#include <bits/stdc++.h>
using namespace std;

/// 6. Z 字形变换

#if 0
/// 模拟分行
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;

        vector<string> str(numRows);
        int flag = 1, i = 0;
        for (char c : s) {
            str[i] += c;
            i += flag;
            if (i == (numRows - 1) || i == 0)
                flag = -flag;
        }

        string res;
        for (string p : str)
            res += p;

        return res;
    }
};

#elif 1
/// 按行访问 (数学规律)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string res;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < n; j += cycleLen) {
                res += s[j+i];
                if (i != 0 && i != numRows-1 && j + cycleLen - i < n)
                    res += s[j + cycleLen - i];
            }
        }

        return res;
    }
};

#endif

int main() {
    Solution solve;
    cout << "str = " << solve.convert("PAY", 4) << endl;

    cout << "\nFinish";
    return 0;
}