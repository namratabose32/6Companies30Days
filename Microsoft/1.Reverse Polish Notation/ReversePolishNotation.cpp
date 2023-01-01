class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
      // add numbers to stack
      // in case of operator perform the operation using the operator on the top 2 elements pop them and push the result to the stack
      // the final value will be stored in the stack after completion of all the operations
        for(auto x:tokens){
            if(x=="+" || x=="-" || x=="*" || x=="/"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                if(x=="+"){
                    s.push(a+b);
                }else if(x=="-")
                    s.push(b-a);
                else if(x=="*")
                    s.push(a*b);
                else
                    s.push(b/a);
            }else{
                s.push(stoi(x));
            }
        }return s.top();
    }
};
