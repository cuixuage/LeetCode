    //AC
    // 寻找共现词组
    
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string> ans;
        if(text.size()<=2) return ans;
        
        vector<string> internal;
        stringstream ss(text); // Turn the string into a stream.
        string tok;
        while(getline(ss, tok, ' ')) {
            internal.push_back(tok);
        }
        
        for(int i=2;i<internal.size();i++){
            if(internal[i-2] == first && internal[i-1]==second)
                ans.push_back(internal[i]);
        }
        
        return ans;
    }