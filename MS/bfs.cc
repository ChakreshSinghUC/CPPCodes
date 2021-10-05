//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        set<TreeNode*> visited;
        queue<TreeNode*> q;
        if (root == nullptr)
            return {};
        q.push(root);
        visited.insert(root);
        bool toggle_flag = true;
        vector<vector<int>> ret;
        vector<int> r;
        while (!q.empty())
            {
            int q_size = q.size();
            while (q_size--)
                {
                TreeNode* t = q.front();
                r.push_back(t->val);
                visited.insert(t);
                q.pop();
                if (t->left != nullptr && visited.find(t->left) == visited.end())
                    {
                    q.push(t->left);
                    }

                if (t->right != nullptr && visited.find(t->right) == visited.end())
                    {
                    q.push(t->right);
                    }
                }

            if (!r.empty())
                {
                ret.push_back(r);
                r.clear();
                }
            }

        vector<vector<int>> v;
        for (auto a : ret)
            {
            if (!toggle_flag)
                {
                reverse(a.begin(), a.end());
                }

            v.push_back(a);
            toggle_flag ^= true;
            }

        return v;
        }
    };
