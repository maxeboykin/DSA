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

class RandomizedSet {
private:
    std::vector<int> vals = {};
    std::unordered_map<int, int> map;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if(map.find(val) == map.end()){
            vals.push_back(val);
            map[val] = vals.size()-1;
            return true;
        }
        return false;
    }
    bool remove(int val) {
       if(map.find(val) != map.end()){
           int last = vals.back();
           map[last] = map[val]; // key, stores new index for the last val that you moved
           vals[map[val]] = last;
           //std::swap(vals[map[val]], vals[map[last]]); // O(1) since elements are non containers
            // we are clobbering where the val is with the last val and removing the last element (pop)
            // we have to update the map first before doing the clobber or the mapping will be unrecoverable
            // and this is why we cant just use swap
            vals.pop_back();
           map.erase(val);
           return true;
       }
       return false;
    }
    int getRandom() {
        int randomIdx = std::rand() % vals.size();
        return vals[randomIdx];
    }
};


int main(){
    RandomizedSet* obj = new RandomizedSet();
    obj->insert(0);
    obj->insert(5);
    obj->insert(12);
    obj->insert(13);
    obj->remove(12);
    obj->insert(2);
    obj->remove(1);
    int result = obj->getRandom();
    int expected = 2;
    std::cout << "expect result to be equal to : " << expected << " . Actual result: " << result << std::endl;
}
