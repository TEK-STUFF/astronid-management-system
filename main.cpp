#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.hpp"
#include "ConfigFile.hpp"
#include "Simulation.hpp"

void loadSimulationSettings(ConfigFile &config, Simulation &simulation) {
    std::string configPath;
    std::string mapPath;
    std::vector<std::vector<bool>> booleanMap;

    std::cout << "Enter config file path: ";
    std::cin >> configPath;
    std::cout << "Enter map file path: ";
    std::cin >> mapPath;

    if (configPath.empty()) {
        configPath = "settings";
    }
    if (mapPath.empty()) {
        mapPath = "map";
    }
    config.loadConfigFile(configPath);
    config.loadMap(mapPath, booleanMap);

    simulation.setGridSize(config.getGridWidth(), config.getGridHeight());
    simulation.setMap(booleanMap);
}

int main() {
    ConfigFile config = ConfigFile();
    Simulation simulation = Simulation();
    loadSimulationSettings(config, simulation);
    sf::RenderWindow window(sf::VideoMode((config.getGridWidth()*config.getCellSize()), (config.getGridHeight()*config.getCellSize())), "ACMS"/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(config.getCellAgingSpeed());
    bool isPaused = true;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    //////////////// [[[ TRANSMISSION ERROR ]]] /////////////////
                    /// warning : an unknown number of bytes have been lost ///
                    //////////////// [[[ TRANSMISSION ERROR ]]] ////////////////
                }
                if (event.key.code == sf::Keyboard::Space) {
                    isPaused = !isPaused;
                }
            }
        }
        window.clear();
        if (!isPaused) {
            simulation.update();
        }
        for (int i = 0; i < simulation.getGridWidth(); i++) {
            for (int j = 0; j < simulation.getGridHeight(); j++) {
                Cell cell = simulation.grid[i][j];
                sf::RectangleShape rectangle(sf::Vector2f(config.getCellSize(), config.getCellSize()));
                rectangle.setPosition(i * config.getCellSize(), j * config.getCellSize());
                // change cell color based on its state
                if (cell.isAlive()) {
                    rectangle.setFillColor(sf::Color::White);
                } else {
                    //////////////// [[[ TRANSMISSION ERROR ]]] /////////////////
                    /// warning : an unknown number of bytes have been lost ///
                    //////////////// [[[ TRANSMISSION ERROR ]]] ////////////////
                }
                window.draw(rectangle);
            }
        }
        window.display();
    }
    return 0;
}
