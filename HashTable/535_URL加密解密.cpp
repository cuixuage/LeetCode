/*
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

注意:
每次使用实力对象调用  那么我们可以保存每一次调用的URL
再使用hash思想解决
*/

class Solution {
public:
    //对象申请的空间内保存的Map
    unordered_map<long,string> myMap;
    long record = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        myMap[record++] = longUrl;
       // return "http://tinyurl.com/"+record;      //c++ split to vector 比较繁琐
       return ""+record;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long key = atol(shortUrl.c_str());
        return myMap[key];
    }
};
