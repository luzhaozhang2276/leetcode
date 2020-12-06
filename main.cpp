#include <bits/stdc++.h>
using namespace std;

#if 0
/// 简单解法(不考虑大数问题)
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        int number = pow(10,n);
        for (int i = 1; i < number; ++i)
            res.push_back(i);

        return res;
    }
};

#elif 0
/// 考虑大数问题,char模拟加法运算(不使用递归)
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n <= 0)
            return res;
        char* number = new char[n+1];
        memset(number, '0', n);
        number[n] = '\0';

        while (!Increment(number))
            Save(number);

        delete []number;
        return res;
    }

    bool Increment(char *number) {
        bool isOverflow = false;    // 越界
        int nTakeOver = 0;      // 进位
        int nLength = strlen(number);

        for (int i = nLength - 1; i >= 0; --i) {
            int nSum = number[i] - '0' + nTakeOver;

            if (i == nLength - 1)
                nSum++;

            if (nSum >= 10) {
                if (i == 0)
                    isOverflow = true;
                else {
                    nSum -= 10;
                    nTakeOver = 1;
                    number[i] = '0' + nSum;
                }
            }
            else {
                number[i] = '0' + nSum;
                break;
            }
        }

        return isOverflow;
    }

    void Save(char *number) {
        string s = "";
        bool isBeginning0 = true;
        int nLength = strlen(number);
        for (int i = 0; i < nLength; ++i)
        {
            if (isBeginning0 && number[i] != '0')
                isBeginning0 = false;
            if (!isBeginning0)
                s += number[i];
        }

        int num = stoi(s);
        res.push_back(num);
    }
};

#elif 1
/// 全排列问题 (递归)
class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n <= 0)
            return res;
        char* number = new char[n+1];
        memset(number, '0', n);
        number[n] = '\0';

        for (size_t i = 0; i < 10; ++i)
        {
            number[0] = i + '0';
            ComputeRecursion(number, n, 0);
        }

        delete []number;
        return res;
    }

    void ComputeRecursion(char* number, int length, int index)
    {
        if (index == length -1)
        {
            Save(number);
            return;
        }

        for (size_t i = 0; i < 10; ++i)
        {
            number[index+1] = i + '0';
            ComputeRecursion(number, length, index+1);
        }
    }

    void Save(char *number) {
        string s = "";
        bool isBeginning0 = true;
        int nLength = strlen(number);
        for (int i = 0; i < nLength; ++i)
        {
            if (isBeginning0 && number[i] != '0')
                isBeginning0 = false;
            if (!isBeginning0)
                s += number[i];
        }

        if (!isBeginning0)
        {
            int num = stoi(s);
            res.push_back(num);
        }
    }
};

#endif



int main() {
    Solution s;
    cout << "print:" << endl;
    for (const auto &p:s.printNumbers(2))
        cout << p << endl;

    cout << "\nFinish" << endl;
    return 0;
}
