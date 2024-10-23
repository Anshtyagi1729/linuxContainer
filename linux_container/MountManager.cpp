#include "MountManager.h"
#include <sys/stat.h>
#include <sys/mount.h>
#include <unistd.h>
#include <iostream>
#include <cstring> 

void MountManager::setupMounts(const char* mount_dir) {
    // Attempt to mount a tmpfs filesystem at the specified mount_dir
    if (mount("none", mount_dir, "tmpfs", 0, nullptr) == -1) {
        std::cerr << "Error mounting tmpfs at " << mount_dir << ": " << strerror(errno) << std::endl;
        return; 
    }
    // Here you could add more mounts as needed
    if (mount("proc", "/proc", "proc", 0, nullptr) == -1) {
        std::cerr << "Error mounting proc filesystem: " << strerror(errno) << std::endl;
        return;
    }
    

    std::cout << "Mounts have been successfully deployed at " << mount_dir << std::endl;
}
