/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/


    vector<int> inorder(Node* root, vector<int> q){
        if(root->left!=NULL)
            q = inorder(root->left,q);
        q.push_back(root->data);
        if(root->right!=NULL)
            q = inorder(root->right,q);
        return q;
    }

	bool checkBST(Node* root) {
        vector<int> q;
        vector<int> p = inorder(root,q);
        if(p.empty())
            return false;
        for(int i=0;i<p.size()-1;i++){
            if(p[i]>=p[i+1])
                return false;
        }
        return true;
		
	}