/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        TreeLinkNode *curr = root,*next_row;
        
        if(root)
            root->next = NULL;
        else
            return;
        
        while(curr)
        {
            next_row = curr->left;
            
            while(curr && curr->left && curr->right)
            {
                curr->left->next = curr->right;
                
                if(curr->next)
                    curr->right->next = curr->next->left;
                else
                    curr->right->next = NULL;
                
                curr = curr->next;
            }
            curr = next_row;
        }
            
        
    }
};