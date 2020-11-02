#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;
        vector<int> b(2,-1);

        int i;
        for (i = 0; i < nums.size(); i++) {
            if (a.count(target-nums[i]) > 0) {
                b[0] = i;
                b[1] = a.count(target-nums[i]);
                break;
            }
            a[nums[i]] = i;
        }
        return b;
    }
};

int main() {
   Solution s;
   vector<int> a;
   int array[] = {2, 7, 9, 10};

   for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
       a[i] = array[i];

   vector<int> b = s.twoSum(a, 9);
   cout << "b[0]=" << b[0] << ", b[1] = " << b[1] << endl;

   return 0;
}
