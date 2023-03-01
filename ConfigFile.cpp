#include "ConfigFile.hpp"

ConfigFile::ConfigFile() {
    this->cell_color = "white";
    this->background_color = "black";
    this->cell_size = 30;
    this->cell_aging_speed = 2;
    this->grid_width = 800;
    this->grid_height = 800;
}

ConfigFile::~ConfigFile() = default;

void ConfigFile::loadConfigFile(const std::string &path) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("cell_color") != std::string::npos) {
                this->cell_color = line.substr(line.find('=') + 1);
            } else if (line.find("cell_aging_color") != std::string::npos) {
                this->cell_aging_color = line.substr(line.find('=') + 1);
            } else if (line.find("background_color") != std::string::npos) {
                this->background_color = line.substr(line.find('=') + 1);
            } else if (line.find("cell_size") != std::string::npos) {
                this->cell_size = std::stoi(line.substr(line.find('=') + 1));
            } else if (line.find("cell_aging_speed") != std::string::npos) {
                this->cell_aging_speed = std::stoi(line.substr(line.find('=') + 1));
            } else if (line.find("grid_width") != std::string::npos) {
                this->grid_width = std::stoi(line.substr(line.find('=') + 1));
            } else if (line.find("grid_height") != std::string::npos) {
                this->grid_height = std::stoi(line.substr(line.find('=') + 1));
            }
        }
    } else {
        std::cerr << "Error while opening the config file" << std::endl;
        return;
    }
    file.close();
    if (this->cell_size > this->grid_width || this->cell_size > this->grid_height) {
        std::cerr << "Cell size is bigger than the grid size" << std::endl;
        int new_size = std::min(1920 / this->grid_width, 1080 / this->grid_height);
        std::cout << "Defaulting to new cell size: " << new_size << std::endl;
    }
    if (this->grid_width * this->cell_size > 1920 || this->grid_height * this->cell_size > 1080) {
        std::cerr << "The grid is probably bigger than the screen" << std::endl;
        int new_size = std::min(1920 / this->grid_width, 1080 / this->grid_height);
        std::cout << "Defaulting to new cell size: " << new_size << std::endl;
    }
}

void ConfigFile::loadMap(const std::string &path, std::vector<std::vector<bool>> &map) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<bool> row;
            for (char c : line) {
                if (c == '1') {
                    row.push_back(true);
                } else {
                    row.push_back(false);
                }
            }
            if (row.size() != this->grid_width) {
                std::cerr << "Map width is not equal to the grid width" << std::endl;
                std::cout << "Adjusting the map's size..." << std::endl;
                row.resize(this->grid_width);
            }
            map.push_back(row);
            if (map.size() > this->grid_height) {
                std::cerr << "Map height is bigger than the grid height" << std::endl;
                std::cout << "Adjusting the map's size..." << std::endl;
                map.resize(this->grid_height);
                break;
            }
        }
    } else {
        std::cerr << "Error while opening the map file" << std::endl;
        return;
    }
    file.close();
}

std::string ConfigFile::getCellColor() const noexcept {
    return this->cell_color;
}

std::string ConfigFile::getCellAgingColor() const noexcept {
    return this->cell_aging_color;
}

std::string ConfigFile::getBackgroundColor() const noexcept {
    return this->background_color;
}

int ConfigFile::getCellSize() const noexcept {
    return this->cell_size;
}

int ConfigFile::getCellAgingSpeed() const noexcept {
    return this->cell_aging_speed;
}

int ConfigFile::getGridWidth() const noexcept {
    return this->grid_width;
}

int ConfigFile::getGridHeight() const noexcept {
    return this->grid_height;
}

std::vector<std::vector<bool>> ConfigFile::getMap() const noexcept {
    return this->map;
}

