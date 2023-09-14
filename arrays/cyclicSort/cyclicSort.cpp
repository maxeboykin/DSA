#include <iostream>

class CyclicSort {
public:
    std::vector<int> cyclicSort(std::vector<int> &nums) {
        int i = 0;
        while(i < nums.size()){
            int j = nums[i] - 1;
            if(nums[i] != nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            } else {
                i++;
            }
        }
        return nums;
    }
    std::vector<int> calculateTime(std::vector<int> &nums){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<int> result = cyclicSort(nums);
        end = clock();
        printf("Cyclic Sort: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(std::vector<int> expected, std::vector<int> actual){
        std::cout << "Reverse Sublist Linked List: ";
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
    CyclicSort solution;
    std::vector<int> foo = {3, 1, 5, 4, 2};
    std::vector<int> bar = {2, 6, 4, 3, 1, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {1, 2, 3, 4, 5, 6};
    std::vector<int> result = solution.cyclicSort(foo);
    solution.printExpectations(expected, result);
    std::vector<int> result2 = solution.cyclicSort(bar);
    solution.printExpectations(expected2, result2);
}