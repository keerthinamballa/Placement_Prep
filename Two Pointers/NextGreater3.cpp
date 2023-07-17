// 556. Next Greater Element III
// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
// Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

// APPROACH:

// It is mentioned in the question that if a greater number cannot be formed from the given number, we return -1.
// That is the greatest number that can be formed from the digits of the given number is the number itself.
// In that case we return -1;
// We can decide that the given number is the greatest number that can be formed from the given digits, if the number is formed by
// descending order of the digits, we can conclude that the given number is the greatest number that can be formed from the given digits.
// And if there is an digit that is less than the digit next to it, we can call it the breaking point. This interger should be modified to
// get the next greater number. Inorder to get the smallest number which is greater than the given number, we find the first breaking point
// from the end of the number. This number, i.e the number at breaking point should be replced with a number which is just greater than the 
// number. We need to find this number from the digits which are to the right of the number at breaking point. 
// And at ay point of time, we could find a breaking point, that is there is no digit which is less than the digit nest to it, that means
// the digits are in the desceding order in the number, we can simply return -1.
// once we swap the integers, we will need to sort the elements from breaking point till end to attain the minimum greatest number.

// To make the traversal easy and to find the breaking points, we can store the digits in an array or vector.
// The idea is to traverse the digits from the right to find the breaking point.
// If at any point, we cross the boundary, we simply return -1.
// Then again we traverse from right to find the index of the digit to be replaced with.
// Swap the elements at both positions.
// sort the digits after breaking point index.

int nextGreater(int n){
    vector<int> nums;
    while(n){
        nums.push_back(n%10);
        n /= 10;
    }
    reverse(nums.begin(), nums.end());

    int k, l;
    int m = nums.size();
    for(k = m-2; k >= 0; k--){
        if(nums[k] < nums[k+1]) break;
    }
    if(k < 0) return -1;
    else{
        for(l=m-1; l>k; l--){
            if(nums[l] > nums[k]) break;
        }
        swap(nums[k], nums[l]);
        sort(nums.begin()+k+1, nums.end());
    }

    string res = "";
    for(int i=0; i<m; i++){
        res += to_string(nums[i]);
    }
    int ans = stoll(res);
    if(res > INT_MAX) return -1;
    return ans;
}

// T.C = O(NlogN)


