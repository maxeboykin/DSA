#include <iostream>
#include <vector>
#include <stack>

class NextGreaterElement{
public:
    static std::vector<int> nextGreaterElement(std::vector<int>&nums1, std::vector<int>&nums2) {
        std::stack<int> stack;
        std::unordered_map<int, int>map;
        std::vector<int>ans;

        for(int &num : nums2){
            while(!stack.empty() && stack.top() < num){ // decreasing monotonic stack (draw it out to conceptualize!)
                map[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }

        for(int &num : nums1){
            if(map.count(num) > 0){
                ans.push_back(map[num]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }

    std::vector<int> calculateTime(std::vector<int> &nums1, std::vector<int> &nums2){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<int>result = nextGreaterElement(nums1, nums2);
        end = clock();
        printf("Next Greater Element: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    void printExpectations(std::vector<int> expected, std::vector<int> actual){
        std::cout << "Next Greater Element: ";
        std::cout << "Expected: " << std::endl;
        printVector(expected);
        std::cout << "Actual: " << std::endl;
        printVector(actual);
    }
    void printVector(std::vector<int> arr){
        for(auto& val: arr){
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    NextGreaterElement solution;
    std::vector<int> nums1_1 = {4,2,6};
    std::vector<int> nums1_2 = {6,2,4,5,3,7};
    std::vector<int> expected1 = {5,4,7};
    std::vector<int> actual = solution.calculateTime(nums1_1, nums1_2);
    solution.printExpectations(expected1, actual);

    std::vector<int> nums2_1 = {9,7,1};
    std::vector<int> nums2_2 = {1,7,9,5,4,3};
    std::vector<int> expected2 = {-1,9,7};
    std::vector<int> actual2 = solution.calculateTime(nums2_1, nums2_2);
    solution.printExpectations(expected2, actual2);


    std::vector<int> nums3_1 = {5,12,3};
    std::vector<int> nums3_2 = {12,3,5,4,10,15};
    std::vector<int> expected3 = {10,15,5};
    std::vector<int> actual3 = solution.calculateTime(nums3_1, nums3_2);
    solution.printExpectations(expected3, actual3);

}
