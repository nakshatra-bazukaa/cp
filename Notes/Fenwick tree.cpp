- Also called BIT(Binary indexed tree)
- Intution: range query problems
- Application similar to segment tree

Why we study it?
    - Coding it is very easy 
    - It takes very less space O(n)

To go to the parent node of a node?
    - Flip the rightmost set bit of the index of the node you are currently at
    How??
        Step 1.) 2's complement 
        Step 2.) And it with orignal number
        Step 3.) Subtract from orignal number

    CODE LOGIC:
        parentIndex = childIndex - (childIndex & (-childIndex))

-------------------------------------------------------------------------------------------------

CODE: 
    Update function
    void update(int index, int value, int *BIT, int n){
        for(; index <= n; index += index&(-index))
            BIT[index] += value;
    }

CODE:
    Query function
    int query(int index, int *BIT){
        int sum = 0;
        for(; index > 0; index -= index&(-index))
            sum += BIT[index];
        return sum;
    }

MAIN:
    int main(){
        int n;
        cin>>n;
        
        int *arr = new int[n+1]();
        int *BIT = new int[n+1]();

        for(int i = 1; i<n; i++){
            cin>>arr[i];
            update(i, arr[i], BIT, n);
        }

        cout<<"Sum of first k elements "<< query(k, BIT)<<endl;
        cout<<"Sum of elements from l to r indexs"<<query(r, BIT)-query(l-1, BIT)<<endl;
    }