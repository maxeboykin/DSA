#include <iostream>
#include <vector>
#include <string>

using namespace std;
class ProductOfArrayExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> prefix(nums.size());
       vector<int> postfix(nums.size());
       int accum = 1;
       for(auto iter = nums.begin(); iter < nums.end(); iter++){
           int index = distance(nums.begin(), iter);
           accum *= *iter;
           prefix[index] = accum;
       }
       accum = 1;
       for(auto iter = nums.end()-1; iter >= nums.begin(); iter--){
           int index = distance(nums.begin(), iter);
           accum *= *iter;
           postfix[index] = accum;
       }
       for(auto iter = nums.begin(); iter < nums.end(); iter++){
           int index = distance(nums.begin(), iter);
           if(index == 0 || index == nums.size() -1){
               if(index == 0) *iter = postfix[index+1];
               if(index == nums.size() -1) *iter = prefix[index-1];
           } else {
               *iter = prefix[index - 1] * postfix[index+1];
           }
       }
       return nums;
    }
};

int main(){
    ProductOfArrayExceptSelf solution;
    vector<int> foo{1,2,3,4};
    vector<int> expectedOutput = {24, 12, 8, 6};
    vector<int> result = solution.productExceptSelf(foo);
    vector<int> bar{-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(bar);
    vector<int> expectedOutput2 = {0, 0, 9, 0, 0};
    cout << "productExceptSelf : ";
    int idx = 0;
    for(const auto& value: result){
        cout << "Expected value: " << expectedOutput[idx] << " actual val: " << value << endl;
        idx++;
    }
    idx = 0;
    for(const auto& value: result2){
        cout << "Expected value: " << expectedOutput2[idx] << " actual val: " << value << endl;
        idx++;
    }
}