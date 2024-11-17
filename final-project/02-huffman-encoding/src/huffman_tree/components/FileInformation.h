// File Information Header and Implementation

// This class consolidates information about the processed file and provides a simple constructor for
// instantiating an object.

#ifndef FILE_INFORMATION_H
#define FILE_INFORMATION_H


#include <string>
#include <utility>

class FileInformation {
public:
    // constructor
    FileInformation(std::string name, std::string extension, const std::size_t size, std::string directory)
    : fileName(std::move(name)), fileExtension(std::move(extension))
    , fileSize(size), fileDirectory(std::move(directory)) {}

    // public data members
    std::string fileName{};
    std::string fileExtension{};
    std::size_t fileSize{};
    std::string fileDirectory{};
};


#endif // FILE_INFORMATION_H