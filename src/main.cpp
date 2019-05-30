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
        outp(n, m, a, app, s, w);
        logic(n, m, a);
    }
    return 0;
}
