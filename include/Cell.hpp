#ifndef GAMEOFLIFE_CELL_HPP
#define GAMEOFLIFE_CELL_HPP

#include <SFML/Graphics.hpp>

class Cell {
public:
    Cell();
    ~Cell();
    [[nodiscard]] bool isAlive() const noexcept;
    void setAlive() noexcept;
    void setDead() noexcept;
    [[nodiscard]] int getNeighbours() const noexcept;
    void setNeighbours(int nb) noexcept;
    [[nodiscard]] int getAge() const noexcept;
    void setAge(int age) noexcept;
    void update() noexcept;
private:
    bool alive;
    bool next_state;
    int neighbours;
    int age;
};

#endif //GAMEOFLIFE_CELL_HPP
