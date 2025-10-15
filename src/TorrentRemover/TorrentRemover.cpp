#include "TorrentRemover.h"

#include <iostream>
#include <filesystem>

namespace
{
    bool VerifyDirectory(std::filesystem::path download_directory)
    {
        if (std::filesystem::exists(download_directory) &&
            std::filesystem::is_directory(download_directory))
        {
            return true;
        }
        return false;
    }
}

void TorrentRemover::RemoveTorrents()
{
    std::filesystem::path torrent_path{std::getenv("HOME")};
    torrent_path /= "Downloads";

    // Check the path to the download directory
    if (!VerifyDirectory(torrent_path))
    {
        return;
    }
    
    std::filesystem::recursive_directory_iterator download_iterator{torrent_path};

    for (auto &&item : download_iterator)
    {
        if (std::filesystem::is_symlink(item.path()))
        {
            continue;
        }
        if (item.path().extension() == ".torrent")
        {
            std::cout << item.path() << "\n";
            std::filesystem::remove(item);
        }   
    }
    return;
}