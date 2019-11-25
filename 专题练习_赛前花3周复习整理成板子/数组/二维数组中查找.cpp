class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool ok = 0;
        int rs = array.size(),cs = array[0].size();
        if(rs && cs){
            int r = 0,c = cs-1;

            while(r < rs && c >= 0){
                int tp = array[r][c];
                if(array[r][c] == target){
                    ok = 1; break;
                } else if(array[r][c] > target) --c;
                else ++r;
            }
        }

        return ok;
    }
};