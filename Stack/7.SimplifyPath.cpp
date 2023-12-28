// https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
        
    vector<string> tokenize(string str,string del){
        int start = 0;
        int end = 0;
        vector<string> res;
        do{
            end = str.find(del,start);
            string tmp = str.substr(start,end-start);
            res.push_back(tmp);
            start = end+1;
        }while(end !=-1);
        
        return res;
    }
    
    string simplifyPath(string path) {
        string res= "";
        vector<string> str =tokenize(path,"/");
        stack<string> s;
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(str[i]=="" or str[i]==".")
                continue;
            else if(str[i]==".."){
                if(!s.empty())
                    s.pop();
            }
            else 
                s.push(str[i]);
            
        }
        stack<string> another;
        while(!s.empty()){
            another.push(s.top());
            s.pop();
        }
        
        while(!another.empty()){
            res+= "/";
            res += another.top();
            another.pop();
        }
        if(res=="")
            return "/";
        return res;
    }
};
