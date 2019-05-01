# Detect Platform
IF (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Windows
    SET (NEZUMI_PLATFORM_WINDOWS ON)
ELSEIF (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # Linux
    MESSAGE (WARNING "TODO: Add Linux support!")
ELSEIF (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # macOS
    MESSAGE (WARNING "TODO: Add macOS support!")
ELSE ()
    # Unknown Platform
    MESSAGE (WARNING "This platform is not supported by Nezumi!")
ENDIF ()

# Detect Compiler
IF (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC
    SET (NEZUMI_COMPILER_MSVC ON)
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC
    SET (NEZUMI_COMPILER_GCC ON)
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Clang
    SET (NEZUMI_COMPILER_CLANG ON)
ELSE ()
    # Unknown Compiler
    MESSAGE (WARNING "This compiler is not supported by Nezumi!")
ENDIF ()