1.) Merge sort
	
	void m(int p1[], int p2[], int s1, int s2, int out[]){
	    int i = 0, j = 0, k = 0;
	    while(i<s1 && j<s2)
	        if(p1[i] < p2[j]) out[k++] = p1[i++];
	        else out[k++] = p2[j++];
	    while(i<s1) out[k++] = p1[i++];
	    while(j<s2) out[k++] = p2[j++];
	}
	void ms(int in[], int s){
	    if(s <= 1) return;
	    int s1 = s/2, s2 = s-s1, p1[s1], p2[s2], k = 0;
	    f(i, 0, s1) p1[i] = in[i];
	    f(i, s1, s) p2[k++] = in[i];
	    ms(p1, s1);
	    ms(p2, s2);
	    m(p1, p2, s1, s2, in);
	}

2.) Quick Sort
	
	int p(int in[], int s){
		int p = in[0], pi = 0;
		for(int i = 1; i<s; i++)
			if(in[i] <= p){
				int t = in[i];
				for(int j = i; j>pi; j--)
					in[j] = in[j-1];
				in[pi++] = t;
			}
		return pi;
	}
	void qs(int in[], int s){
		if(s <= 1) return;
		int pi = p(in, s);
		qs(in, pi);
		qs(in+pi+1, s-pi-1);
	}

