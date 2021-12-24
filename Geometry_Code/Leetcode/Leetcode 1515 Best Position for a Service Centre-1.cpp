#define eps 1e-6
#define ld long double
#define pdd pair<ld,ld>
#define x first
#define y second

class Solution {
public:
    pdd p[105];int n;
    
    ld dis_all(pdd mid){
        ld sum;
        for(int i = 0;i < n;i++){
            ld x = p[i].x - mid.x,y = p[i].y - mid.y;
            sum += sqrt(x * x + y * y);
        }
        return sum;
    }
    
    double getMinDistSum(vector<vector<int>>& pos) {
        n = pos.size();
        for(int i = 0;i < n;i++)p[i] = {pos[i][0],pos[i][1]};
        pdd cur = p[0];ld mid_dis = dis_all(p[0]);
        ld test_size = 100;
        ld dx[4] = {1.0,0.0,-1.0,0.0},dy[4] = {0.0,1.0,0.0,-1.0};
        bool flag = 0;
        while(test_size > eps){
            flag = 0;
            for(int i = 0;i < 4;i++){
                pdd newp = cur;
                newp.x += dx[i] * test_size;
                newp.y += dy[i] * test_size;
                ld new_dis = dis_all(newp);
                if(new_dis < mid_dis){
                    mid_dis = new_dis;
                    cur = newp;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)test_size /= 2.0;
        }
        return mid_dis;
    }
};