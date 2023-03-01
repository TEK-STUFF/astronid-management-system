
#ifndef GAMEOFLIFE_SIMULATION_HPP
#define GAMEOFLIFE_SIMULATION_HPP

#include <vector>

#include "Cell.hpp"

class Simulation {
public:
    std::vector<std::vector<Cell>> grid;
    Simulation();
    Simulation(int width, int height, int cell_size);
    explicit Simulation(std::vector<std::vector<bool>> map);
    ~Simulation();
    void setMap(std::vector<std::vector<bool>> map);
    void setGridSize(int width, int height);
    void update();
    void setCellAlive(int x, int y);
    void setCellDead(int x, int y);
    void setRandomCells(int density); // 'density' is a percentage between 0 and 100
    [[nodiscard]] bool isCellAlive(int x, int y) const noexcept;
    [[nodiscard]] int getCellNeighbours(int x, int y) const noexcept;
    [[nodiscard]] int getCellAge(int x, int y) const noexcept;
    [[nodiscard]] int getGridWidth() const noexcept;
    [[nodiscard]] int getGridHeight() const noexcept;
private:
    int grid_width;
    int grid_height;
};

#endif //GAMEOFLIFE_SIMULATION_HPP
