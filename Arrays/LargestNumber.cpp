// 179. Largest Number
// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.


static bool myCompare(int x, int y){
    string val1 = to_string(x) + to_string(y);
    string val2 = to_string(y) + to_string(x);
    return val1 > val2;
}

int largestNumber(vector<int>& nums){
    sort(nums.begin(), nums.end(), myCompare);
    string s;
    for(int &x: nums){
        s += to_string(x);
    }
    while(s[0] == 0 && s.length() > 1){
        s.erase(0,1);
    }
    return s;
}

// Time Complexity : O(nlogn)
// Space Complexity : O(1)
