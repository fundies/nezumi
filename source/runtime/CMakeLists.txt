include (ExternalProject)

# Vendor includes
include_directories("${CMAKE_BINARY_DIR}/vendor/include")

# Set Runtime Options
SET (RUNTIME_PARANOID_MODE ON CACHE BOOL "Enables various runtime error checks and assertions.")

# Get Runtime Sources
SET (
    SOURCE_RUNTIME

    "source/runtime/game.cpp"
    "source/runtime/system.cpp"

    "source/runtime/window/window.internal.cpp"
    "source/runtime/render/render.internal.cpp"
    "source/runtime/timer/timer.internal.cpp"
)

# Define Empty Modules
NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_WINDOW "None" SOURCES "source/runtime/window/none/window.none.cpp")
NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_RENDER "None" SOURCES "source/runtime/render/none/render.none.cpp")
NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_FILESYSTEM "None" SOURCES "source/runtime/filesystem/none/filesystem.none.cpp")
NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_TIMER "None" SOURCES "source/runtime/timer/none/timer.none.cpp")

# Define Platform Modules
IF (NEZUMI_PLATFORM_WINDOWS)
    # Windows
    NEZUMI_MODULE_DEFAULT (RUNTIME_MODULE_WINDOW "Win32")
    NEZUMI_MODULE_DEFAULT (RUNTIME_MODULE_RENDER "Direct3D 11")
    NEZUMI_MODULE_DEFAULT (RUNTIME_MODULE_FILESYSTEM "Win32")
    NEZUMI_MODULE_DEFAULT (RUNTIME_MODULE_TIMER "Win32")

    # Windows - Window
    NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_WINDOW "Win32" SOURCES "source/runtime/window/win32/window.win32.cpp")

    # SDL2 - Window
    NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_WINDOW "SDL2" SOURCES "source/runtime/window/sdl2/window.sdl2.cpp" LIBRARIES "SDL2main;SDL2-static;imm32;version;winmm" EXTERNAL "SDL2" PROVIDES "SDL2main;SDL2-static")

    # Windows - Render
    NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_RENDER "Direct3D 11" SOURCES "source/runtime/render/d3d11/render.d3d11.cpp" LIBRARIES "dxgi;d3d11")

    # Windows - Filesystem
    NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_FILESYSTEM "Win32" SOURCES "source/runtime/filesystem/win32/filesystem.win32.cpp")

    # Windows - Timer
    NEZUMI_MODULE_ENTRY (RUNTIME_MODULE_TIMER "Win32" SOURCES "source/runtime/timer/win32/timer.win32.cpp")
ELSE ()
    # Unknown Platform
    MESSAGE (WARNING "This platform has no supported runtime modules!")
ENDIF ()

# Define Module Options
NEZUMI_MODULE_OPTION (RUNTIME_MODULE_WINDOW "The backend to use for the runtime's window module.")
NEZUMI_MODULE_OPTION (RUNTIME_MODULE_RENDER "The backend to use for the runtime's render module.")
NEZUMI_MODULE_OPTION (RUNTIME_MODULE_FILESYSTEM "The backend to use for the runtime's filesystem module.")
NEZUMI_MODULE_OPTION (RUNTIME_MODULE_TIMER "The backend to use for the runtime's timer module.")

# Add Target
ADD_LIBRARY (
    runtime STATIC

    ${SOURCE_RUNTIME}
    ${SOURCE_RUNTIME_MODULE_WINDOW}
    ${SOURCE_RUNTIME_MODULE_RENDER}
    ${SOURCE_RUNTIME_MODULE_FILESYSTEM}
    ${SOURCE_RUNTIME_MODULE_TIMER}
)

# Add Target Directories
TARGET_INCLUDE_DIRECTORIES (runtime PUBLIC "source" "include")

# Add Target Definitions
TARGET_COMPILE_DEFINITIONS (runtime PRIVATE "$<$<CONFIG:DEBUG>:DEBUG_MODE>")

IF (RUNTIME_PARANOID_MODE)
    TARGET_COMPILE_DEFINITIONS (runtime PRIVATE "PARANOID_MODE")
ENDIF ()

# Add Target Modules
NEZUMI_MODULE_TARGET (RUNTIME_MODULE_WINDOW runtime)
NEZUMI_MODULE_TARGET (RUNTIME_MODULE_RENDER runtime)
NEZUMI_MODULE_TARGET (RUNTIME_MODULE_FILESYSTEM runtime)
NEZUMI_MODULE_TARGET (RUNTIME_MODULE_TIMER runtime)