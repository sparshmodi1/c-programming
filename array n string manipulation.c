#include<stdio.h>   
#include<stdlib.h>


//CRUD OPERATION USING CALLOC DYNAMIC MEMORY ALLOCATION
int read(int *arr, int n){
    for(int i =0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void add(int *arr, int value, int n){
    for(int i =0; i < n; i++){
        if(arr[i]==0){
            arr[i]=value;
            break;
        }
    }
}

void update(int *arr,int pos, int value, int n){
    for(int i =0; i < n; i++){
        if(i==pos){
            arr[i] = value;
        }
    }
}

//take hints from ai to build this function regarding shifting and position validation
void delete(int *arr, int pos, int *n){
    if(0<=pos && pos<=2){
        for (int i = pos; i < *n-1; i++){
            arr[i] = arr[i+1];
        }

        (*n)--;
    }
}

int main(){
    int n = 3;
    int *arr = calloc(n, sizeof(int)); 

    add(arr, 1, n);
    add(arr, 2, n);
    add(arr, 3, n);

    read(arr, n);

    printf("\n");

    update(arr, 0, -1, n);
    read(arr, n);

    delete(arr, 0, &n);
    printf("\n");

    read(arr, n);

    return 0;
}


//CRUD using static arrays 

void add(int arr[], int value, int s){
    for (int i = 0; i < s; i++){
        if(arr[i]==0){
            arr[i] = value;
            break;
        }
    }
}

void update(int arr[], int pos, int value, int s){
    for(int i =0; i < s; i++){
        if(i==pos){
            arr[i]=value;
        }
    }
}

void delete(int arr[], int pos, int s){
    for(int i =pos; i < s-1; i++){
        arr[i] = arr[i+1];
    }
    arr[s - 1] = 0;
}

int printarr(int arr[], int s){
    for(int i =0; i < s; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
int main(){
    int arr[3] = {0};
    int s = sizeof(arr)/sizeof(arr[0]);
    add(arr, 1, s);
    add(arr, 3, s);
    add(arr, 4, s);

    printarr(arr, s);

    update(arr, 1, 2, s);
    printarr(arr, s);

    delete(arr, 1, s);
    printarr(arr, s);

    return 0;
}



//CRUD IN 2D ARRAY
void add(int arr[3][4],  int value){
    for(int i =0; i < 3; i++){
        for(int j =0; j < 4; j++){
            if(arr[i][j] == 0 || arr[i][j] == -1){
                arr[i][j] = value;
                return;
            }
            
        }
    }
}

void update(int arr[3][4], int r, int c, int value){
    if(r >= 0 && r < 3 && c >= 0 && c < 4){
        arr[r][c] = value;
    }
}

void delete(int arr[3][4], int r, int c) {
    if (r < 0 || r >= 3 || c < 0 || c >= 4) {
        printf("Invalid position \n");
        return;
    }

    arr[r][c] = -1;
}

void print2darr(int arr[3][4]){
    for(int i =0; i < 3; i++){
        for(int j =0; j < 4; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int arr[3][4] = {0};
    add(arr, 5);
    add(arr, 6);
    add(arr, 7);
    add(arr, 8);
    add(arr, 9);
    add(arr, 10);
    add(arr, 11);
    add(arr, 12);

    print2darr(arr);

    delete(arr, 1, 1);
    print2darr(arr);
}


//reversing string in C
void reverse(char str[], int n){
    int i =0;
    int j = n-1;
    while(i < j){
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }

}

int printstr(char str[], int n){
    for(int i =0; i < n; i++){
        printf("%c ", str[i]);
    }
    return 0;
}

int main(){
    int n;
    scanf("%d\n", &n);

    char str[n];
    scanf("%[^\n]", str);

    reverse(str, n);
    printstr(str, n);

    return 0;
}

//swapping array rows in 2D array

void swapRows(int arr[3][4], int r1, int r2) {
    if (r1 < 0 || r1 >= 3 || r2 < 0 || r2 >= 3) {
        printf("Invalid \n");
        return;
    }

    for (int j = 0; j < 4; j++) {
        int temp = arr[r1][j];
        arr[r1][j] = arr[r2][j];
        arr[r2][j] = temp;
    }
}

int main(){
    
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    swapRows(arr, 0, 2);
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}


//traversing string using pointers
int main(){
    char str[] = "HEllo";
    char *ptr = str;

    int size = sizeof(str)/sizeof(str[0]);
    
    for(int i =0; i < size; i++){
        printf("%c", *(ptr + i));
    }
}
