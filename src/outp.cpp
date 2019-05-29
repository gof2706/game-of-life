#include "game.h"
void outp(
        int n,
        int m,
        std::vector< std::vector< int > >& a,
        RenderWindow& app,
        Sprite& s,
        int w)
{
    app.clear(Color::White);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            {
                if (a[i][j] == 0)
                    s.setTextureRect(IntRect(0 * w, 0, w, w));
                else
                    s.setTextureRect(IntRect(1 * w, 0, w, w));
                s.setPosition(i * w, j * w);
                app.draw(s);
            }
        }
    app.display();
}
