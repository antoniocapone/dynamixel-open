# Dynamixel Driver (Protocol 2.0)

A lightweight, platform-independent C driver for controlling Dynamixel motors using Dynamixel's Protocol 2.0. This driver is designed to be efficient, easy to integrate, and adheres to the official [Dynamixel Protocol 2.0 documentation](https://emanual.robotis.com/docs/en/dxl/protocol2/).

## Features

- ✅ Write command support
- ⬜ Read command support (Upcoming)
- ⬜ High-level driver (Upcoming)

## Getting Started

### Prerequisites
- A C compiler (GCC, Clang, or MSVC)
- A serial communication interface (UART, USB-to-Serial adapter, etc.)
- A Dynamixel motor supporting Protocol 2.0 (e.g., XM, XH, or XL series)

### Installation
Clone the repository:
```sh
git clone https://github.com/antoniocapone/dynamixel-open
cd dynamixel-driver
```

### Usage
Include the driver in your project:
```c
#include "dynamixel_driver.h"
```

Initialize communication:
```c
/* Not Implemented Yet */
```

Send a write command:
```c
/* Not Implemented Yet */
```

### Future Enhancements
- Implementation of read commands to fetch motor status and feedback
- A high-level API for simplified motor control (position, velocity, and torque control)
- Cross-platform support for Windows, Linux, and macOS

## Contributing
Contributions are welcome! Feel free to submit issues, feature requests, or pull requests.

## References
- [Robotis Official Website](https://www.robotis.com/)
