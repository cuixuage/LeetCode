/*
区分普通路径和问题：  并不一定是root节点到leaf结点的路径
有可能是leaf节点到另一个leaf节点的路径
*/


int maxValue;

public int maxPathSum(TreeNode root) {
    maxValue = Integer.MIN_VALUE;
    maxPathDown(root);
    return maxValue;
}

private int maxPathDown(TreeNode node) {
    if (node == null) return 0;
    int left = Math.max(0, maxPathDown(node.left));
    int right = Math.max(0, maxPathDown(node.right));
    maxValue = Math.max(maxValue, left + right + node.val);     //全局max  类似后序遍历的
    return Math.max(left, right) + node.val;                    //max 
}