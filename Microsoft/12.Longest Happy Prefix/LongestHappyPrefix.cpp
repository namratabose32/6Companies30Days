class Solution {
public:
    string longestPrefix(string s) {
        // Method - 1
        //This memory limit is exceeded in this method quki ek ek karke sara prefix ko store kar rahe the
    /*
        unordered_set<string>prefix;
        string pre;
        for(int i=0;i<s.length()/2;i++){
            pre=pre+s[i];
            prefix.insert(pre);
        }
        string suf;
        string ans="";
        for(int i=s.length()-1;i>=1;i--){
            suf=s[i]+suf;
            if(prefix.find(suf)!=prefix.end()){
                ans=suf;
            }                
        }return ans;
    */
        
        //Method - 2
      // Simpily Rabin-Karp algorithm is used
    /*
        Simple sa funda h.... hm a to z ka hash value lete h i.e 0 to 25
        a-> 0 , b->1, c->2....etc
        ab agar string ka directly sum lenge toh zada chances h hi same sum ke liye bahot sare different strings ho... chalo example se sajho.... 
        string size maan lo 3 and sum ek substring ka 5 maan liye... tb isme kya h ki bahot saare string aa jayenge jaise "aac","abb","aca","bab"...etc.
        toh sabka direct value lene se acha Rabin-Karp ne bola aap previous value ko 10 se multiply kardo and phir current value ko add karo then sbka unique sum hi ayega.....chalo phir example se smajhte h.... 
        aac = 1*(10)^2 +1*(10)^1+3*(10)^0 = 113
        aca = 1*(10)^2 +3*(10)^1+1*(10)^0 = 131 
        so now aac and aca value will not be equal but previously we saw their values were same i.e. 5.........
        Hence this method can be used to find out the longest happy prefix were prefix == suffix
    */
        long pre=0,suf=0,len=0,mul=1;
        int mod=1e9+7;
        for(int i=0,j=s.length()-1;j>0;j--,i++){
            // value of next prefix and suffix element to be added
            int prefix=s[i]-'a';
            int suffix=s[j]-'a';
            // adding it to summation
            //For the prefix hash, we will multiply the previous value by 10 and add a new letter.
            pre=(pre*10+prefix)%mod;
            //For the suffix hash, we add a new letter multiplied by 26 ^ (i - 1).
            suf=(suf+mul*suffix)%mod;
            mul=mul*10%mod;
            // agar prefix aur suffix ka hash value same h toh waha tak ka length hoga...
            if(pre==suf)
                len=i+1; // i+1 isleye le rahe jisse ki length proper calculate kr paye as i startss from 0.
        }
        return s.substr(0,len); // we donot take len+1 here instead we take i+1 in previous statement as yaha liye toh jb condition match nhi karega toh yaha len+1 lene se incorrect ans dene lagega
    }
};
// phirse hindi me comments daalne ke liye khed h.... :)
