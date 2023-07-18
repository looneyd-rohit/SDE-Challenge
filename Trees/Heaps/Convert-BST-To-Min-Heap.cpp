// https://www.codingninjas.com/studio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0

#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> inorder;
	BinaryTreeNode* curr = root;
	// inorder to store increasing sequence
	while(curr){
		if(curr->left == NULL){
			inorder.push_back(curr->data);
			curr = curr->right;
		}else{
			BinaryTreeNode* temp = curr->left;
			while(temp->right && temp->right!=curr) temp = temp->right;
			if(temp->right){
				temp->right = NULL;
				inorder.push_back(curr->data);
				curr = curr->right;
			}else{
				temp->right = curr;
				curr = curr->left;
			}
		}
	}
	curr = root;
	int index = 0;
	// preorder to replace values with increasing sequence
	while(curr){
		if(curr->left == NULL){
			curr->data = inorder[index++];
			curr = curr->right;
		}else{
			BinaryTreeNode* temp = curr->left;
			while(temp->right && temp->right!=curr) temp = temp->right;
			if(temp->right){
				temp->right = NULL;
				curr = curr->right;
			}else{
				temp->right = curr;
				curr->data = inorder[index++];
				curr = curr->left;
			}
		}
	}
	return root;
}