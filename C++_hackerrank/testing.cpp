#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray {
public:
    static vector<int> get_array() {
      vector <int> arr;
      return arr;
    }

};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        vector <int> arr;
        for(int i =0;i<10;i++)
         arr.push_back(i+1);
        return arr;
    }

    static int get_expected_result() {
       return 0;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        vector <int> arr;
        for(int i =0;i<10;i++)
         arr.push_back(i+1);
        arr[1] = 1;
        return arr;
    }

    static int get_expected_result() {
        return 0;
    }

};

