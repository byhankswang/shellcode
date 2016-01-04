# shellcode
Shellcode for x86/x86-64 and ARM platform.



Architecture calling conventions
    Every architecture has its own way of invoking and passing arguments to the kernel.  The details for various architectures are listed in the two tables below.

    The first table lists the instruction used to transition to kernel mode, (which might not be the fastest or best way to transition to the kernel, so you might have  to  refer  to
    the VDSO), the register used to indicate the system call number, and the register used to return the system call result.

    arch/ABI   instruction          syscall #   retval Notes
    ───────────────────────────────────────────────────────────────────────────────────
    arm/OABI   swi NR               -           a1     NR is syscall #
    arm/EABI   swi 0x0              r7          r0
    blackfin   excpt 0x0            P0          R0
    i386       int $0x80            eax         eax
    ia64       break 0x100000       r15         r10/r8
    parisc     ble 0x100(%sr2, %r0) r20         r28
    s390       svc 0                r1          r2     NR may be passed directly with

    s390x      svc 0                r1          r2     "svc NR" if NR is less than 256
    sparc/32   t 0x10               g1          o0
    sparc/64   t 0x6d               g1          o0
    x86_64     syscall              rax         rax

    The second table shows the registers used to pass the system call arguments.

    arch/ABI   arg1   arg2   arg3   arg4   arg5   arg6   arg7
    ──────────────────────────────────────────────────────────
    arm/OABI   a1     a2     a3     a4     v1     v2     v3
    arm/EABI   r0     r1     r2     r3     r4     r5     r6
    blackfin   R0     R1     R2     R3     R4     R5     -
    i386       ebx    ecx    edx    esi    edi    ebp    -
    ia64       r11    r9     r10    r14    r15    r13    -
    parisc     r26    r25    r24    r23    r22    r21    -
    s390       r2     r3     r4     r5     r6     r7     -
    s390x      r2     r3     r4     r5     r6     r7     -
    sparc/32   o0     o1     o2     o3     o4     o5     -
    sparc/64   o0     o1     o2     o3     o4     o5     -
    x86_64     rdi    rsi    rdx    r10    r8     r9     -

    Note that these tables don't cover the entire calling convention—some architectures may indiscriminately clobber other registers not listed here.

