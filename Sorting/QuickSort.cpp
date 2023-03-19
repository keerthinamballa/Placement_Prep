// Quicksort Algorithm

void qs(vector<int> &arr, int l, int h){
    if(l < h){
        int p = partition(arr, l, h);
        qs(arr, l, p-1);
        qs(arr, p+1, h);
    }
}

int partition(vector<int>& arr, int l, int h){
    int p = arr[l];
    int i = l, j = h;
    while(i < h){
        while(arr[i] <= p && i < h){
            i++;
        }
        while(arr[j] > p && j > 0){
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}


// Time Complexity : O(nlogn)
// Space Complexity : O(1) (excepting recursive call stack)


