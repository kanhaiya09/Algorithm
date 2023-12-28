// https://practice.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1?

class Solution {
  public:
    bool isOperator(char ch){
        return ch=='+' || ch=='-' || ch=='*' || ch=='/';
    }
  
    int checkRedundancy(string str) {
       stack<char> s;
       for(int i = 0 ; i < str.size() ; i++ ){
           char ch = str[i];
           if(ch=='(' or isOperator(ch)){
               s.push(ch);
           }else{
               if(ch==')'){
                   int cnt = 0;
                   
                   while(s.top() != '('){
                       if(isOperator(s.top()))
                            cnt++;
                        s.pop();
                   }
                   //cout<<"cnt : "<<cnt<<"\n" ;
                   if(cnt==0)
                        return true;
                   s.pop();    
               }
           }
       }
       return false;
    }
};
