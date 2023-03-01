#include "Cell.hpp"

Cell::Cell() {
    this->alive = false;
    this->neighbours = 0;
    this->age = 0;
    this->next_state = false;
}

Cell::~Cell() = default;

bool Cell::isAlive() const noexcept {
    return this->alive;
}

void Cell::setAlive() noexcept {
    this->next_state = true;
}

void Cell::setDead() noexcept {
    this->next_state = false;
}

int Cell::getNeighbours() const noexcept {
    return this->neighbours;
}

void Cell::setNeighbours(int nb) noexcept {
    this->neighbours = nb;
}

int Cell::getAge() const noexcept {
    return this->age;
}

void Cell::setAge(int a) noexcept {
    this->age = a;
}

void Cell::update() noexcept {
    this->alive = this->next_state;
}
