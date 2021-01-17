#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    public:
        Solution() {}
        virtual ~Solution() {}

        void showAll(vector<int>& nums, int target);
};

void Solution::showAll(vector<int>& nums, int target)
{
    map<int, int> m;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        if (m.count(target-nums[i]) > 0) {
            cout << "(" << target-nums[i] << "," << nums[i] << ")" << endl;
        } else {
            m[nums[i]] = i;
        }
    }
}

int main(int argc, char** argv)
{
    Solution s;
    vector<int> v = {1,2,3,3,4,5};
    s.showAll(v, 6);

    return 0;
}
