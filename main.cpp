#include <bits/stdc++.h>
using namespace std;

vector<string> simpleSplit(const string &str, char a)
{
    std::vector<std::string> vec;
    std::stringstream ss;
    ss.str(str);
    std::string s;
    while (std::getline(ss, s, a))
    {
        vec.push_back(s);
    }
    return vec;
}

struct Code
{
    // string name;
    int degree;
    int time;
    vector<string> adj;
};

int course(vector<string> & data) {
    unordered_map<string, Code> hash;

    for (int i = 1; i < data.size(); ++i) {
        auto s = simpleSplit(data[i], ',');
        Code tar;
        tar.time = stoi(s[1]);
        tar.degree = s.size() - 2;
        hash[s[0]] = tar;
    }

    for (int i = 1; i < data.size(); ++i) {
        auto s = simpleSplit(data[i], ',');
        for (int j = 2; j < s.size(); ++j) {
            if (hash.find(s[j]) == hash.end())
                return -1;
            hash[s[j]].adj.emplace_back(s[0]);
        }
    }

    queue<string> Q;
    for (const auto &p : hash) {
        if (p.second.degree == 0)
            Q.emplace(p.first);
    }

    int res = 0;
    while (!Q.empty()) {
        int curr_size = Q.size();
        int curr_time = 0;
        for (int i = 0; i < curr_size; ++i) {
            string top = Q.front();
            curr_time = max(curr_time, hash[top].time);
            Q.pop();
            for (const auto &p : hash[top].adj) {
                hash[p].degree--;
                if (hash[p].degree == 0)
                    Q.emplace(p);
            }
        }
        res += curr_time;
        if (hash[data[0]].degree == 0)
            return res + hash[data[0]].time;
    }

    if (hash[data[0]].degree != 0)
        return -1;

    return res == 0 ? -1 : res;
}

int main() {

    vector<string> data;
    data.emplace_back("module3");
    data.emplace_back("module1,10");
//    data.emplace_back("module2,5,module1");
    data.emplace_back("module2,5");
    data.emplace_back("module3,10,module1,module2");
//    data.emplace_back("module4,10,module3");


    cout << course(data) << endl;

    return 0;
}