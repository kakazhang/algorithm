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
        int slidewindow(string s);
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

int Solution::slidewindow(string s)
{
    int left = 0, right = -1;
    int m = 0;
    int len = s.size();
    unordered_set<int> strs;

    for (; left < len; left++) {
        if (left != 0)
            strs.erase(s[left]);

        while (right+1<len && !strs.count(s[right+1])) {
            strs.insert(s[right+1]);
            right++;
        }
        m = max(m, right-left+1);
    }
    return m;
}

int main(int argc, char** argv)
{
    string str = "hello,world";
    string window = "abcdcabdaabbc";

    Solution s;
    cout << "longest substring:" << s.longestSubstring(str) << endl;

    cout << "max window size:" << s.slidewindow(window) << endl;
    return 0;
}
