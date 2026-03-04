#include <stdio.h> 
#include <limits.h> 

int main() {
    int n;

    printf("Masukkan jumlah bilangan (N): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah bilangan N harus lebih besar dari 0.\n");
        return 1;
    }

    int arr[n];

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    printf("Masukkan %d bilangan bulat (antara -100 hingga 100):\n", n);
    for (int i = 0; i < n; i++) {
        int currentNum;
        printf("Bilangan ke-%d: ", i + 1);
        scanf("%d", &currentNum);

        if (currentNum < -100 || currentNum > 100) {
            printf("Peringatan: Bilangan %d berada di luar rentang -100 hingga 100. Tetap diproses.\n", currentNum);
        }
        
        arr[i] = currentNum;

        if (arr[i] < minVal) {
            minVal = arr[i];
        }

        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    printf("\nOutput Program:\n");
    printf(" %d\n", minVal);
    printf("%d\n", maxVal);

    return 0;
}
