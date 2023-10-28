#include <iostream>
#include <vector>
#include <stack>

class RemoveAllAdjacentDuplicates{
public:
    std::string removeAdjacentDuplicates(std::string s) {
        std::string stack;
        for(char curChar : s){
            if(!stack.empty() && stack.back() == curChar){
                stack.pop_back();
            } else{
                stack.push_back(curChar);
            }
        }
        return stack;
    }

    std::string calculateTime(std::string s){
        clock_t start;
        clock_t end;
        start = clock();
        std::string result = removeAdjacentDuplicates(s);
        end = clock();
        printf("Remove All Adjacent Duplicates in String: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    void printExpectations(std::string expected, std::string actual){
        std::cout << "Remove All Adjacent Duplicates in String: ";
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Actual: " << actual << std::endl;
    }
};

int main(){
    RemoveAllAdjacentDuplicates solution;
    std::string s1 = "abccba";
    std::string expected1 = "";
    std::string actual = solution.calculateTime(s1);
    solution.printExpectations(expected1, actual);

    std::string s2 = "foobar";
    std::string expected2 = "fbar";
    std::string actual2 = solution.calculateTime(s2);
    solution.printExpectations(expected2, actual2);

    std::string s3 = "abcd";
    std::string expected3 = "abcd";
    std::string actual3 = solution.calculateTime(s3);
    solution.printExpectations(expected3, actual3);

}
