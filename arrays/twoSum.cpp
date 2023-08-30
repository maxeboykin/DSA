#include <iostream>
#include <vector>
#include <string>

using namespace std;
class TwoSum {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(numMap.count(complement)) {
                return vector<int>{numMap[complement], i };
            }
            numMap[nums[i]] = i;
        }
        return {};  // no solution found
    }
};

int main(){
    TwoSum solution;
    vector<int> foo{2, 7, 11, 15 };
    vector<int> result = solution.twoSum(foo, 9);
    cout << "twoSum indices: ";
    for(const auto& element: result) {
        cout << element << " ";
    }
    cout << endl;
}