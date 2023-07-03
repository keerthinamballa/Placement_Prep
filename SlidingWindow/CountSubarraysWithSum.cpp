// 930. Binary Subarrays With Sum
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.


// Using hashing

int countSubarrays(vector<int> &nums, int goal){
    int n = nums.size();
    unordered_map<int, int> m({{0, 1}});
    int sum = 0, res = 0;
    for(int it : nums){
        sum += it;
        res += m[sum - goal];
        m[sum]++;
    }
    return res;
}


// Sliding Window Approach

int atmost(vector<int> &nums, int goal){
    int n = nums.size();
    if(goal < 0) return 0;
    int left = 0, right = 0, res = 0;
    while(right < n){
        goal -= nums[right];
        while(goal < 0){
            goal += nums[left];
            left++;
        }
        res += (right-left+1);
        right++;
    }
    return res;
}

int countSubarrays(vector<int> &nums, int goal){
    return atmost(nums, goal) - atmost(nums, goal-1);
}

// T.C => O(n)
// S.C => O(1)
