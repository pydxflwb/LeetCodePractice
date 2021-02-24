
// 832 翻转图像
// 1. 普通解法

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        vector<int> line = vector<int>();
        for (int i=0; i<A.size(); i++){
            for (int j=A[i].size()-1; j>=0; j--){
                line.push_back(A[i][j]?0:1);
            }
        swap(A[i], line);
        line.clear();
        }
        return A;
    }
};

// 2.