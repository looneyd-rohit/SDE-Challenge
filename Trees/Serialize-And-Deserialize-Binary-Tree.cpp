// Leetcode 297

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string code = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f = q.front(); q.pop();
            if(f==NULL){
                code += "$,";
                continue;
            }
            string nodeVal = to_string(f->val);
            code += nodeVal;
            code.push_back(',');
            
            // visit childs
            q.push(f->left);
            q.push(f->right);
        }
        // cout<<code<<endl;
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // apply reverse logic, use a queue again
        if(data.front()=='$') return NULL;
        queue<TreeNode*> q;
        int num = 0, i=0;
        bool neg = false;
        for(i=0; i<data.length() && data[i]!=','; i++){
            if(data[i]=='-'){
                neg = true;
                continue;
            }
            num = num*10 + (data[i]-'0');
        }
        TreeNode* root = new TreeNode(num * (neg ? -1 : 1));
        q.push(root);
        i++;
        neg = false;
        for( ; i<data.length(); ){
            if(q.empty()) break;
            
            // get the left
            if(i<data.length() && data[i] == '$'){
                i+=2;
                q.front()->left = NULL;
            }else{
                int n1 = 0;
                for(; i<data.length() && data[i]!=','; i++){
                    if(data[i]=='-'){
                        neg = true;
                        continue;
                    }
                    n1 = n1*10 + (data[i]-'0');
                }
                TreeNode* left = new TreeNode(n1 * (neg ? -1 : 1));
                neg = false;
                q.front()->left = left;
                q.push(left);
                i++;
            }
            
            // get the right
            if(i<data.length() && data[i] == '$'){
                i+=2;
                q.front()->right = NULL;
            }else{
                int n2 = 0;
                for( ; i<data.length() && data[i]!=','; i++){
                    if(data[i]=='-'){
                        neg = true;
                        continue;
                    }
                    n2 = n2*10 + (data[i]-'0');
                }
                TreeNode* right = new TreeNode(n2 * (neg ? -1 : 1));
                neg = false;
                q.front()->right = right;
                q.push(right);
                i++;
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));