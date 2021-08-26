class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return false;
        preorder += ',';
        
        int size = 1;
        int n = preorder.size();
        
        for(int i=0; i<n; i++) {
            if(preorder[i] != ',')
                continue;
            size--;
            if(size < 0)
                return false;
            if(preorder[i-1] != '#')
                size += 2;
        }
        return size == 0;
    }
};
