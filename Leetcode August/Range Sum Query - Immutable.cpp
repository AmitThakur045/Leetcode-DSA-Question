class NumArray {
public:
    vector<int> tmp;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(i == 0)
                tmp.push_back(nums[i]);
            else 
                tmp.push_back(nums[i] + tmp[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return tmp[right];
        return tmp[right] - tmp[left-1];
    }
};
