# The Catalyst Kernel

## A standalone 64-bit general purpose hobby operating system kernel

### Design
- Hybrid kernel that allows performance critical driver components to run in kernel space
- Relatively stable kernel that is extensible via userspace kernel servers
- Privilege-level based security and system call access
- Low-level but hardware agnostic system call interface
- Flexible enough to allow any API to be built on top of its system call interface

 ### Hardware Support
- x86-64 implementation in progress
- Aarch64 support planned
- UEFI and ACPI are required
