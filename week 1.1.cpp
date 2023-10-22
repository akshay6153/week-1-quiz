#include "stats.h"
#include <stdio.h>
#include <stdlib.h>

// Function to compare for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void analyze_data(const unsigned char *data, size_t size, int *max, int *min, int *mean, int *median) {
    // Initialize variables
    int sum = 0;
    int *sorted_data = malloc(size * sizeof(int));

    // Convert data to integers and calculate sum
    for (size_t i = 0; i < size; i++) {
        sorted_data[i] = (int)data[i];
        sum += sorted_data[i];
    }

    // Calculate mean
    *mean = sum / size;

    // Sort the data
    qsort(sorted_data, size, sizeof(int), compare);

    // Calculate min and max
    *min = sorted_data[0];
    *max = sorted_data[size - 1];

    // Calculate median
    if (size % 2 == 0) {
        *median = (sorted_data[size / 2 - 1] + sorted_data[size / 2]) / 2;
    } else {
        *median = sorted_data[size / 2];
    }

    free(sorted_data);
}

void print_statistics(const int max, const int min, const int mean, const int median) {
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Mean: %d\n", mean);
    printf("Median: %d\n", median);
}

int main() {
    unsigned char data[] = {42, 12, 78, 36, 99, 2, 54, 92, 33, 15};
    size_t size = sizeof(data) / sizeof(data[0]);

    int max, min, mean, median;

    analyze_data(data, size, &max, &min, &mean, &median);
    print_statistics(max, min, mean, median);

    return 0;
}
