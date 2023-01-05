class Solution {
public:
    int numberOfSubstrings(string s) {
        // i-> starting index so that if [a,b,c] is found then by its help we can remove the starting element.... this problem behaves as sliding window problem
        // indexSubstr -> substring index to move forward and add element in substring
        int i=0,n=s.length(),indexSubStr=0,ans=0;
        // number of occurance of a,b,c
        int a=0,b=0,c=0;
        while(i<n && i<=indexSubStr && indexSubStr<=n){
            if(a && b && c){ // if all three found
                ans+=n-(indexSubStr-1);
                if(s[i]=='a')
                    a--;
                else if(s[i]=='b')
                    b--;
                else
                    c--;
                i++;
            }else{
                if(s[indexSubStr]=='a')
                    a++;
                else if(s[indexSubStr]=='b')
                    b++;
                else
                    c++;
                indexSubStr++;
            }
        }
        return ans;
    }
};
