#include <iostream>

class CyclicSort {
public:
    int findMissingNumber(std::vector<int> &nums) {
        int i = 0;
        while(i < nums.size()){
            int j = nums[i];
            if(j < nums.size() && nums[i] != nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            } else {
                i++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i){
                return i;
            }
        }
        return nums.size();
    }
    int calculateTime(std::vector<int> &nums){
        clock_t start;
        clock_t end;
        start = clock();
        int result = findMissingNumber(nums);
        end = clock();
        printf("findMissingNumber: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(int expected, int actual){
        std::cout << "findMissingNumber: ";
        std::cout << "Expected: ";
        std:: cout << expected << std::endl;
        std::cout << "Actual: ";
        std:: cout << actual << std::endl;
    }
    void printVector(std::vector<int> arr){
        for(auto& val: arr){
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};


int main(){
    CyclicSort solution;
    std::vector<int> foo = {4, 0, 3, 1};
    std::vector<int> bar = {8, 3, 5, 2, 4, 6, 0, 1};
    int expected = 2;
    int expected2 = 7;
    int result = solution.findMissingNumber(foo);
    solution.printExpectations(expected, result);
    int result2 = solution.findMissingNumber(bar);
    solution.printExpectations(expected2, result2);
}