#include <bits/stdc++.h>
using namespace std;

#if 0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (n & 1)
                count++;
            n = n >> 1;
        }
        return count;
    }
};

#elif 0

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
                count++;
            flag = flag << 1;
        }
        return count;
    }
};

#elif 1

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n)
        {
            ++count;
            n = (n-1) & n;
        }
        return count;
    }
};

#endif

int main() {
    Solution s;
    uint32_t t = 00000000000000000000000000001011;
    cout << "counts: " << s.hammingWeight(t) << endl;


    cout << "\nFinish" << endl;
    return 0;
}
