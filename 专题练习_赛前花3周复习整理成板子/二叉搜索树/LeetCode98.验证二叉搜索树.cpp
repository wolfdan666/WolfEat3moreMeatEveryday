// 方法二: 迭代
// 通过使用栈，上面的递归法可以转化为迭代法。这里使用BFS
//
// Java版
// class Solution {
//   LinkedList<TreeNode> stack = new LinkedList();
//   LinkedList<Integer> uppers = new LinkedList(),
//           lowers = new LinkedList();

//   public void update(TreeNode root, Integer lower, Integer upper) {
//     stack.add(root);
//     lowers.add(lower);
//     uppers.add(upper);
//   }

//   public boolean isValidBST(TreeNode root) {
//     Integer lower = null, upper = null, val;
//     update(root, lower, upper);

//     while (!stack.isEmpty()) {
//       root = stack.poll();
//       lower = lowers.poll();
//       upper = uppers.poll();

//       if (root == null) continue;
//       val = root.val;
//       if (lower != null && val <= lower) return false;
//       if (upper != null && val >= upper) return false;
//       // 遍历左边的时候，右边的最大一直保持val
//       // 遍历右边的时候，左边的最小一直保持val，所以就保持了性质
//       update(root.right, val, upper);
//       update(root.left, lower, val);
//     }
//     return true;
//   }
// }

// cpp dfs
// CE一发,因为指针不能直接用 `.` 而要用 `->`
// wa一发,如下,佛了 ====》 看了好久，感觉自己绝对没错，所以交别人的验证一下先
// 2019年11月24日16:50:06 发现别人AC了...
// 然后2019年11月24日16:53:10 测试一发发现傻逼了自己，NULL在c++里面是0，和java里面的Integer对象中的NULL不是一样的！我傻逼了
// 后面改了又wa在单值上
/*
73 / 75 个通过测试用例
状态：解答错误
提交时间：0 分钟之前
输入：
[0,null,-1]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  // 对于边界值有两种处理方式,1. 设置更大的界限,不过这样显然是找到的数据的bug
  // 所以我采用第二种方式,就是利用 二叉搜索树 不会有重复值的性质去 取代之前的>=,<=,这样就不会受限了
    // set<int> s;// 20ms
    unordered_set<int> s;// 16ms

    bool solve(TreeNode *root,int min,int max){
      if(root == NULL) return true;
      int val = root->val;
      if(s.find(val)!=s.end()) return false;
      else s.insert(val);
      // 这里会wa在`[2147483647]` if(min>=val) return false;
      // 凡是遍历下来的，一定有父亲，所以其实只要特判一手单根树就行了！
      // [1,null,1] 右边遍历也不是跟左边的孩子比较，都是和父亲比较！！ if(root->left!=NULL && min>=val) return false;
      if(min>val) return false;
      // 这里会wa在`[1,1]` 因为右边不是跟右孩子比较！ if(root->right!=NULL && max<=val) return false;
      if(max<val) return false;
      // 遍历左边的时候，右边的最大一直保持val
      // 遍历右边的时候，左边的最小一直保持val，所以就保持了性质
      return solve(root->left,min,val) && solve(root->right,val,max);
    }

    bool isValidBST(TreeNode* root) {
      // return solve(root,NULL,NULL);
      if(root == NULL || (root->left == NULL && root->right == NULL) ) return true;
      return solve(root,INT_MIN,INT_MAX);
    }
};


// class Solution {
// public:
// bool check(TreeNode* root, long lower, long upper) {
// if (!root) {
//   return true;
// }
// else {
//   bool left = true;
//   bool right = true;
//   if (root->left) {
//     if (root->left->val <= lower || root->left->val >= upper || root->left->val >= root->val) {
//       return false;
//     }
//     else {
//       left = check(root->left, lower, root->val);
//     }
//   }
//   if (root->right) {
//     if (root->right->val <= lower || root->right->val >= upper || root->right->val <= root->val) {
//       return false;
//     }
//     else {
//       right = check(root->right, root->val, upper);
//     }
//   }
//   return left && right;
// }
// }

// bool isValidBST(TreeNode* root) {
//     if (!root) {
//       return true;
//     }
//     else {
//       return check(root,LONG_MIN,LONG_MAX); // 有 INT_MAX INT_MIN输入样例 需要更大的数据
//     }
//   }
// };