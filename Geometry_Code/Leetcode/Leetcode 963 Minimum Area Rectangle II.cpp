class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& p){
        set<pair<int,int>> s;
        int n = p.size();
        for(int i = 0;i < n;i++)s.insert({p[i][0],p[i][1]});
        double ans = 1e9;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int x1 = p[j][0] - p[i][0];
                int y1 = p[j][1] - p[i][1];
                for(int k = j+1;k < n;k++){
                    int x2 = p[k][0] - p[i][0];
                    int y2 = p[k][1] - p[i][1];
                    if(x1 * x2 + y1 * y2 != 0)continue;
                    int nx = p[k][0] + x1,ny = p[k][1] + y1;
                    if(s.find({nx,ny}) != s.end()){
                        ans = min(ans,sqrt(x1*x1+y1*y1) * sqrt(x2*x2+y2*y2));
                    }
                }
            }
        }
        if(ans == 1e9)return 0;
        return ans;
    }
};