#include <bits/stdc++.h>
using namespace std;

/// 12. 整数转罗马数字

#if 0
// 逐位判断 1
class Solution {
public:
    string intToRoman(int num) {
        string res;
        char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int i = 6;
        int div = 1000;
        while (num != 0) {
            int tmp = num / div;
            num %= div;

            if (tmp < 4) {              // 1 2 3
                for (int j = 0; j < tmp; ++j)
                    res += symbols[i];
            } else if (tmp == 4) {      // 4
                res += symbols[i];
                res += symbols[i+1];
            } else if (tmp < 9) {       // 5 6 7 8
                res += symbols[i+1];
                for (int j = 0; j < tmp-5; ++j)
                    res += symbols[i];
            } else {                    // 9
                res += symbols[i];
                res += symbols[i+2];
            }

            i -= 2;
            div /= 10;
        }

        return res;
    }
};

#elif 1
class Solution {
public:
    string intToRoman(int num) {

        return intToRomanOneBit(num/1000, 'M', 0, 0)                // 千位
             + intToRomanOneBit((num%1000)/100, 'C', 'D', 'M')      // 百位
             + intToRomanOneBit((num%100)/10, 'X', 'L', 'C')        // 十位
             + intToRomanOneBit(num%10, 'I', 'V', 'X');             // 个位
    }
private:
    string intToRomanOneBit(int num, char one, char five, char ten){
        if(num <=3){
            return string(num, one);
        }
        if(num == 4){
            return string("") + one + five;
        }
        if(num <= 8){
            return string("") + five + string(num-5, one);
        }
         return string("") + one + ten;
    }
};
#elif 1
/// 贪心算法
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string res;
        for (int i = 0; i < values.size() && num >= 0; ++i) {
            while (values[i] <= num) {
                num -= values[i];
                res += symbols[i];
            }
        }

        return res;
    }

};

#endif

int main() {
    Solution solve;
    cout << "res = " << solve.intToRoman(1993) << endl;

    cout << "\nFinish";
    return 0;
}