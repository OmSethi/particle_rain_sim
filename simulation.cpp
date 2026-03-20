// simulation for particle rain 

#include <cstdlib>
#include <SFML/Graphics.hpp>

struct Particle {
    float x, y; // position
    float speed; // how fast the particle falls
};

int screenHeight = 800;
int screenWidth = 600;

Particle particles[500]; // array of particles

int main() {
    sf::RenderWindow window(sf::VideoMode({600u, 800u}), "Particle Rain");
    window.setFramerateLimit(60);

    // give each particle a random starting position and speed
    for (int i = 0; i < 500; i++) {
        particles[i].x = rand() % screenWidth;
        particles[i].y = rand() % screenHeight;
        particles[i].speed = 1 + rand() % 5; // rand speed between 1-5
    }

    // while loop that runs at every frame
    while (window.isOpen()) {

        // close window
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        // this logic moves each particle down and resets once it is off the screen
        for (int i = 0; i < 500; i++) {
            particles[i].y += particles[i].speed;
            if (particles[i].y > screenHeight) {
                particles[i].y = 0;
                particles[i].x = rand() % screenWidth;
            }
        }
    
        // clearing previous frame
        window.clear(sf::Color::Black);

        // draw each particle
        for (int i = 0; i < 500; i++) {
            sf::RectangleShape drop(sf::Vector2f(2.f, 10.f));
            drop.setPosition({particles[i].x, particles[i].y});
            drop.setFillColor(sf::Color::Cyan);
            window.draw(drop);
        }
        // show the new frame
        window.display();
    }
    return 0;
}

