 int lengthOfLongestSubstring(char* s) {
    int start = 0;
    int end = 0;
    int maxLength = 0;
    int len = strlen(s);
    int charSet[200] ;  
    
        for (int i = 0 ; i < 200; i ++){
            charSet[i]=-1 ;
        }
        while (end < len){
        if (charSet[s[end]] >= start) {
            start = charSet[s[end]] + 1  ;
        }
        charSet[s[end]] = end;
        
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
        
        end++;
    }
    
    return maxLength;
}