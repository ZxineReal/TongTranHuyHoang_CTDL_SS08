#include <stdio.h>
#include <stdlib.h>

void inputArr(int arr[], int size);
void printArr(int arr[], int size);
void insertionSort(int arr[], int size);
int linearSearch(int arr[], int size, int value);
int binarySearch(int arr[], int size, int value);

int main() {
    int choice;
    int n = 0;
    int* arr = NULL;
    int flag = 0;
    int x;

    do {
        printf("MENU\n");
        printf("1: Nhap mang\n");
        printf("2: In mang\n");
        printf("3: Sap xep mang\n");
        printf("4: Tim kiem phan tu\n");
        printf("0: Thoat chuong trinh\n");
        printf("Lua chon cua ban: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Moi ban nhap vao so luong phan tu: \n");
                scanf("%d", &n);
                if (n <= 0 || n >= 1000) {
                    printf("So luong phan tu khong hop le!\n");
                    break;
                }
                arr = malloc(sizeof(int) * n);
                if (arr == NULL) {
                    printf("Khong the cap phat bo nho dong!\n");
                    break;
                }
                inputArr(arr, n);

                break;
            case 2:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printArr(arr, n);
                break;
            case 3:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                insertionSort(arr, n);
                flag = 1;
                break;
            case 4:
                if (n == 0) {
                    printf("Mang rong!\n");
                    break;
                }
                printf("Moi ban nhap vao phan tu can tim kiem: ");
                scanf("%d", &x);

                if (flag == 0) {
                    printf("LinearSearch\n");
                    linearSearch(arr, n, x);
                    if (linearSearch(arr, n, x) != -1) {
                        printf("Vi tri cua phan tu trong mang la: %d\n", linearSearch(arr, n, x));
                    } else {
                        printf("Khong tim thay phan tu trong mang!\n");
                    }
                } else {
                    printf("BinarySearch\n");
                    binarySearch(arr, n, x);
                    if (binarySearch(arr, n, x) != -1) {
                        printf("Vi trong mang la: %d\n", binarySearch(arr, n, x));
                    } else {
                        printf("Khong tim thay phan tu trong mang!\n");
                    }
                }
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!");
                break;
        }

    } while (choice != 0);
}

void inputArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Moi ban nhap vao phan tu tai vi tri %d", i);
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int size) {
    printf("Array: \t");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    printf("Sap xep mang hoan tat!\n");
}

int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}