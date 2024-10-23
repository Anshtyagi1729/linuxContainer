#include "NamespaceManager.h"
#include <stdlib.h>
void NamespaceManager::createNamespaces()
{
    if(unshare(CLONE_NEWPID|CLONE_NEWUSER|CLONE_NEWNS)==-1)
    {
        perror("unshare");
        exit(EXIT_FAILURE);
    }
    std::cout<<"namespaces are created succesfully"<<std::endl;
    //CAN ADD MOUNTS AND MORE FUNCTIONALITY FOR THE LINUX CONTAINER

}