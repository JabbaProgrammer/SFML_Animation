#include "SFML/Graphics.hpp"
#include "Animation.h"

using namespace sf;

int main() {
    // Window parameters
    RenderWindow window(VideoMode(200, 200), "Action");
    window.setFramerateLimit(60);
    View view;

    // Player
    RectangleShape player(Vector2f(48.f, 48.f));
    Texture playerTexture;
    playerTexture.loadFromFile("/home/tim/Development/C++/SFML_Animation/Resources/Player/Run.png");
    player.setTexture(&playerTexture);
    player.setOrigin(Vector2f(24.f, 24.f));
    player.setScale(Vector2f(3.f, 3.f));
    Animation animation(&playerTexture, Vector2u(6, 1), 0.1f);

    Clock clock;
    float deltaTime = .0f;

    while(window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }

        animation.Update(deltaTime, true);
        player.setTextureRect(animation.uvRect);

        view.reset(player.getGlobalBounds());
        window.setView(view);
        window.clear(Color::White);
        window.draw(player);
        window.display();
    }
    return 0;
}