#include <stdio.h>
#include <stdbool.h>

#define NONE -1
#define ERROR 0

int get_input_and_is_legal (int n , int* arr);
int Find_Sum (int n ,int* arr);
void RunOnAllNum_and_PrintThePower (int n , int* arr);
int its_power_of2(int num);

int main(){
    int n = 0;
    int sum = 0;
    printf("Enter size of input:\n");
    scanf("%d",&n);
    if( n <= 0){
        printf("Invalid size\n");
        return 0;
    }
    int* arr = malloc(sizeof(int)*n);
    if(arr == NULL){
        free(arr);
        return 0;
    }
    printf("Enter numbers:\n");
    if(!get_input_and_is_legal (n ,arr)){
        free(arr);
        return 0;
    }
    RunOnAllNum_and_PrintThePower (n , arr);
    sum=Find_Sum(n,arr);
    printf("Total exponent sum is %d" , sum);
    free(arr);
    return 0;
}
int Find_Sum (int n ,int* arr){
    int sum=0;
    for(int i=0 ; i < n ; i++){
        if(arr[i] != NONE)
            sum+=arr[i];
    }
    return sum;
}
void RunOnAllNum_and_PrintThePower (int n , int* arr){
    for(int i=0 ; i < n ; i++){
        int j = its_power_of2(arr[i]);
        if (j != NONE)
            printf("The number %d is a power of2: %d = 2^%d \n",arr[i],arr[i],j);
        arr[i] = j;
    }
}
int get_input_and_is_legal (int n , int* arr){
    for(int i=0 ; i < n ; i++){
        if(scanf("%d",arr+i)!=1){
            printf("Invalid number\n");
            return ERROR;
        }
    }
}
int its_power_of2(int num){
    int j=0;
    while(num != 1){
        if(num <=0 || num%2 != 0)
            return NONE;
        j++;
        num /= 2;
    }
    return j;
}
