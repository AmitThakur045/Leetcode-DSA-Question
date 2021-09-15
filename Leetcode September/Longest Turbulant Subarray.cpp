class Solution {
public:
    bool check(vector<int>& arr, int k) {
        return ((arr[k] > arr[k-1] && arr[k] > arr[k+1]) || (arr[k] < arr[k-1] && arr[k] < arr[k+1])); 
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n < 2)
            return n;
        int res = 1;
        int start = 0, end = 0;
        while(start+1 < n) {
            if(arr[start] == arr[start+1]) {
                start++;
                continue;
            }
            end = start+1;
            while(end+1 < n && check(arr, end)) {
                end++;
            }
            res = max(res, end-start+1);
            start = end;
        }
        return res;
    }
};
