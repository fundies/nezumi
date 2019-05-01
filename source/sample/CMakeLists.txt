# Add Target
ADD_EXECUTABLE (sample "source/main.cpp")

# Add Target Libraries
TARGET_LINK_LIBRARIES (sample PRIVATE runtime)