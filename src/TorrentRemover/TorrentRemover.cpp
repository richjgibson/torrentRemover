#include "TorrentRemover.h"

#include <iostream>
#include <filesystem>

void TorrentRemover::RemoveTorrents()
{
    std::filesystem::path torrent_path{std::getenv("HOME")};
    torrent_path /= "Downloads";

    std::filesystem::recursive_directory_iterator download_iterator{torrent_path};

    for (auto &&item : download_iterator)
    {
        if (item.path().extension() == ".torrent")
        {
            std::cout << item.path() << "\n";
            std::filesystem::remove(item);
        }   
    }
    return;
}