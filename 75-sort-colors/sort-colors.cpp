class Solution {
public:
    void merge(vector<int> &arr, int l, int mid, int u) {
        int i = l;
        int j = mid + 1;
        int k = 0;
        int a[u - l + 1];
        while (i <= mid && j <= u) {
            if (arr[i] < arr[j]) {
                a[k++] = arr[i++];
            } else {
                a[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            a[k++] = arr[i++];
        }
        while (j <= u) {
            a[k++] = arr[j++];
        }
        for (int i = 0; i < (u - l + 1); i++) {
            arr[l + i] = a[i];
        }
    }
    void mergeSort(vector<int> &arr, int l, int u) {
        int mid;
        if (l < u) {
            mid = (l + u) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, u);
            merge(arr, l, mid, u);
        }
    }
    void sortColors(vector<int>& nums) {
        mergeSort(nums,0,nums.size() -1);
    }
};