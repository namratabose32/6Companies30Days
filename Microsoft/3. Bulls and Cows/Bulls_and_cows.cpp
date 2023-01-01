class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> s,g; // number of occurance of every digit
        for(auto x:secret)
            s[x]++;
        for(auto x:guess)
            g[x]++;
        int n=0; // number of right guess irrespective of their position
        for(auto x:s){
            if(g.find(x.first)!=g.end()){
                n+=min(g[x.first],x.second);
            }
        }
        int bull=0; //guess at right location same as secret
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                bull++;
        }
        return to_string(bull)+"A"+to_string(n-bull)+"B";
    }
};
