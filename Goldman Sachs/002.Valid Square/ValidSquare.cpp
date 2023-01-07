class Solution {
public:
    /*
        distance between two points is sqrt((x2-x1)^2 + (y2-y1)^2)
        find the distance between all the points. it it is a square then it will have 4 side of same length and 2 diagonal of same length
       p.s. we are not taking the square as it will give values in decimal which might differ or difficult to store...
    */
    
    int distance(vector<int> p1,vector<int> p2){
        int x=p2[0]-p1[0];
        int y=p2[1]-p1[1];
        return (x*x + y*y);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // store all the distance between 2 points in a set
        unordered_set<int> square={distance(p1,p2),distance(p1,p3),distance(p1,p4),distance(p2,p3),distance(p2,p4),distance(p3,p4)};
        // if distance is zero means there is 2 same points which cannot form a square therefore return false
        if(square.find(0)!=square.end())
            return 0;
        // if size of set is 2 i.e. it contains the side of square and diagonal of the square only so it is a square
        if(square.size()==2)
            return 1;
        return 0;
    }
};
