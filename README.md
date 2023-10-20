# The Catalyst Kernel
A standalone 64-bit general-purpose hobby operating system kernel.

## Status

Catalyst is in the early stages of initial development, initially targeting the x86-64 based PC and server platforms.

## Design

- **Hybrid Kernel**:
  - A relatively stable kernel that is extensible via userspace kernel servers
  - Performance-critical driver components can be integrated directly into the kernel space as required

- **Security & System Calls**:
  - Privilege level based security
  - Minimalist system call interface offering close control over system primitives

- **Bootloader**:
  - Uses the [Limine Boot Protocol](https://github.com/limine-bootloader/limine)

## Hardware Support

- x86-64 implementation in progress
- UEFI and ACPI are required

## Building

Building is as simple as running `make`.

## Contributing

If you're interested in contributing to the Catalyst Kernel, please reach out to [mdpatel.econ@gmail.com](mailto:mdpatel.econ@gmail.com).

## License

Catalyst is licensed under the [GNU General Public License Version 3.0](https://www.gnu.org/licenses/gpl-3.0.en.html) as published by the Free Software Foundation.