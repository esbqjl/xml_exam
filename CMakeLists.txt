cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("xml_exam")

# Add source to the main executable (xml_exam)
add_executable (xml_exam "src/xml_exam.cpp" "include/xml_exam.h" "src/main.cpp")

# Add source to the test executable (test_xml_exam)
add_executable (test_xml_exam "test/test_xml_exam.cpp" "include/xml_exam.h" "src/xml_exam.cpp")

# Set the C++ standard to C++20 for both executables
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET xml_exam PROPERTY CXX_STANDARD 20)
  set_property(TARGET test_xml_exam PROPERTY CXX_STANDARD 20)
endif()