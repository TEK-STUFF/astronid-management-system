#include "Simulation.hpp"

Simulation::Simulation() {
    this->grid_width = 0;
    this->grid_height = 0;
}

Simulation::Simulation(int grid_width, int grid_height, int cell_size) {
    this->grid_width = grid_width;
    this->grid_height = grid_height;
    for (int i = 0; i < this->grid_width; i++) {
        std::vector<Cell> row;
        for (int j = 0; j < this->grid_height; j++) {
            row.emplace_back();
        }
        this->grid.push_back(row);
    }
}

Simulation::Simulation(std::vector<std::vector<bool>> map) {
    this->grid_width = map.size();
    this->grid_height = map[0].size();
    this->setMap(map);
}

Simulation::~Simulation() = default;

void Simulation::update() {
    // this loop updates the number of neighbours for each cell, then determines if the cell will be alive or dead in the next generation
    for (int i = 0; i < this->grid_width; i++) {
        for (int j = 0; j < this->grid_height; j++) {
            int neighbours = 0;
            if (i > 0 && j > 0 && this->grid[i - 1][j - 1].isAlive()) {
                neighbours++;
            }

            //////////////// [[[ TRANSMISSION ERROR ]]] /////////////////
             /// warning : an unknown number of bytes have been lost ///
            //////////////// [[[ TRANSMISSION ERROR ]]] ////////////////

            if (i < this->grid_width - 1 && j > 0 && this->grid[i + 1][j - 1].isAlive()) {
                neighbours++;
            }
            if (i < this->grid_width - 1 && this->grid[i + 1][j].isAlive()) {
                neighbours++;
            }
            if (i < this->grid_width - 1 && j < this->grid_height - 1 && this->grid[i + 1][j + 1].isAlive()) {
                neighbours++;
            }
            this->grid[i][j].setNeighbours(neighbours);
            if (this->grid[i][j].isAlive()) {
                if (neighbours < 2 || neighbours > 3) {
                    //////////////// [[[ TRANSMISSION ERROR ]]] /////////////////
                    /// warning : an unknown number of bytes have been lost ///
                    //////////////// [[[ TRANSMISSION ERROR ]]] ////////////////
                }
            } else {
                if (neighbours == 3) {
                    this->grid[i][j].setAlive();
                }
            }
        }
    }
    for (int i = 0; i < this->grid_width; i++) {
        for (int j = 0; j < this->grid_height; j++) {
            this->grid[i][j].update();
        }
    }
}

void Simulation::setCellAlive(int x, int y) {
    this->grid[x][y].setAlive();
}

void Simulation::setCellDead(int x, int y) {
    this->grid[x][y].setDead();
}

bool Simulation::isCellAlive(int x, int y) const noexcept {
    return this->grid[x][y].isAlive();
}

int Simulation::getCellNeighbours(int x, int y) const noexcept {
    return this->grid[x][y].getNeighbours();
}

int Simulation::getCellAge(int x, int y) const noexcept {
    return this->grid[x][y].getAge();
}

int Simulation::getGridWidth() const noexcept {
    return this->grid_width;
}

int Simulation::getGridHeight() const noexcept {
    return this->grid_height;
}

void Simulation::setRandomCells(int density) {
    for (int i = 0; i < this->grid_width; i++) {
        for (int j = 0; j < this->grid_height; j++) {
            if (rand() % 100 < density) {
                this->setCellAlive(i, j);
            }
        }
    }

}


void Simulation::setMap(std::vector<std::vector<bool>> map) {
    this->grid_width = map.size();
    this->grid_height = map[0].size();
    for (int i = 0; i < this->grid_width; i++) {
        std::vector<Cell> row;
        for (int j = 0; j < this->grid_height; j++) {
            row.emplace_back();
        }
        this->grid.push_back(row);
    }
    for (int i = 0; i < this->grid_width; i++) {
        for (int j = 0; j < this->grid_height; j++) {
            if (map[i][j]) {
                this->setCellAlive(i, j);
            }
        }
    }

}

void Simulation::setGridSize(int width, int height) {
    //////////////// [[[ TRANSMISSION ERROR ]]] /////////////////
    /// warning : an unknown number of bytes have been lost ///
    //////////////// [[[ TRANSMISSION ERROR ]]] ////////////////
}
