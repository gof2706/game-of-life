#include "game.h"
void outp(
        int n,
        int m,
        std::vector< std::vector< int > >& a,
        RenderWindow& app,
        Sprite& s,
        int w)
{
    Font font;
    if (!font.loadFromFile("../font/16761.ttf")) {
        // ошибка...
    }
    Text text1;
    text1.setFont(font);
    text1.setString(
            "Escape-exit R-rand B-billiard P-pulsar S-skrepka T-tumbler "
            "D-drozd W-prachka Q-stick");
    text1.setCharacterSize(15);
    text1.setFillColor(Color::Black);
    text1.setPosition(30, 605);

    sf::Event event;
    while (app.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            app.close();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        app.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::R)) {
        fillrand(n, m, a);
    }
    if (Keyboard::isKeyPressed(Keyboard::B)) {
        fillbill(n, m, a);
    }
    if (Keyboard::isKeyPressed(Keyboard::P)) {
        fillpuls(n, m, a);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        fillskre(n, m, a);
    }
    if (Keyboard::isKeyPressed(Keyboard::T)) {
        filltumb(n, m, a);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        filldroz(n, m, a);
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        fillprac(n, m, a);
    }
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        fillpalk(n, m, a);
    }
    app.clear(Color::White);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0)
                s.setTextureRect(IntRect(0 * w, 0, w, w));
            else
                s.setTextureRect(IntRect(1 * w, 0, w, w));
            s.setPosition(i * w, j * w);
            app.draw(s);
        }
    }
    app.draw(text1);
    app.display();
}

