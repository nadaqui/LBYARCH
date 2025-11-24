#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calculates accelaration without calling assembly function.
void acc(int y, float *arr, int *res){
	float con = 0.27777777777; 	  // 1000M/H / 3600s
	float vi = 0;
	float vf = 0;
	float time = 0;
	int ans = 0;
	
	for (int i = 0; i < y; i++){
		vi = arr[i * 3 + 0];  	 // initial velocity
		vf = arr[i * 3 + 1]; 	 // final velocity
		time = arr[i * 3 + 2];	 // time
		
		vf = vf - vi; 			 // Vf - Vi
		vf = vf * con;	 		 // Convert kh/hr to m/s
		vf = vf / time;	 		 // (Vf - Vi) / t
		
		ans = (int)nearbyint(vf); // Convert to int (RTN-TE)
		res[i] = ans;
	}
}

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

    // Call C function
    acc(y, matrix, res);

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
