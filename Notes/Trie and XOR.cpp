Application - Find maximum pair xor in O(nlog(maxElement)) instead of n^2
Intution - When reducing the complexity by factor log(n) and someting may be done with those numbers in bitwise scale.
         - This concept is generally used in problem involving xor. 

    NODE:

        class TrieNode{
            public:
            TrieNode* left;
            TrieNode* right;
        };


    CODE: Making bitwise trie of numbers
        Complexity - O(max(n))

        void insert(int n, TrieNode* head){
            TrieNode *curr = head;
            for(int i = 31; i>=0; i--){
                int b = (n>>i)&1;

                if(b == 0){
                    if(curr->left == NULL)
                        curr->left = new TrieNode();
                    curr = curr->left;
                }else{
                    if(curr->right == NULL)
                        curr->right = new TrieNode();
                    curr = curr->right;
                }
            }
        }

    CODE: To find max xor for a given number if that number is xored from numbers from trie
        Advantage - The operation is done with the help of trie in O(max(n)) instead of O(n) 

        int findMaxXor(TrieNode *head, int n){
            TrieNode *curr = head;
            int curr_xor = 0;
            for(int i = 31; i>=0; i--){
                int b = (n>>i)&1;

                if(b == 0)
                    if(curr->right != NULL){
                        curr_xor += pow(2, i);
                        curr = curr->right;
                    }else
                        curr = curr->left;
                else
                    if(curr->left != NULL){
                        curr_xor += pow(2, i);
                        curr = curr->left;
                    }else
                        curr = curr->right;
            }
            return curr_xor;
        }

    MAIN: 

        int main(){
            int arr[6] = {1, 2, 3, 4, 5, 6};
            TrieNode *head = new TrieNode();
            for(int i = 0; i<6; i++){
                insert(arr[i], head);
            }
            int ans = INT_MIN;
            for(int i = 0; i<n; i++){
                int temp = findMaxXor(head, arr[i]);
                ans = (temp>ans)?temp:ans;
            }
            cout<<ans;
            return 0;
        }