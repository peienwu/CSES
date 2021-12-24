class Solution {
public:
    double R,X,Y;
    Solution(double radius, double x_center, double y_center) {
        R = radius;X = x_center;Y = y_center;
        srand(time(NULL));
    }
    
    vector<double> randPoint() {
        double Area = rand() * R * R * M_PI / (RAND_MAX + 1.0);
        double r = sqrt(Area / M_PI);
        double theta = 2.0 * M_PI * rand() / (RAND_MAX + 1.0);
        vector<double> ans;
        ans.push_back(X + r * cos(theta));
        ans.push_back(Y + r * sin(theta));
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */