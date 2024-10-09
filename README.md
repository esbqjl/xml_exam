# XML Exam Project

This project is a C++ application that includes a main executable `xml_exam` and a test executable `test_xml_exam`. It uses CMake for build configuration, and the project is set up to be compatible with C++20. This guide will walk you through building and running the project using CMake, including support for multiple build configurations with `CMakePresets.json`.

## Project Structure

The project structure is as follows:

```
.
├── include/            # Header files
│   └── xml_exam.h
├── src/                # Source files
│   ├── xml_exam.cpp
│   └── main.cpp
├── test/               # Unit tests
│   └── test_xml_exam.cpp
├── CMakeLists.txt      # CMake build script
├── CMakePresets.json   # CMake preset configurations
└── README.md           # This readme file
```

## Prerequisites

Before building the project, ensure you have the following installed:

- **CMake** (version 3.8 or higher)
- **Ninja** (for build automation)
- **Microsoft Visual Studio** (or any C++ compiler supporting C++20)
- **Git** (optional, for version control)

## Setting Up the Build Environment

The project uses `CMakePresets.json` to define build configurations. The available presets are:

1. **x64-debug**: 64-bit build with debug information
2. **x64-release**: 64-bit build optimized for release
3. **x86-debug**: 32-bit build with debug information
4. **x86-release**: 32-bit build optimized for release

The `CMakePresets.json` file also sets up default configurations for the C and C++ compilers.

### Configuring the Build

1. **Open a terminal and navigate to the project directory**:
   ```bash
   cd /path/to/your/project
   ```

2. **Configure the project using a preset**:
   ```bash
   cmake --preset x64-debug
   ```

   This command will generate the build files in the `out/build/x64-debug` directory.

### Building the Project

Once the configuration is complete, you can build the project:

```bash
cmake --build out/build/x64-debug
```

This will compile the source files and generate the executable binaries.

### Running the Executables

After a successful build, the executables will be located in the `out/build/x64-debug` directory.

- **Run the main application**:
  ```bash
  ./out/build/x64-debug/xml_exam
  ```

- **Run the test executable**:
  ```bash
  ./out/build/x64-debug/test_xml_exam
  ```

## Configuring and Building for Other Presets

To build for other configurations, use the corresponding presets:

- **x64 Release**:
  ```bash
  cmake --preset x64-release
  cmake --build out/build/x64-release
  ```

- **x86 Debug**:
  ```bash
  cmake --preset x86-debug
  cmake --build out/build/x86-debug
  ```

- **x86 Release**:
  ```bash
  cmake --preset x86-release
  cmake --build out/build/x86-release
  ```

## CMake Configuration Options

The project enables hot reload for MSVC compilers if supported. The following CMake configurations are applied:

- **CMake Policy CMP0141**: Set to `NEW` for MSVC debug information format.
- **C++ Standard**: The project uses C++20 for both the main and test executables.

## Troubleshooting

If you encounter any issues:

1. **Verify that CMake and Ninja are correctly installed and added to your PATH.**
2. **Ensure that you are using a C++ compiler compatible with C++20.**
3. **Check that you have selected the correct preset for your target architecture and build type.**

## Contributing

Feel free to contribute by submitting issues, bug reports, or pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
