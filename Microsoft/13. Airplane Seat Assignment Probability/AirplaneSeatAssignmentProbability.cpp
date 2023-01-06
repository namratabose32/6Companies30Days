class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double probability=1.0;
        // only one person so he will definitely get the seat
        if(n==1)
            return probability;
        // there is equal chance of getting and not getting a seat so probability is 50%
        else
            return probability/2;
    }
};
