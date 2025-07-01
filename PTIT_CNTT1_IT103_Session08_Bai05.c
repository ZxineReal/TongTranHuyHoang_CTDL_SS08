#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size);

int main() {
    int n;
    printf("Moi ban nhap vao so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!");
        return 0;
    }

    int* arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong!");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap vao phan tu tai vi tri %d: ",i);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau la:");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);
    printf("Mang sau khi sap xep la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }

    free(arr);
    return 0;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}