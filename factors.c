#include <stdio.h>
#include <stdlib.h>

// Function to factorize a number into two factors
void factorize(unsigned long long num) {
    unsigned long long i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            printf("%llu=%llu*%llu\n", num, i, num / i);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    unsigned long long num;
    
    // Read each number from the file and factorize it
    while (fscanf(file, "%llu", &num) != EOF) {
        factorize(num);
    }

    fclose(file);
    return 0;
}
