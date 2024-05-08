#ifndef CONFIGS_H
#define CONFIGS_H

#include <string>


class Configs
{
public:
    Configs();
    std::string enterFilePath = "";
    std::string extension = "";
    std::string imagePath = "";
    std::string name = "";
    std::string oriConfigFilePath = "";
    int originate = 1;
    int version = 1;
};

#endif // CONFIGS_H
