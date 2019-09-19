/*
substr 子串
二维动态规划 [i,j]区间是否为回文子串
dp[i][j] = dp[i+1][j-1] && str[i]==str[j]
         = False
*/


public String longestPalindrome(String s) {
  int n = s.length();
  String res = null;
    
  boolean[][] dp = new boolean[n][n];
    
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i + 1][j - 1]);
            
      if (dp[i][j] && (res == null || j - i + 1 > res.length())) {
        res = s.substring(i, j + 1);
      }
    }
  }
    
  return res;
}

/*
拓展问题:
字符串中01个数相等的最长substring
思路:
==> 将零替换为-1,转换为区间和为零的最长区间
==> dp[i][j]记录区间和 ==> dp[i+1][j-1]+arr[i]+arr[j]
==> 统计dp[i][j]==0的区间长度
*/