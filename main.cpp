#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int numOfSpace = 0;
        for (int i=0; i<s.length(); ++i)
        {
            if(s[i] == ' ')
                ++numOfSpace;
        }
        cout << "num: " << numOfSpace << endl;
        int p1 = s.size();
        int newLength = s.length() + 2*numOfSpace;
        s.resize(newLength);
        while (p1>=0 && newLength>p1)
        {
            if(s[p1]==' ')
            {
                s[newLength--] = '0';
                s[newLength--] = '2';
                s[newLength--] = '%';
            } else
                s[newLength--] = s[p1];
            --p1;
        }

        return s;
    }
};

/**
 * @brief 注意知识点 string
 * 1. resize()
 * 2. reserve()
 * 3. capacity()
 * 4. size()
 * 5. length()
 */

//class Solution {
//public:
//    string replaceSpace(string s) {
//        int count = 0, len = s.size();
//        // 统计空格数量
//        for (char c : s) {
//            if (c == ' ') count++;
//        }
//        // 修改 s 长度
//        s.resize(len + 2 * count);
//        // 倒序遍历修改
//        for(int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
//            if (s[i] != ' ')
//                s[j] = s[i];
//            else {
//                s[j - 2] = '%';
//                s[j - 1] = '2';
//                s[j] = '0';
//                j -= 2;
//            }
//        }
//        return s;
//    }
//};


int main() {
    string str = "We are happy.";

    Solution s;
    cout << s.replaceSpace(str) << endl;

    cout << "\nFinish" << endl;
    return 0;
}
