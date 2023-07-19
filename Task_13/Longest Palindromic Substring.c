char * longestPalindrome(char * s){
    int length_s = strlen(s);
    int maxLength = 1; 
    int start = 0;      
    int palindrome[length_s][length_s] ;
     memset(palindrome, 0, sizeof(palindrome));


    /*for (int i = 0 ; i<length_s ; i++){
         for (int j = 0 ; j<length_s ; j++){
             palindrome[i][j]=0;
         }

    }*/
    for (int i = 0; i < length_s; i++) {
        palindrome[i][i] = 1;
    }
 
    for (int i = 0; i < length_s-1; i++) {
        if (s[i] == s[i+1]) {
            palindrome[i][i+1] = 1;
            maxLength = 2;
            start = i;
        }
    }
     for (int length_3ormore = 3;  length_3ormore <= length_s; length_3ormore++) {                        
        for (int i = 0; i < length_s - length_3ormore + 1; i++) {                       
            int j = i + length_3ormore - 1;                    
            if (s[i] == s[j] && palindrome[i+1][j-1]) {
                palindrome[i][j] = 1;
                if (length_3ormore > maxLength) {
                    start = i;
                    maxLength = length_3ormore;
                }
            }
        }
    }

  if (length_s == 0) return "";       
    if (length_s == 1) return s;     

    char* result = malloc(sizeof(char) * (maxLength + 1)); 
    strncpy(result, s + start, maxLength); 
    result[maxLength] = '\0'; 
    return result;
}