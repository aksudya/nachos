# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the network assignment
#    Defines set up assuming this assignment is done last 
#    If not, use the "bare bones"  defines below. 
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DVM -DFILESYS_NEEDED -DFILESYS -DNETWORK
INCPATH = -I../network -I../bin -I../filesys -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H) $(FILESYS_H) $(NETWORK_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C) $(FILESYS_C) $(NETWORK_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O) $(FILESYS_O) $(NETWORK_O)

# bare bones version
# DEFINES =-DTHREADS -DNETWORK
# INCPATH = -I../network -I../threads -I../machine
# HFILES = $(THREAD_H) $(NETWORK_H)
# CFILES = $(THREAD_C) $(NETWORK_C)
# C_OFILES = $(THREAD_O) $(NETWORK_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h ../threads/dllist.h
list.o: ../threads/list.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scheduler.o: ../threads/scheduler.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/scheduler.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
synch.o: ../threads/synch.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synch.h ../threads/thread.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h
synchlist.o: ../threads/synchlist.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synchlist.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/synch.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h
system.o: ../threads/system.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
thread.o: ../threads/thread.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/thread.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/switch.h ../threads/synch.h \
 ../threads/list.h ../threads/system.h ../threads/scheduler.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h
utility.o: ../threads/utility.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/stdarg.h
threadtest.o: ../threads/threadtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h \
 ../threads/dllist.h
dllist.o: ../threads/dllist.cc /usr/include/stdc-predef.h \
 ../threads/dllist.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
dllist-driver.o: ../threads/dllist-driver.cc /usr/include/stdc-predef.h \
 ../threads/dllist.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
interrupt.o: ../machine/interrupt.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/interrupt.h ../threads/list.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
sysdep.o: ../machine/sysdep.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 /usr/include/signal.h /usr/include/bits/signum.h \
 /usr/include/bits/signum-generic.h \
 /usr/include/bits/types/sig_atomic_t.h \
 /usr/include/bits/types/sigset_t.h /usr/include/bits/types/__sigset_t.h \
 /usr/include/bits/types/struct_timespec.h \
 /usr/include/bits/types/siginfo_t.h /usr/include/bits/types/sigval_t.h \
 /usr/include/bits/siginfo-arch.h /usr/include/bits/siginfo-consts.h \
 /usr/include/bits/siginfo-consts-arch.h \
 /usr/include/bits/types/sigevent_t.h /usr/include/bits/sigevent-consts.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/include/bits/types/stack_t.h /usr/include/sys/ucontext.h \
 /usr/include/bits/sigstack.h /usr/include/bits/ss_flags.h \
 /usr/include/bits/types/struct_sigstack.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/thread-shared-types.h \
 /usr/include/bits/pthreadtypes-arch.h /usr/include/bits/sigthread.h \
 /usr/include/sys/types.h /usr/include/bits/types/clock_t.h \
 /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h \
 /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h \
 /usr/include/bits/uintn-identity.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/types/struct_timeval.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/sysmacros.h \
 /usr/include/sys/time.h /usr/include/sys/socket.h \
 /usr/include/bits/types/struct_iovec.h /usr/include/bits/socket.h \
 /usr/include/bits/socket_type.h /usr/include/bits/sockaddr.h \
 /usr/include/asm/socket.h /usr/include/asm-generic/socket.h \
 /usr/include/asm/sockios.h /usr/include/asm-generic/sockios.h \
 /usr/include/bits/types/struct_osockaddr.h /usr/include/sys/file.h \
 /usr/include/fcntl.h /usr/include/bits/fcntl.h \
 /usr/include/bits/fcntl-linux.h /usr/include/linux/falloc.h \
 /usr/include/bits/stat.h /usr/include/sys/un.h /usr/include/sys/mman.h \
 /usr/include/bits/mman.h /usr/include/bits/mman-linux.h \
 /usr/include/unistd.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/confname.h \
 /usr/include/bits/getopt_posix.h /usr/include/bits/getopt_core.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
stats.o: ../machine/stats.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/stats.h
timer.o: ../machine/timer.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/timer.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
addrspace.o: ../userprog/addrspace.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h \
 ../userprog/addrspace.h ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../userprog/bitmap.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../filesys/openfile.h
exception.o: ../userprog/exception.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h \
 ../userprog/syscall.h
progtest.o: ../userprog/progtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h \
 ../machine/console.h ../userprog/addrspace.h
console.o: ../machine/console.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/console.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
machine.o: ../machine/machine.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/translate.h ../machine/disk.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
mipssim.o: ../machine/mipssim.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/translate.h ../machine/disk.h ../machine/mipssim.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
translate.o: ../machine/translate.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
directory.o: ../filesys/directory.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../filesys/filehdr.h ../machine/disk.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../filesys/directory.h ../filesys/openfile.h
filehdr.o: ../filesys/filehdr.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h \
 ../filesys/filehdr.h ../userprog/bitmap.h ../filesys/openfile.h
filesys.o: ../filesys/filesys.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../filesys/directory.h \
 ../filesys/openfile.h ../filesys/filehdr.h ../filesys/filesys.h
fstest.o: ../filesys/fstest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h ../threads/thread.h
openfile.o: ../filesys/openfile.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../filesys/filehdr.h ../machine/disk.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../filesys/openfile.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
synchdisk.o: ../filesys/synchdisk.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/synch.h ../threads/thread.h ../threads/utility.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/list.h
disk.o: ../machine/disk.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
nettest.o: ../network/nettest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h \
 ../network/post.h
post.o: ../network/post.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../network/post.h ../machine/network.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/synchlist.h ../threads/list.h ../threads/utility.h \
 ../threads/synch.h ../threads/thread.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h
network.o: ../machine/network.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
