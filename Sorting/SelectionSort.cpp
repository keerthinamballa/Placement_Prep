// Selection Sort Algorithm

void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        int min_ind = i;
        for(int j=i+!; j < n; j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
    }
}

// Time Complexity : O(n^2)

