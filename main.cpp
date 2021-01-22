#include <bits/stdc++.h>
using namespace std;

// set
// unordered_map

// string
// char*
// char[]

class Solution {
public:
    vector<string> res;
    char* c;
    vector<string> permutation(string s) {
        c = const_cast<char *>(s.c_str());
        recur(0);
        return res;
    }

    void recur(int x)
    {
        if (c[x] == '\0') {
            res.emplace_back(c);
            return;
        }

        set<char> chars;
        int i = x;
        while (c[i] != '\0')
        {
            if (chars.find(c[i]) != chars.end())
            {
                i++;
                continue;
            }

            chars.insert(c[i]);
            swap(i,x);
            recur(x+1);
            swap(x,i);
            i++;
        }
    }

    void swap(int a, int b)
    {
        char tmp = c[a];
        c[a] = c[b];
        c[b] = tmp;
    }
};

int main() {
    string s = "abb";

    Solution solve;
    vector<string> res = solve.permutation(s);

    for (auto &p:res)
        cout << p << endl;

    cout << "\nFinish";
    return 0;
}
