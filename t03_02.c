#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN

int main() {
    int n;

    printf("Masukkan jumlah bilangan (N): ");
    scanf("%d", &n);

    if (n < 2) { // Validasi untuk rata-rata berturut-turut
        printf("Jumlah bilangan N harus minimal 2 untuk menghitung rata-rata berturut-turut.\n");
        return 1;
    }

    int arr[n];

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    double min_avg_consecutive = 201.0; // Inisialisasi lebih tinggi dari rata-rata maksimum yang mungkin (100)

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

    // Menghitung rata-rata terendah dari dua nilai berturut-turut
    for (int i = 0; i < n - 1; i++) {
        double current_avg = (double)(arr[i] + arr[i+1]) / 2.0;
        if (current_avg < min_avg_consecutive) {
            min_avg_consecutive = current_avg;
        }
    }

    printf("\n");
    printf("%d\n", minVal);
    printf("%d\n", maxVal);
    printf("%.2f\n", min_avg_consecutive); // Tambahan output

    return 0;
}
