/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 02 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Hamzah Abdul Rahim (13224066)
 *   Nama File           : soal1modul2.c
 *   Deskripsi           : Soal 1 - Pemulihan Sensor Fragmen
 * 
 */

#include <stdio.h>

void recover(int arr[], int n){
    for(int i = n-1;i>=0;i--){
        int right, left;
        if(i == n-1){
            right = -1;
        }
        if(i == 0){
            left = -1;
        }
        if(i!=0 && i!=n-1){
            right = arr[i+1];
            left = arr[i-1];
        }
        if(arr[i]==-1){
            if(right != -1 && left != -1){
                arr[i] = (right+left)/2;
            }
            else if(left != -1){
                arr[i] = left;
            }
            else if(right != -1){
                arr[i] = right;
            }
            else{
                arr[i] = 0;
            }
        }
    }
}





int main(){
    int N;
    int data[100000];

    scanf("%d", &N);

    for(int i=0;i<N;i++){
        scanf("%d", &data[i]);
    }

    recover(data, N);
    int sum = 0;
    printf("RECOVERED ");
    for(int i = 0; i<N;i++){
        sum += data[i];
        printf("%d", data[i]);
        if(i<N-1){
            printf(" ");
        }
        else if(i == N-1){
            printf("\n");
        }
    }

    printf("MAX_SUM %d\n", sum);

    


}
