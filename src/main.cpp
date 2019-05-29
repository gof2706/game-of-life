#include "game.h"

int main()
{
    Texture t;
    t.loadFromFile("../src/img/wb.jpg");
    Sprite s(t);
    int w = 15;
    int n = 70, m = 40;
    RenderWindow app(VideoMode(1050, 600), "game-of-life");
    vector< vector< int > > a(n, vector< int >(m, 0));
    while (app.isOpen()) {
        Event e;
        if (e.type == Event::Closed)
            app.close();
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
        outp(n, m, a, app, s, w);
        logic(n, m, a);
    }
    return 0;
}
