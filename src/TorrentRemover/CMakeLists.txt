add_library(torrentRemover STATIC
            TorrentRemover.cpp)

target_include_directories(torrentRemover PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})