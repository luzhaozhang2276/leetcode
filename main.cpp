#include <bits/stdc++.h>
using namespace std;

#if 1
/// leetcode
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long start = 1, count = 9;
        while (n > count) {     // 确定位数 digit, 起始位 start
            n -= count;
            digit++;
            start *= 10;
            count = digit * start * 9;
        }
        long num = start + (n - 1) / digit;     // 确定数字 num
        string number = to_string(num);
        return number[(n - 1)%digit] - '0';     // num 中的哪一位
    }
};
#elif 1
/// 自己
class Solution {
public:
    int findNthDigit(long int n) {
        if (n < 10)
            return n;

        n++;
        long int sum = 10;
        long int digit = 1, base = 9;
        while (n > sum) {
            digit++;
            base *= 10;
            sum += base * digit;
        }
        int offset = n - (sum - base * digit);
        int num = offset / digit + pow(10,digit-1);
        num = (offset % digit == 0) ? num - 1 : num;
        //cout << num << endl;

        int tmp = num / pow(10, digit - offset % digit);
        return (offset % digit == 0) ? num%10 : tmp%10;
    }
};
#endif

int main() {
    Solution solve;
    cout << solve.findNthDigit(200) << endl;

//    int num = 12345;
//    int s = 5;
//    int res = num / pow(10, 5 - s);
//    cout << res%10 << endl;
//    while (num % 10)
//    {
//        cout << num%10 << " ";
//        num /= 10;
//    }

    cout << "\nFinish";
    return 0;
}
