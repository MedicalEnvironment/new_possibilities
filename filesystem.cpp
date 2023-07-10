#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

auto recursiveGetFileNamesByExtension = [](fs::path path, const std::string extension)
{
    std::vector<std::string> filename;
    std::vector<std::string> filenames;

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file() && entry.path().extension().string() == extension) {
            filenames.push_back(entry.path().filename().string());
        }
    }

    return filenames;
};

int main()
{
    fs::path directoryPath("/Users/gasoline/Desktop");
    std::string desiredExtension(".txt");

    auto filenames = recursiveGetFileNamesByExtension(directoryPath, desiredExtension);

    std::cout << "Files with extension " << desiredExtension << ":" << std::endl;
    for(const auto& filename: filenames)
    {
        std::cout << filename << std::endl;
    }

    return 0;
}
