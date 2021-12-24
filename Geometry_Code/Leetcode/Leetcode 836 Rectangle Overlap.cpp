class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //最小的右端點 - 最大的左端點
        int x = min(rec1[2],rec2[2]) - max(rec1[0],rec2[0]);
        //最小的上端點 - 最大的下端點
        int y = min(rec1[3],rec2[3]) - max(rec1[1],rec2[1]);
        return x > 0 && y > 0;
    }
};
