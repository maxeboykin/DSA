#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>

bool calculateTime(std::string arg, bool (*func)(std::string));
class RansomNote {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char,int> mag;
        for(int i = 0; i < magazine.length(); i++){
            mag[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(mag[ransomNote[i]] <= 0) return false;
            mag[ransomNote[i]]--;
        }
        return true;
    }
    bool calculateTime(std::string ransomNote, std::string magazine){
        clock_t start;
        clock_t end;
        start = clock();
        bool result = canConstruct(ransomNote, magazine);
        end = clock();
        printf("Ransom Note: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }
    void printExpectations(bool expected, bool actual, bool expected2, bool actual2, bool expected3, bool actual3){
        std::cout << "Ransom Note: ";
        std::cout << std::endl;
        std::cout << "Expected: " << expected << " actual: " << actual;
        std::cout << std::endl;
        std::cout << "Expected: " << expected2 << " actual: " << actual2;
        std::cout << std::endl;
        std::cout << "Expected: " << expected3 << " actual: " << actual3;
        std::cout << std::endl;
    }
};


int main(){
    RansomNote solution;
    std::string rn1 = "a";
    std::string mag1 = "b";
    bool expectedResult = false;
    std::string rn2 = "aa";
    std::string mag2 = "ab";
    bool expectedResultTwo = false;
    std::string rn3 = "aa";
    std::string mag3 = "aab";
    bool expectedResultThree = true;
    bool resultOne = solution.calculateTime(rn1, mag1);
    bool resultTwo = solution.calculateTime(rn2, mag2);
    bool resultThree = solution.calculateTime(rn3, mag3);
    solution.printExpectations(expectedResult, resultOne, expectedResultTwo, resultTwo, expectedResultThree, resultThree);
}
