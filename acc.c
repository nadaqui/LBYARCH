#include <stdio.h>
#include <stdlib.h>

// Assembly to output acceleration (as integer)
extern void asmacc(int y, float *arr, int *res);

// C is responsible for: collecting the inputs, allocating memory spaces for the images, and printing the outputs.
int main() {
    int y;
    printf("Input Y: ");
    scanf("%d", &y);

    // Allocate arrays
    float *matrix = malloc(y * 3 * sizeof(float));
    int   *res    = malloc(y *     sizeof(int));
    if (!matrix || !res) {
        perror("malloc failed");
        free(matrix);
        free(res);
        return 1;
    }

    printf("Input matrix (Y rows, 3 floats each):\n");
    for (int i = 0; i < y; i++) {
        if (scanf("%f %f %f", &matrix[i*3], &matrix[i*3+1], &matrix[i*3+2]) != 3) {
            printf("Invalid input.\n");
            free(matrix);
            free(res);
            return 1;
        }
    }

    // Call assembly
    asmacc(y, matrix, res);

    // Print results
    int num = 1;
    for (int i = 0; i < y; i++) {
        printf("Car %d acceleration: %d\n", num, res[i]);
        num++;
    }

    free(matrix);
    free(res);
    return 0;
}
