#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int num_elements;
    printf("Masukkan jumlah bilangan bulat (n): ");
    scanf("%d", &num_elements);

    if (num_elements <= 0) {
        printf("Jumlah bilangan harus positif. Program berakhir.\n");
        return 1;
    }

    int arr[num_elements];
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    printf("Masukkan %d bilangan bulat (antara -100 hingga 100):\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < -100 || arr[i] > 100) {
            printf("Error: Bilangan harus antara -100 hingga 100. Program berakhir.\n");
            return 1;
        }

        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    float min_avg_consecutive = FLT_MAX;
    float max_avg_consecutive = FLT_MIN;

    if (num_elements >= 2) {
        for (int i = 0; i < num_elements - 1; i++) {
            float current_avg = (float)(arr[i] + arr[i+1]) / 2.0;
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }
    }
    
    printf("\n--- Hasil Analisis Bilangan ---\n");
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    if (num_elements >= 2) {
        printf("%.2f\n", min_avg_consecutive);
        printf("%.2f\n", max_avg_consecutive);
    } else {
        printf("Rata-rata dua nilai berturut-turut tidak dapat dihitung karena jumlah bilangan kurang dari 2.\n");
    }

    return 0;
}
