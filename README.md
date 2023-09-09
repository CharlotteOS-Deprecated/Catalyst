# The Catalyst Kernel

## A standalone 64-bit general purpose hobby operating system kernel

### Status

Catalyst is in the early stages of initial development with core kernel functionality first being developed for
the x86-64 based PC and server platforms with plans to port it to similar Arm based devices in the future.

### Design
- Hybrid kernel
    - Relatively stable kernel that is extensible via userspace kernel servers
    - Performance critical driver components can be moved into kernel space as needed
- Privilege-level based security and system call access
- Low-level but hardware agnostic system call interface
- Flexible enough to allow any API to be built on top of its system call interface
- Boots using the Limine Boot Protocol

 ### Hardware Support
- x86-64 implementation in progress
- Aarch64 support planned
- UEFI and ACPI are required
