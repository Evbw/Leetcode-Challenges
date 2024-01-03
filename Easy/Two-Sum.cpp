#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // Map to store the difference and its index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {}; // Return empty vector if no solution is found
    }
};

void printVector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    printVector(solution.twoSum(nums, target));

    vector<int> nums2 = {3, 2, 4};
    target = 6;
    printVector(solution.twoSum(nums2, target));

    vector<int> nums3 = {3, 3};
    target = 6;
    printVector(solution.twoSum(nums3, target));
}