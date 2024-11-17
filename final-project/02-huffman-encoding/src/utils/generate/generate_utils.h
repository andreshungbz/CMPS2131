#ifndef GENERATE_UTILS_H
#define GENERATE_UTILS_H


#include <fstream>
#include <string>
#include <unordered_map>

#include "huffman_tree/components/FileInformation.h"
#include "huffman_tree/components/HuffmanHeader.h"
#include "huffman_tree/HuffmanNode.h"

void generateEncodingTable(std::unordered_map<std::optional<char>, std::string>& encodingTable, const HuffmanNode* root);
void generateEncodingTableHelper(std::unordered_map<std::optional<char>, std::string>& encodingTable, const HuffmanNode* root, const std::string& code);

void generateHuffmanCode(std::ifstream& input, const std::unordered_map<std::optional<char>, std::string>& encodingTable, std::string& encodingString);
void insertEncodedCharacter(const std::unordered_map<std::optional<char>, std::string>& encodingTable, std::string& encodingString, char character);

void generateHuffmanTreeRepresentation(std::string& representation, const HuffmanNode* root);
void generateHuffmanTreeRepresentationHelper(std::string& representation, const HuffmanNode* root);

void generateFileInfoCode(FileInformation& information, std::string& infoEncoding);

void generateHuffmanHeader(HuffmanHeader& header, std::size_t iLength, std::size_t tLength, std::size_t eLength);


#endif // GENERATE_UTILS_H