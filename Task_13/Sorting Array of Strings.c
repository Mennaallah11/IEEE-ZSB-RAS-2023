#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b){
    int r = strcmp(a, b) > 0 ;
    return r;
}

int lexicographic_sort_reverse(const char* a, const char* b){
    int r = strcmp(a, b) < 0 ;
    return r;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){
    int l_1 = 0, l_2 = 0;
    int arr_1[50] = {0}, arr_2[50] = {0};
    int length_1 = strlen(a);
    int length_2 = strlen(b);

    for(int i = 0; i < length_1; i++){
        arr_1[a[i] - 'a'] = 1;   
    }

    for(int i = 0; i < length_2; i++){
        arr_2[b[i] - 'a' ] = 1;   
    }

    for(int i = 0; i < 50; i++){
        if(arr_1[i])
            l_1++;
        if(arr_2[i])
            l_2++;
    }
    if( l_1 != l_2)
        return l_1 > l_2;
    else
        return strcmp(a, b)  > 0;

}

int sort_by_length(const char* a, const char* b){
    if(strlen(a) != strlen(b))
        return strlen(a) > strlen(b) ;   
    else
        return strcmp(a, b) > 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        int j = i;
        char* p = arr[i];
        while(j > 0){
            if((*cmp_func)(arr[j-1],p) > 0 )
                arr[j] = arr[j-1];
            else
                break;
            j--;
        }
        arr[j] = p;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
  arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}