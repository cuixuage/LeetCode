// https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution

// left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row

// right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row

// height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';

// height(i,j) = 0, if matrix[i][j]=='0'