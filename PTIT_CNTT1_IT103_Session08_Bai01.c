#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int key);

int main() {
    int n;
    int x;

    printf("Moi ban nhap vao so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong!");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap vao phan tu tai vi tri %d", i);
        scanf("%d", &arr[i]);
    }

    printf("Moi ban nhap vao phan tu can tim kiem: ");
    scanf("%d", &x);

    if (binarySearch(arr, n, x) != -1) {
        printf("Vi tri cua phan tu: %d", binarySearch(arr,n,x));
    } else {
        printf("Khong tim thay phan tu trong mang!");
    }
    free(arr);
    return 0;
}

int binarySearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}