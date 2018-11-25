/*
此回溯问题十分特别  每一个数字代表的字符不同，在从中抽取排列

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

vector<string> letterCombinations(string digits){
    vector<string> res;
    if(digits=="") return res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
        
    //对于每一个数字
    for(int i=0;i<digits.size();i++){
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for(int j=0;j<res.size();j++)
            for(int c=0;c<chars.size();c++)
                //res[j]是vector  每次讲当前数字代表的字符  加入到之前的所有排列上
                tempres.push_back(res[j]+chars[c]);
        //更新
        res = tempres;
    }
    return res;
}
