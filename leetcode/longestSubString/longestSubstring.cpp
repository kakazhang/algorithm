#include <iostream>
#include <unordered_set>
#include <string>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

class Solution {
    public:
        Solution() {}
        virtual ~Solution() {}

        int longestSubstring(string s);
};

int Solution::longestSubstring(string s)
{
    int left = 0, len = s.size();
    unordered_set<int> a;
    int num = 0;

    if (s.size() == 0)
        return 0;

    for (int i = 0; i < len; i++) {
        while (a.find(s[i]) != a.end()) {
            a.erase(s[left]);
            left++;
        }

        num = max(num, i-left+1);
        a.insert(s[i]);
    }

    return num;
}

int main(int argc, char** argv)
{
    string str = "hello,world";

    Solution s;
    cout << "longest substring:" << s.longestSubstring(str) << endl;

    return 0;
}
