cmake_minimum_required(VERSION 3.10.0)
project(torrentRemover VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src/app)
add_subdirectory(src/TorrentRemover)
add_subdirectory(src/tests)