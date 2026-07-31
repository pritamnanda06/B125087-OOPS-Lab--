#include <stdio.h>

int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i + 1; 
        }
    }
    return -1; 
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int position = linearSearch(arr, n, target);

    if (position != -1) {
        printf("Element found at position: %d\n", position);
    } else {
        printf("Element not found\n");
    }

    return 0;
}