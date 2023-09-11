/*TODO: show various methods including sorting the strings,
 * using prime factor decomposition, and maybe just counting freq of chars
 * like a normal hash map
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

class GenerateParenthesis {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        dfs(n, n, "", ans);
        return ans;
    }
    void printExpectations(std::vector<std::string> expected, std::vector<std::string> actual) {
        std::cout << "GenerateParenthesis: ";
        std::cout << std::endl;
        int idx = 0;
        for (const auto &value: actual) {
            std::cout << "Expected value: " << expected[idx] << " actual val: " << value << std::endl;
            idx++;
        }
    }
private:
    void dfs(int left, int right, std::string path, std::vector<std::string>&ans){
        //base recursive case
        if(left == 0 && right == 0){
            ans.push_back(path);
            return;
        }
        if(left > 0){
            path.push_back('(');
            dfs(left-1, right, path, ans);
            path.pop_back();
        }
        if(right > left){
            path.push_back(')');
            dfs(left, right-1, path, ans);
            path.pop_back();
        }
}
};

int main(){
    GenerateParenthesis solution;
    std::vector<std::string> result1 = solution.generateParenthesis(3);
    std::vector<std::string> expectation1 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    solution.printExpectations(expectation1, result1);
}
