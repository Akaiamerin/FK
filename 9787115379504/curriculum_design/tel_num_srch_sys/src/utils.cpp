#include <fstream>
#include "utils.h"

//读取文件
void ReadFile(std::string file_path, std::vector<std::string> & vec) {
    std::ifstream ifs(file_path);
    if (ifs.is_open() == false) {
        return;
    }
    std::string str = {};
    while (std::getline(ifs, str)) {
        vec.push_back(str);
    }
    ifs.close();
}

//写入文件
void WriteFile(std::string file_path, std::vector<std::string> vec) {
    std::ofstream ofs(file_path);
    for (int i = 0; i < vec.size(); i++) {
        ofs << vec[i] << std::endl;
    }
    ofs.close();
}