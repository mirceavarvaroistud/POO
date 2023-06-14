cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add your source files
set(SOURCES
    src/main.cpp
    src/display.cpp
    src/client.cpp
    src/car.cpp
)

# Add your header files
set(HEADERS
    include/display.h
    include/client.h
    include/car.h
)

# Create an executable from the sources
add_executable(CarRental ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(CarRental PUBLIC include)

# Optional: Add any libraries your project depends on
# find_package(<Package_Name> REQUIRED)
# target_link_libraries(MyExecutable <Package_Name>::<Library_Name>)

