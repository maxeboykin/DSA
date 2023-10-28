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


class InsertIntervals{
public:
    static std::vector<Interval> insert(const std::vector<Interval> &intervals, Interval newInterval){
        if(intervals.empty()) return std::vector<Interval>{newInterval};
        std::vector<Interval>mergedIntervals;
        int i = 0;
        while(i < intervals.size() && intervals[i].end < newInterval.start) {
            mergedIntervals.push_back(intervals[i++]);
        }
        while(i < intervals.size() && intervals[i].start <= newInterval.end) {
            newInterval.start = std::min(newInterval.start, intervals[i].start);
            newInterval.end  = std::max(newInterval.end, intervals[i].end);
            i++;
        }
        mergedIntervals.push_back(newInterval);
        while(i < intervals.size()){
            mergedIntervals.push_back(intervals[i++]);
        }
        return mergedIntervals;
    }
    static std::vector<std::vector<int>> insertInt(const std::vector<std::vector<int>>&intervals, std::vector<int>& newInterval){
        if(intervals.empty()) return std::vector<std::vector<int>>{newInterval};
        std::vector<std::vector<int>>mergedIntervals;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            mergedIntervals.push_back(intervals[i++]);
        }
        while(i < intervals.size() && intervals[i][0] <=  newInterval[1]){ // ends when start is greater than new interval end
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        mergedIntervals.push_back({newInterval});
        while(i < intervals.size()){
            mergedIntervals.push_back(intervals[i++]);
        }
        return mergedIntervals;
    }
//    static std::vector<Interval> insert(const std::vector<Interval> &intervals, Interval newInterval){
//        if(intervals.empty()) return std::vector<Interval>{newInterval};
//        std::vector<Interval>mergedIntervals;
//        bool intervalInserted = false;
//        auto intervalItr = intervals.begin();
//        Interval interval = *intervalItr++;
//        int start = interval.start;
//        int end = interval.end;
//        while(intervalItr != intervals.end()){
//            interval = *intervalItr++;
//            if(!intervalInserted && newInterval.start <= end){
//                start = std::min(start, newInterval.start);
//                end = std::max(end, newInterval.end);
//                intervalInserted = true;
//            }
//            if(interval.start <= end ) {
//                end = std::max(end, interval.end);
//            } else {
//                mergedIntervals.push_back({start, end});
//                start = interval.start;
//                end = interval.end;
//            }
//        }
//        if (intervalInserted) end = std::max(end, newInterval.end);
//        mergedIntervals.push_back({start, end});
//        if(intervalInserted == false){
//            mergedIntervals.push_back(newInterval);
//        }
//        return mergedIntervals;
//    }
    std::vector<Interval> calculateTime(std::vector<Interval> &intervals, Interval newInterval){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<Interval>result = insert(intervals, newInterval);
        end = clock();
        printf("Insert Intervals: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    std::vector<std::vector<int>> calculateTimeInts(std::vector<std::vector<int>> &intervals, std::vector<int> newInterval){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<int>>result = insertInt(intervals, newInterval);
        end = clock();
        printf("Insert Intervals Ints: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
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
    void printExpectationsWithInts(std::vector<std::vector<int>> expected, std::vector<std::vector<int>> actual){
        std::cout << "Merge Intervals: ";
        std::cout << "Expected: " << std::endl;
        for(auto& val: expected){
            std::cout << val[0] << "," << val[1] << " ";
        }
        std::cout << std::endl;
        std::cout << "Actual: " << std::endl;
        for(auto& val: actual){
            std::cout << val[0] << "," << val[1] << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    InsertIntervals solution;
    std::vector<Interval> intervals = {{1,3}, {5,7}, {8,12}};
    std::vector<Interval> actual = solution.calculateTime(intervals, {4, 6});
    std::vector<Interval> expected = {{1,3}, {4, 7}, {8, 12}};
    solution.printExpectations(expected, actual);

    std::vector<Interval> intervals2 = {{1,3}, {5,7}, {8,12}};
    std::vector<Interval> actual2 = solution.calculateTime(intervals2, {4, 10});
    std::vector<Interval> expected2 = {{1,3}, {4, 12}};
    solution.printExpectations(expected2, actual2);

    std::vector<Interval> intervals3 = {{1,3}, {5,7}, {8,12}};
    std::vector<Interval> actual3 = solution.calculateTime(intervals3, {13, 15});
    std::vector<Interval> expected3 = {{1,3}, {5, 7}, {8,12}, {13,15}};
    solution.printExpectations(expected3, actual3);



    // -------------- //

    std::vector<std::vector<int>> intervals4 = {{1,3}, {5,7}, {8,12}};
    std::vector<std::vector<int>> actual4 = solution.calculateTimeInts(intervals4, {4, 6});
    std::vector<std::vector<int>> expected4 = {{1,3}, {4, 7}, {8, 12}};
    solution.printExpectationsWithInts(expected4, actual4);

}
