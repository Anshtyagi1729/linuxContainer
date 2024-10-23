#include "NamespaceManager.h"
#include "CgroupManager.h"
#include "seccompManager.h"
#include "MountManager.h"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <mount_dir> <command>" << std::endl;
        return 1;
    }
    const char *mount_dir = argv[1];
    const char *command = argv[2];
    NamespaceManager nsManager;
    CgroupManager cgroupManager;
    SeccompManager seccompManager;
    MountManager mountManager;
    nsManager.createNamespaces();

    std::cout << "Container environment set up. Executing command..." << std::endl;
    return 0;
}
