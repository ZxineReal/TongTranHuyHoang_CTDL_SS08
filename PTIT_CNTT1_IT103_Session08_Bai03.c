#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size);

int main() {
    int n;
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
        printf("Moi ban nhap vao phan tu tai vi tri %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);
    printf("Mang sau khi sap xep la:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
