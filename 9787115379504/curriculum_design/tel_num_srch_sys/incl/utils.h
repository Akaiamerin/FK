#pragma once

#include <string>
#include <vector>

//读取文件
void ReadFile(std::string file_path, std::vector<std::string> & vec);

//写入文件
void WriteFile(std::string file_path, std::vector<std::string> vec);