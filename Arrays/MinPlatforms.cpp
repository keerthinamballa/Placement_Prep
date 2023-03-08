// Minimum Platforms
// Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

int minPlatforms(vector<int>& arr, vector<int>& dep){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int platforms = 1, res = 1;
    int i=1, j=0;
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            platforms++;
            i++;
        }
        else{
            platforms--;
            j++;
        }
        if(platforms > res) res = platforms;
    }
    return res;
}

// Time Complexity : O(n*logn)
// Space Complexity : O(1)




