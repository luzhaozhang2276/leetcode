#include <bits/stdc++.h>
using namespace std;

#if 0
/// 位运算 : 与 + 异或
class Solution {
public:
    int add(int a, int b) {
        // 此处是将 a + b 转换成了 n + c ,并进行下一次调用(循环)
        while (b != 0) {    // 当进位为 0 时,跳出循环
            int c = unsigned(a & b) << 1;   // c = 进位   (C++ 负数不支持移位操作,不正确)
            a ^= b;         // a = 非进位和
            b = c;          // b = 进位
        }
        return a;
    }
};

#elif 1
/// 递归
class Solution {
public:
    int add(int a, int b) {
        // a(非进位和),b(进位和)
        // b == 0 即当前进位和为0,退出循环
        // 新的循环: a = a^b, b = unsigned(a & b) << 1
        return b == 0 ? a : add(a^b, unsigned(a & b) << 1);
    }
};

#endif


int main() {
    Solution solve;
    cout << "-1 + 2 = " << solve.add(-1, 2) << endl;

    cout << "\nFinish";
    return 0;
}