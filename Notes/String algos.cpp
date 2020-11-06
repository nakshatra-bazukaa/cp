1.) KMP O(n + m) { n - length of string, m - length of pattern}

    Code:
        int* getLps(string pattern){
            int len = pattern.length();
            int *lps = new int[len];

            int i = 1, j = 0;
            lps[0] = 0;
            while(i<len)
                if(pattern[i] == pattern[j])
                    lps[i++] = (j++)+1;
                else if(j != 0)
                    j = lps[j-1];
                else
                    lps[i++] = 0;

            return lps;
        }
        bool kmpSearch(string text, string pattern){
            int lenText = text.length();
            int lenPat = pattern.length();

            int i = 0, j = 0;
            int *lps = getLps(pattern);
            
            while(i<lenText && j<lenPat)
                if(text[i] == pattern[j]){
                    i++;
                    j++;
                }
                else if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            if(j == lenPat)
                return true;
            return false;
        }

2.) Z-Algo O(n) { n - length of string }

    returns indexes at which pattern is present in the text

    CODE: 
        void build(int *Z, string str){
            int l = 0, r = 0, n = str.length();

            for(int i = 1; i<n; i++){
                if(i>r){
                    //  i does not lie between l and r
                    // Z for this dosnt exist
                    l = i;
                    r = i;
                    while(r<n && str[r-l] == str[r])
                        r++;
                    Z[i] = r-l;
                    r--;
                }else{
                    int k = i-l;
                    if(Z[k]<=r-i)
                        // i lies between l and r
                        // Z will exist previously
                        Z[i] = Z[k];
                    else{
                        // Some part of Z is already included
                        // You have to start matching further
                        l = i;
                        while(r<n && str[r-l] == str[r])
                            r++;
                        Z[i] = r-l;
                        r--;
                    }
                }
            }
        }
        void searchString(string text, string pattern){
            string str = pattern + "$" + text;
            int n = str.length();
            int *Z = new int[n]();
            build(Z, str);
            for(int i = 0; i<n; i++)
                if(Z[i] == pattern.length())
                    cout<<i - pattern.length() - 1<<endl;
        }