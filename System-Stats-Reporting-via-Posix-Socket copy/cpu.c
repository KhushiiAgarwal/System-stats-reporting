#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cpu_type {
    char cpu_model[255];
} CPU;

CPU cpuDetails() {
    FILE *fp;
    char buffer[1024];
    char *cpu_info = NULL;
    size_t size = 0;

    // Open a pipe to the sysctl command
    fp = popen("sysctl -n machdep.cpu.brand_string", "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        exit(EXIT_FAILURE);
    }

    // Read the output of sysctl into the buffer
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp); // close the pipe

    // Allocate memory for the CPU info string and copy the line to it
    size = strlen(buffer) + 1;
    cpu_info = malloc(size);
    if (cpu_info == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    strcpy(cpu_info, buffer);

    CPU CPU1;

    if (cpu_info != NULL) {
        // printf("CPU info: %s\n", cpu_info);
        strcpy(CPU1.cpu_model, cpu_info);
    } else {
        printf("CPU info not found\n");
    }

    free(cpu_info); // Free the allocated memory
    return CPU1;
}

// int main(int argc, char const *argv[]) {
//     CPU cpu_info = cpuDetails();
//     printf("CPU info: %s\n", cpu_info.cpu_model);

//     return 0;
// }
