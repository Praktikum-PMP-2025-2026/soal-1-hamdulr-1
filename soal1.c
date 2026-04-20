/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 02 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Hamzah Abdul Rahim (13224066)
 *   Nama File           : soal1modul2.c
 *   Deskripsi           : Soal 1 - Pemulihan Sensor Fragmen
 * 
 */

#include <stdio.h>

int floors(float n){
    int intpart;
    float fracpart;
    intpart = (int)n;
    fracpart = (float)n-intpart;
    if(fracpart == 0){
        return (int)n;
    }
    else{
        if(n>=0){
            return intpart;
        }
        else if(n<0){
            return intpart-1;
        }
    }
}

int findleft(int arr[], int idx, int n){
    if(idx == 0){
        return -1;
    }
    else{
        for(int i = idx-1;i>=0;i--){
            if(arr[i] !=-1){
                return arr[i];
            }
        }
        return -1;
    }
}

int findright(int arr[], int idx, int n){
    if(idx == n-1){
        return -1;
    }
    else{
        for(int i = idx+1;i<=n-1;i++){
            if(arr[i] !=-1){
                return arr[i];
            }
        }
        return -1;
    }
}
void recover(int arr[], int n){
    int right, left;
    for(int i = 0;i<n;i++){
        left = findleft(arr, i, n);
        right = findright(arr, i, n);
        if(arr[i]==-1){
            if(right != -1 && left != -1){
                float new;
                new = (float)(right+left)/2;
                int floornew;
                floornew = floors(new);
                arr[i] = floornew;
                //printf("FLOOR\n");
                
            }
            else if(left != -1){
                arr[i] = left;
                //printf("LEFT\n");
            }
            else if(right != -1){
                arr[i] = right;
                //printf("RIGHT\n");
            }
            else{
                arr[i] = 0;
                //printf("ZERO\n");
            }
        }
    }
}

void findmaxsub(int arr[], int n, int *res){
    int left = 0;
    int right = n-1;
    int maxsum = -9999999;
    int sum = 0;
    for(int i = left;i<=right;i++){
        for(int j = i;j<=right;j++){
            for(int k = i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum>=maxsum){
                maxsum = sum;
            }
            sum = 0;
        }
    }
    *res = maxsum;
}




int main(){
    int N;
    int data[100000];

    scanf("%d", &N);

    for(int i=0;i<N;i++){
        scanf("%d", &data[i]);
    }

    recover(data, N);
    printf("RECOVERED ");
    for(int i = 0; i<N;i++){
        printf("%d", data[i]);
        if(i<N-1){
            printf(" ");
        }
        else if(i == N-1){
            printf("\n");
        }
    }

    int sum;
    findmaxsub(data, N, &sum);
    printf("MAX_SUM %d\n", sum);

    


}
