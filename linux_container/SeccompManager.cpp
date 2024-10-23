#include "seccompManager.h"
#include<stdlib.h>
void SeccompManager::setupSeccomp()
{
    scmp_filter_ctx ctx=seccomp_init(SCMP_ACT_KILL);
    //could also have used seccomp_init(scmp_act_kill)
    //this would have killed the thread if the container access somthing htat was not allowed
    if(!ctx)
    {
        perror("seccomp");
        exit(EXIT_FAILURE);
    }
    seccomp_rule_add(ctx,SCMP_ACT_ALLOW,SCMP_SYS(read),0);
    seccomp_rule_add(ctx,SCMP_ACT_ALLOW,SCMP_SYS(write),0);
    seccomp_rule_add(ctx,SCMP_ACT_ALLOW,SCMP_SYS(exit),0);
    seccomp_load(ctx);
    seccomp_release(ctx);
    std::cout<<"seccomp filter deployed successfully"<<std::endl;

};