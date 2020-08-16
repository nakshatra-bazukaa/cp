ALGORITHIMS :-

	1.) Merge Sort

		void merge(int part1[], int part2[], int size1, int size2, int output[]){
			int i = 0, j = 0, k = 0;
			
			while(i < size1 && j < size2)
				if(part1[i] < part2[j])
					output[k++] = part1[i++];
				else
					output[k++] = part2[j++];

			while(i < size1)
				output[k++] = part1[i++];

			while(j < size2)
				output[k++] = part2[j++];
		}
		void merge_sort(int input[], int size){
			if(size <= 1)
				return;

			int mid = size/2;
			int size1 = mid, size2 = size-mid;
			int part1[size1], part2[size2];
			
			for(int i = 0; i < mid; i++)
				part1[i] = input[i];
			int k = 0;
			for(int i = mid; i<size; i++)
				part2[k++] = input[i];

			merge_sort(part1, size1);
			merge_sort(part2, size2);
			merge(part1, part2, size1, size2, input);
		}

	2.) Quick Sort
		
		int partition_array(int input[], int size){
			int pivot = input[0], pivotIndex = 0;

			for(int i = 1; i < size; i++)
				if(input[i] <= pivot){
					int temp = input[i];
					for(int j = i; j>pivotIndex; j--)
						input[j] = input[j-1];
					input[pivotIndex++] = temp;
				}
			return pivotIndex;
		}
		void quick_sort(int input[], int size){
			if(size <= 1)
				return;

			int pivotIndex = partition_array(input, size);
			quick_sort(input, pivotIndex);
			quick_sort(input+pivotIndex+1, size-pivotIndex-1);
		}	

	3.) To implement Binary Search
		
		int start = 0, end = vmax;
		while(start <= end){
			int mid = start + (end-start)/2;
			if(check(mid) == true){
				ans = mid;
				start = mid+1;
			}else
				end = mid-1;
		}

DATA STRUCTURES :-

		1.) Linked List
			
			class Node{
				public:
				    int data;
				    Node *next;
				    Node(int data){
				        this -> data = data;
				        this -> next = NULL;
				    }
			};
