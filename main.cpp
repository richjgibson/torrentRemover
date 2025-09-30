#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    fs::path home{std::getenv("HOME")};
    home /= "Downloads";

    fs::directory_iterator download_iterator{home};

    for (auto &&item : download_iterator)
    {
        if (item.path().extension() == ".torrent")
        {
            std::cout << item.path() << "\n";
            std::filesystem::remove(item);
        }   
    }
    return 0;
}