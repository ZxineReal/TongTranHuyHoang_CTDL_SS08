#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size);
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
        printf("Moi ban nhap vao phan tu tai vi tri %d:",i);
        scanf("%d", &arr[i]);
    }

    printf("Moi ban nhap vao phan tu can tim kiem: ");
    scanf("%d", &x);
    bubbleSort(arr, n);

    if (binarySearch(arr, n, x) != -1) {
        printf("Vi tri cua phan tu: %d", binarySearch(arr, n, x));
    } else {
        printf("Khong tim thay phan tu trong mang!");
    }
    free(arr);
    return 0;

}

void bubbleSort(int *arr, int size) {
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

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
