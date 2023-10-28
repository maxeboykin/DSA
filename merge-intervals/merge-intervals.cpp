#include <iostream>
#include <vector>

class Interval {
public:
    int start = 0;
    int end = 0;

    Interval(int start, int end){
        this->start = start;
        this->end = end;
    }
};


class MergeIntervals{
public:
    static std::vector<Interval> merge(std::vector<Interval> &intervals){
        if(intervals.size() < 2) return intervals;
        std::sort(intervals.begin(), intervals.end(),
                  [](const Interval &i, const Interval &j) {return i.start < j.start;});
        std::vector<Interval>mergedIntervals;
        auto intervalItr = intervals.begin();
        Interval interval = *intervalItr++; // sets left interval
        int start = interval.start;
        int end = interval.end;
        while(intervalItr != intervals.end()){ // while right interval itr not pointing to end
            interval = *intervalItr++; // set interval to right interval, start/end vars should be left interval
            if(interval.start <= end) { // akin to right.start <= left.end
                end = std::max(interval.end, end); // max(right.end, left.end)
            } else {
                mergedIntervals.push_back({start, end});
                start = interval.start;
                end = interval.end;
            }
        }

        mergedIntervals.push_back({start, end});
        return mergedIntervals;
    }

    static std::vector<std::vector<int>> mergeWithInts(std::vector<std::vector<int>> &intervals){
        if(intervals.size() < 2) return intervals;
        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>&i, const std::vector<int>&j) {return i[0] < j[0];});
        std::vector<std::vector<int>>mergedIntervals;
        auto intervalItr = intervals.begin();
        std::vector<int> interval = *intervalItr++; // sets left interval
        int start = interval[0];
        int end = interval[1];
        while(intervalItr != intervals.end()){ // while right interval itr not pointing to end
            interval = *intervalItr++; // set interval to right interval, start/end vars should be left interval
            if(interval[0] <= end) { // akin to right.start <= left.end
                end = std::max(interval[1], end); // max(right.end, left.end)
            } else {
                mergedIntervals.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }

        mergedIntervals.push_back({start, end});
        return mergedIntervals;
    }
    std::vector<Interval> calculateTime(std::vector<Interval> &intervals){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<Interval>result = merge(intervals);
        end = clock();
        printf("Merged Intervals: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    void printExpectations(std::vector<Interval> expected, std::vector<Interval> actual){
        std::cout << "Merge Intervals: ";
        std::cout << "Expected: " << std::endl;
        printVector(expected);
        std::cout << "Actual: " << std::endl;
        printVector(actual);
    }
    void printVector(std::vector<Interval> arr){
        for(auto& val: arr){
            std::cout << val.start << "," << val.end << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    MergeIntervals solution;
    std::vector<Interval> intervals = {{1,4}, {2,5}, {7,9}};
    std::vector<Interval> actual = solution.calculateTime(intervals);
    std::vector<Interval> expected = {{1,5}, {7, 9}};
    solution.printExpectations(expected, actual);


    std::vector<Interval> intervals2 = {{6,7}, {2,4}, {5,9}};
    std::vector<Interval> actual2 = solution.calculateTime(intervals2);
    std::vector<Interval> expected2 = {{2,4}, {5, 9}};
    solution.printExpectations(expected2, actual2);

}
