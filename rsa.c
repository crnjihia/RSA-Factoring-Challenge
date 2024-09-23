#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(unsigned long long num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (unsigned long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to factorize a number into two prime factors
void rsa_factorize(unsigned long long num) {
    unsigned long long i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0 && is_prime(i) && is_prime(num / i)) {
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
        rsa_factorize(num);
    }

    fclose(file);
    return 0;
}
