TREE DSA


INFO
		1.) Traversals

			(a) Trees

					Preorder  (root, children) 
					Postorder (children, root)

			(b) Binary Tree

					Inorder   (Left, Root, Right)
					Preorder  (Root, Left, Right) 
					Postorder (Left, Right, Root)

		2.) AVL Trees (Self balancing BST)

			(a) Left rot. and Right rot.

					y                               x
				   / \       Right Rotation        / \
				  x   T3     – – – – – – – >      T1  y 
				 / \         < - - - - - - -         / \
				T1  T2       Left Rotation         T2  T3


					-Order of keys
						-keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
						-BST property is not violated anywhere.
			
			Solving strategy:

			(a) Left Left Case

				T1, T2, T3 and T4 are subtrees.
				         z                                      y 
				        / \                                   /   \
				       y   T4      Right Rotate (z)          x      z
				      / \          - - - - - - - - ->      /  \    /  \ 
				     x   T3                               T1  T2  T3  T4
				    / \
				  T1   T2

			(b) Left Right Case

				     z                               z                           x
				    / \                            /   \                        /  \ 
				   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
				  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
				T1   x                          y    T3                    T1  T2 T3  T4
				    / \                        / \
				  T2   T3                    T1   T2

			(c) Right Right Case

				  z                                y
				 /  \                            /   \ 
				T1   y     Left Rotate(z)       z      x
				    /  \   - - - - - - - ->    / \    / \
				   T2   x                     T1  T2 T3  T4
				       / \
				     T3  T4

			(d) Right Left Case

				   z                            z                            x
				  / \                          / \                          /  \ 
				T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
				    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
				   x   T4                      T2   y                  T1  T2  T3  T4
				  / \                              /  \
				T2   T3                           T3   T4

			Checking Conditions:

				(a) Left Left Case
					- balance > 1 && val < root->left->val

				(b) Right Right Case
					- balance < -1 && val > root->right->val

				(c) Left Right Case
					- balance > 1 && val > root->left->val

				(d) Right Left Case
					- balance < -1 && val < root->right->val
TAKING INPUT
		
		1.) Tree (LEVEL WISE)

			TreeNode<int>* takeInputLevelWise() {
			    int rootData;
			    cin >> rootData;
			    TreeNode<int>* root = new TreeNode<int>(rootData);
			    
			    queue<TreeNode<int>*> pendingNodes;
			    
			    pendingNodes.push(root);
			    while (pendingNodes.size() != 0) {
			        TreeNode<int>* front = pendingNodes.front();
			        pendingNodes.pop();
			        int numChild;
			        cin >> numChild;
			        for (int i = 0; i < numChild; i++) {
			            int childData;
			            cin >> childData;
			            TreeNode<int>* child = new TreeNode<int>(childData);
			            front->children.push_back(child);
			            pendingNodes.push(child);
			        }
			    }
			    return root;
			}

			int main() {
			    TreeNode<int>* root = takeInputLevelWise();
			    printLevelWise(root);
			}

			Sample input : 10 3 20 30 40 2 40 50 0 0 0 0 

			Sample Tree : 10:20,30,40
						  20:40,50
						  30:
						  40:
					      40:
						  50:

		2.) Binary Tree 

			BinaryTreeNode<int>* takeInput() {
			    int rootData;
			    //cout << "Enter root data : ";
			    cin >> rootData;
			    if(rootData == -1) {
			        return NULL;
			    }
			    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
			    queue<BinaryTreeNode<int>*> q;
			    q.push(root);
			    while(!q.empty()) {
			        BinaryTreeNode<int> *currentNode = q.front();
					q.pop();
			        int leftChild, rightChild;
			        //cout << "Enter left child of " << currentNode -> data << " : ";
			        cin >> leftChild;
			        if(leftChild != -1) {
			            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
			            currentNode -> left =leftNode;
			            q.push(leftNode);
			        }
			        //cout << "Enter right child of " << currentNode -> data << " : ";
			        cin >> rightChild;
			        if(rightChild != -1) {
			            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
			            currentNode -> right =rightNode;
			            q.push(rightNode);
			        }
			    }
			    return root;
			}

			int main() {
			    BinaryTreeNode<int>* root = takeInput();
			    cout << sumOfAllNodes(root) << endl;
			}

			Sample input : 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

DATA STRUCTURE

		1.) Tree

			template <typename T>
			class TreeNode{
			    public:
			        T data;
			        vector<TreeNode<T>*> children;

			        TreeNode(T data)
			            this->data = data;
			 
			        ~TreeNode()
			            for (int i = 0; i < children.size(); i++) 
			                delete children[i];
			 };

		2.) Binary Tree and BST

			template <typename T>
			class BinaryTreeNode {
			    public : 
				    T data;
				    BinaryTreeNode<T> *left;
				    BinaryTreeNode<T> *right;

				    BinaryTreeNode(T data) {
				        this -> data = data;
				        left = NULL;
				        right = NULL;
				    }
			};


ALGORITHMS
		
		1.) Level Order Traversal
		
			void printLevelWise(TreeNode<int>* root) {
    
			    queue<TreeNode<int>*> pendingNodes;
			    pendingNodes.push(root);
			    
			    while(!pendingNodes.empty()){
			    	TreeNode<int>* front = pendingNodes.front();
			        pendingNodes.pop();
			                
			        cout<<front->data<<":";
			        
			        if(front->children.size() == 0){
			            cout<<endl;
			            continue;
			        }
			        
			        for(int i = 0; i<front->children.size()-1; i++){
			            cout<<front->children[i]->data<<',';
			            pendingNodes.push(front->children[i]);
			        }
			        cout<<front->children[front->children.size()-1]->data<<endl;
			        pendingNodes.push(front->children[front->children.size()-1]);
			    }
			}

		2.) Height of a Tree
			
			int height(TreeNode<int>* root) {
				if(root == NULL)
			        return 0;
			    
			    int ans = 0;
			    for(auto i : root->children){
			        int temp = height(i);
			        if(temp>ans)
			            ans = temp;
			    }
			    return ans+1;
			}

		3.) Number of Leaf nodes
	
			int numLeafNodes(TreeNode<int>* root) {
    
			    if(root->children.size() == 0)
				    return 1;
			    
			    int ans = 0;
			    for(auto i : root->children)
			        ans += numLeafNodes(i);
			    
			    return ans;
			}

		4.) Top view of a binary Tree

			void topView(Node * root) {
		        unordered_map<int,Node*> m;
		        int mi = INT_MAX, ma = INT_MIN;
		        queue<pair<int,Node*>> q;
		        q.push(make_pair(0, root));
		        while(!q.empty()){
		            pair<int,Node*> front = q.front();
		            q.pop();
		            if(front.second == NULL)
		                continue;
		            if(m.count(front.first) == 0){
		                m[front.first] = front.second;
		                if(mi>front.first)
		                    mi = front.first;
		                if(ma<front.first)
		                    ma = front.first;
		            }
		            q.push(make_pair(front.first-1, front.second->left));
		            q.push(make_pair(front.first+1, front.second->right));
		        }
		        for(int i = mi; i<=ma; i++)
		            cout<<m[i]->data<<' ';
		    }

		5.) LCA of a BST

			Node *lca(Node *root, int v1,int v2) {
		        if(root == NULL || root->data == v1 || root->data == v2 || (root->data < v1 && root->data > v2) || (root->data > v1 && root->data < v2))
		            return root;
		        if(root->data<v1 && root->data<v2)
		            return lca(root->right, v1, v2);
		        else
		            return lca(root->left, v1, v2);
		    }

		6.) Inserting in AVL Trees

			node *newNode(int val){  
			    node *nn = new node(); 
			    nn->val = val;  
			    nn->left = NULL;  
			    nn->right = NULL;  
			    nn->ht = 0;   
			    return nn;  
			}  
			int height(node *root) {  
			    return (root == NULL) ? -1 : root->ht;  
			}  
			int getBalance(node *root)  {  
			    return (root == NULL) ? 0 : (height(root->left) - height(root->right));  
			}  
			node* rightRotate(node *y){  
			    node *x = y->left, *T2 = x->right;  
			    x->right = y;  
			    y->left = T2;  
			    y->ht = max(height(y->left), height(y->right)) + 1;  
			    x->ht = max(height(x->left), height(x->right)) + 1;  
			    return x;  
			} 
			node* leftRotate(node *x){  
			    node *y = x->right, *T2 = y->left;  
			    y->left = x;  
			    x->right = T2;  
			    x->ht = max(height(x->left), height(x->right)) + 1;  
			    y->ht = max(height(y->left), height(y->right)) + 1;  
			    return y;  
			}  
			node* insert(node * root,int val){
			    if (root == NULL)  
			        return newNode(val);  
			  
			    if (val < root->val)  
			        root->left = insert(root->left, val);  
			    else if (val > root->val)  
			        root->right = insert(root->right, val);  
			    else 
			        return root;  
			  
			    root->ht = 1 + max(height(root->left), height(root->right));  
			    
			    int balance = getBalance(root);  

			    if (balance > 1 && val < root->left->val)  
			        return rightRotate(root);  
			    else if (balance < -1 && val > root->right->val)  
			        return leftRotate(root);  
			    else if (balance > 1 && val > root->left->val){  
			        root->left = leftRotate(root->left);  
			        return rightRotate(root);  
			    }  
			    else if (balance < -1 && val < root->right->val){  
			        root->right = rightRotate(root->right);  
			        return leftRotate(root);  
			    }  
			    return root;  
			}
