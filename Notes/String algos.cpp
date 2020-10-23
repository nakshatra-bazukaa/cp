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
