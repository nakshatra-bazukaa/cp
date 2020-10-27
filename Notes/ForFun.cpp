1.) Merge sort
	
	void merge(int part1[], int part2[], int size1, int size2, int output[]){
	    int i = 0, j = 0, k = 0;
	    while(i<size1 && j<size2) output[k++] = part1[i] < part2[j] ? part1[i++] : part2[j++];
	    while(i<size1) output[k++] = part1[i++];
	    while(j<size2) output[k++] = part2[j++];
	}
	void merge_sort(int input[], int size){
	    if(size <= 1) return;
	    int size1 = size/2, size2 = size-size1, part1[size1], part2[size2], k = 0;
	    for(int i = 0; i<size1; i++) part1[i] = input[i];
	    for(int i = size1; i<size; i++) part2[k++] = input[i];
	    merge_sort(part1, size1);
	    merge_sort(part2, size2);
	    merge(part1, part2, size1, size2, input);
	}

2.) Quick Sort
	
	int find_pivot(int input[], int size){
		int pivot = 0;
		for(int i = 1; i<size; i++)
			if(input[i] <= input[0]){
				int t = input[i];
				for(int j = i; j>pivot; j--)
					input[j] = input[j-1];
				input[pivot++] = t;
			}
		return pivot;
	}
	void quick_sort(int input[], int size){
		if(size <= 1) return;
		int pivot = find_pivot(input, size);
		quick_sort(input, pivot);
		quick_sort(input+pivot+1, size-pivot-1);
	}

