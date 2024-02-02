#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
#include <string.h>

typedef struct os_type {
    char system[1023];
    char node[1023];
    char os[1023];
    char machine[1023];
} OS;

OS osdetails() {
    struct utsname buf1;
    errno = 0;

    if (uname(&buf1) != 0) {
        perror("uname doesn't return 0, so there is an error");
        exit(EXIT_FAILURE);
    }

    OS os1;

    // Use strncpy to avoid buffer overflow
    strncpy(os1.system, buf1.sysname, sizeof(os1.system) - 1);
    os1.system[sizeof(os1.system) - 1] = '\0'; // Ensure null-termination

    strncpy(os1.node, buf1.nodename, sizeof(os1.node) - 1);
    os1.node[sizeof(os1.node) - 1] = '\0';

    strncpy(os1.os, buf1.version, sizeof(os1.os) - 1);
    os1.os[sizeof(os1.os) - 1] = '\0';

    strncpy(os1.machine, buf1.machine, sizeof(os1.machine) - 1);
    os1.machine[sizeof(os1.machine) - 1] = '\0';

    // Print the information (optional)
    // printf("System Name = %s\n", os1.system);
    // printf("Node Name = %s\n", os1.node);
    // printf("Version = %s\n", os1.os);
    // printf("Machine = %s\n", os1.machine);

    return os1;
}

// int main(int argc, char const *argv[]) {
//     OS os_info = osdetails();
//    //  // Print the information (optional)
//    //  printf("System Name = %s \n", os_info.system);
//    //  printf("Node Name = %s \n", os_info.node);
//    //  printf("Version = %s \n", os_info.os);
//    //  printf("Machine = %s \n", os_info.machine);

//     return 0;
// }
