// 977. Squares of a Sorted Array
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

vector<int> sortedSquares(vector<int>& arr){
    int n = arr.size();
    vector<int> res(n);
    int i=0; j = n-1;
    for(int p = n-1; p>=0; p--){
        if(abs(arr[i]) > abs(arr[j])){
            res[p] = arr[i]*arr[i];
            i++;
        }
        else{
            res[p] = arr[j]*arr[j];
            j--;
        }
    }
    return res;
}


// Time Complexity : O(n)
// Space Complexity : O(1) 


