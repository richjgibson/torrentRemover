

add_executable(torrent_remover_tests
                test_torrentRemover.cpp)

target_link_libraries(
    torrent_remover_tests PRIVATE
    torrentRemover
    gtest_main
)

add_test(NAME HelloTest COMMAND torrent_remover_tests)