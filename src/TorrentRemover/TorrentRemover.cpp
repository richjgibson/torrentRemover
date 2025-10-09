#include "TorrentRemover.h"

#include <iostream>
#include <filesystem>

void TorrentRemover::RemoveTorrents()
{
    std::filesystem::path home{std::getenv("HOME")};
    home /= "Downloads";

    std::filesystem::recursive_directory_iterator download_iterator{home};

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