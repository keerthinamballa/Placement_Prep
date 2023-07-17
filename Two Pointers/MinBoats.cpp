// 881. Boats to Save People
// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
// Return the minimum number of boats to carry every given person.


// APPROACH:

// It is given here that the boat can accomodate atmost two people if the sume of their weights is atmost the limit.
// The idea is to sort the weights, use two pointers left and right.
// Initialize the left pointer to 0, right pointer to len(weights) - 1.
// For every pair of left and right, compute the sum of their weights.
// If the sum is less than or equal to the limit, one boat can accomodate both of them and we move to the next pair.
// If the sum is greater than the limit, the boat cannot accomodate both. Instead it can take only one of them.
// Here is a catch, to minimize the number of boats, the boat takes up the heavier person of the to. The intuition is the lighter person can form
// a pair with another person such that they together can have a weight less than or equal to limit.
// At the end we return the number of boats.

int minBoats(vector<int> &weights, int limit){
    int n = weights.size();
    int left = 0, right = n-1;
    int count = 0;
    while(left <= right){
        int curr_weight = weight[left] + weight[right];
        if(curr_weight <= limit){
            left++;
            right--;
        }
        else{
            right--;
        }
        count++;
    }
    return count;
}

// T.C = O(N)




