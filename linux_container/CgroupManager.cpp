#include "CgroupManager.h"
#include<sys/stat.h>
#include<unistd.h>
void CgroupManager::setupCgroups()
{
    const char*cg_dir="/sys/fs/cgroup/my_container";
    mkdir(cg_dir,0755);
    //the above line makes a directory in the cg_dir and gives it permission of 0755
    //we can add more cgroups like for the management for the memory adn cpu stuff like that
    std::cout<<"cgroups are setup successfull"<<std::endl;
}