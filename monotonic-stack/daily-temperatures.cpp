#include <iostream>
#include <vector>
#include <stack>

class DailyTemperatures{
public:
    static std::vector<int> dailyTemperatures(std::vector<int>&temperatures){
        std::stack<int> stack;
        std::unordered_map<int, int>map;
        std::vector<int>ans(temperatures.size());
        int idx = 0;
        for(int temp: temperatures) {
            while(!stack.empty() && temp > temperatures[stack.top()]){
                ans[stack.top()] = idx - stack.top();
                stack.pop();
            }
            stack.push(idx);
            idx++;
        }
        return ans;
    }

    std::vector<int> calculateTime(std::vector<int> &temperatures){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<int>result = dailyTemperatures(temperatures);
        end = clock();
        printf("Daily Temperatures: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    void printExpectations(std::vector<int> expected, std::vector<int> actual){
        std::cout << "Daily Temperatures: ";
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
    DailyTemperatures solution;
    std::vector<int> temperatures = {70,73,75,71,69,72,76,73};
    std::vector<int> expected = {1,1,4,2,1,1,0,0};
    std::vector<int> actual = solution.calculateTime(temperatures);
    solution.printExpectations(expected, actual);
    // --- //
    std::vector<int> temperatures1 = {73,72,71,70};
    std::vector<int> expected1 = {0,0,0,0};
    std::vector<int> actual1 = solution.calculateTime(temperatures1);
    solution.printExpectations(expected1, actual1);
    // --- //
    std::vector<int> temperatures2 = {70,71,72,73};
    std::vector<int> expected2 = {1,1,1,0};
    std::vector<int> actual2 = solution.calculateTime(temperatures2);
    solution.printExpectations(expected2, actual2);
}
