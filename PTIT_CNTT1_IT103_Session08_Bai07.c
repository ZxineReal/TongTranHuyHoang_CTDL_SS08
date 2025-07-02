#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

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
        printf("Moi ban nhap vao phan tu tai vi tri %d", i);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

void quickSort(int arr[], int left, int right) {
    int pivot = arr[right];
    if (left < right) {
        int pivotPos = partition(arr, left, right);
        quickSort(arr, left, pivotPos - 1);
        quickSort(arr, pivotPos + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}