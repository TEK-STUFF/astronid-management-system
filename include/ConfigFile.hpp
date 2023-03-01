#ifndef GAMEOFLIFE_CONFIGFILE_HPP
#define GAMEOFLIFE_CONFIGFILE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class ConfigFile {
public:
    ConfigFile();
    ~ConfigFile();
    void loadConfigFile(const std::string& path);
    void loadMap(const std::string& path, std::vector<std::vector<bool>>& map);
    [[nodiscard]] std::string getCellColor() const noexcept;
    [[nodiscard]]std::string getCellAgingColor() const noexcept;
    [[nodiscard]] std::string getBackgroundColor() const noexcept;
    [[nodiscard]] int getCellSize() const noexcept;
    [[nodiscard]] int getCellAgingSpeed() const noexcept;
    [[nodiscard]] int getGridWidth() const noexcept;
    [[nodiscard]] int getGridHeight() const noexcept;
    [[nodiscard]] std::vector<std::vector<bool>> getMap() const noexcept;
private:
    std::string cell_color;
    std::string cell_aging_color;
    std::string background_color;
    int cell_size;
    int cell_aging_speed;
    int grid_width;
    int grid_height;
    std::vector<std::vector<bool>> map;
};

#endif //GAMEOFLIFE_CONFIGFILE_HPP
