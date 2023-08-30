#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
/*
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a
 different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction.
 If you cannot achieve any profit, return 0.
 */

using namespace std;
class BestTimeBuyAndSellStock {
public:
    int maxProfit(const vector<int> &prices) {
        int maxProfit = 0;
        int left = 0;
        for(int right = 0; right < prices.size(); right++){
            int curProfit = prices[right] - prices[left];
            maxProfit = max(maxProfit, curProfit);
            if(curProfit <= 0){
                left = right;
            }
        }
        return maxProfit;
    }
};

int main(){
    BestTimeBuyAndSellStock solution;
    vector<int> foo = {7,1,5,3,6,4};
    int expectedResult = 5;
    vector<int> bar = {7,6,4,3,1};
    int expectedResultTwo = 0;
    int resultOne = solution.maxProfit(foo);
    int resultTwo = solution.maxProfit(bar);
    cout << "best Time to Buy and Sell Stock: ";
    cout << endl;
    cout << "Expected profit result: " << expectedResult << " actual: " << resultOne;
    cout << endl;
    cout << "Expected profit result: " << expectedResultTwo << " actual: " << resultTwo;
    cout << endl;
}