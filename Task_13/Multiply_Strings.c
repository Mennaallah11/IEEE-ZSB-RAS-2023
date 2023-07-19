char * multiply(char * num1, char * num2){
    int Multiply ;
    int sum = 0;
    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);
    int x = len_num1 + len_num1 ;
    
    char* result = (char*)calloc(len_num1 + len_num1+1,sizeof(char));       
    for(int i=0 ; i< len_num1; i++){
        for(int j=0 ; j<len_num2 ; j++){
              int lenResult= i + j + 1 ;
              Multiply = (num1[i] - '0') * (num2[j] - '0');
              for (lenResult ; Multiply != '\0' ; lenResult --){
                  Multiply +=result[lenResult];
                  result[lenResult] = Multiply %10;
                  Multiply = Multiply / 10;
              }
        }
    }
    if(num1[0]=='0' || num2[0]=='0') 
    return "0"; 
    for(int i=0 ; i<x; i++){
        result[i] += '0';
    }
    if(result[0]=='0') return result+1;
    return result;
}