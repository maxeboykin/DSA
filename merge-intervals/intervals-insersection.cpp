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


class IntervalsIntersection{
public:
    static std::vector<Interval> merge(const std::vector<Interval> &arr1, const std::vector<Interval> &arr2){
        std::vector<Interval>intersectIntervals;
        int i = 0,j = 0;
        while(i < arr1.size() && j < arr2.size()){
            // check if one start time of one interval overlaps the other interval
            if(arr2[j].start >= arr1[i].start && arr1[i].end >= arr2[j].start || //arr1 starts first and overlaps arr2
                arr1[i].start >= arr2[j].start && arr2[j].end >= arr1[i].start // arr2 starts first and overlaps arr1
            ){
                intersectIntervals.push_back({std::max(arr1[i].start, arr2[j].start), std::min(arr1[i].end, arr2[j].end)});
            }
            // move next from interval which finishes first
            if(arr1[i].end < arr2[j].end){
                i++;
            } else {
                j++;
            }
        }
        return intersectIntervals;
    }
    static std::vector<std::vector<int>> mergeInt(const std::vector<std::vector<int>>&arr1, const std::vector<std::vector<int>>&arr2){

    }

    std::vector<Interval> calculateTime(const std::vector<Interval> &arr1, const std::vector<Interval> &arr2){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<Interval>result = merge(arr1, arr2);
        end = clock();
        printf("Intersection Intervals: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    std::vector<std::vector<int>> calculateTimeInts(std::vector<std::vector<int>> &intervals, std::vector<std::vector<int>>&newInterval){
        clock_t start;
        clock_t end;
        start = clock();
        std::vector<std::vector<int>>result = mergeInt(intervals, newInterval);
        end = clock();
        printf("Intersection Intervals Ints: it took %d clicks (%f seconds).\n", end-start, ((float)(end-start))/CLOCKS_PER_SEC);
        return result;
    }

    void printExpectations(std::vector<Interval> expected, std::vector<Interval> actual){
        std::cout << "Intersection Intervals: ";
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
        std::cout << "Intersection Intervals: ";
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
    IntervalsIntersection solution;
    std::vector<Interval> arr_1_1 = {{1,3}, {5,6}, {7,9}};
    std::vector<Interval> arr_1_2 = {{2,3}, {5,7}};
    std::vector<Interval> actual = solution.calculateTime(arr_1_1, arr_1_2);
    std::vector<Interval> expected = {{2,3}, {5, 6}, {7, 7}};
    solution.printExpectations(expected, actual);
    // ---- //
    std::vector<Interval> arr_2_1 = {{1,3}, {5,7}, {9,12}};
    std::vector<Interval> arr_2_2 = {{5,10}};
    std::vector<Interval> actual2 = solution.calculateTime(arr_2_1, arr_2_2);
    std::vector<Interval> expected2 = {{5,7}, {9, 10}};
    solution.printExpectations(expected2, actual2);

}
