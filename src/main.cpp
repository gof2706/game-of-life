#include "game.h"
using namespace std;
extern void fillrand(int n, int m, vector< vector< int > >& a);
extern void logic(int n, int m, vector< vector< int > >& a);
extern void outp(int n, int m, vector< vector< int > >& a);
extern void fillbill(int n, int m, vector< vector< int > >& a);
extern void fillpuls(int n, int m, vector< vector< int > >& a);
extern void filldroz(int n, int m, vector< vector< int > >& a);
extern void fillpalk(int n, int m, vector< vector< int > >& a);
extern void fillprac(int n, int m, vector< vector< int > >& a);
extern void fillskre(int n, int m, vector< vector< int > >& a);
extern void filltumb(int n, int m, vector< vector< int > >& a);

int main()
{
    RenderWindow app(VideoMode(450, 450), "game-of-life");

    Texture t;
    t.loadFromFile("../src/img/wb.jpg");
    Sprite s(t);

    int w = 15;

    int n = 30, m = 30;
    vector< vector< int > > a(n, vector< int >(m, 0));
    //    fillrand(n, m, a);
    //	fillbill(n,m,a);
    //	filldroz(n,m,a);
    //	fillpalk(n,m,a);
    //	fillprac(n,m,a);
    //	fillskre(n,m,a);
    filltumb(n, m, a);
    //    fillpuls(n, m, a);

    while (1) {
        Event e;
        if ((e.type == Event::Closed) && (app.pollEvent(e)))
            app.close();
        app.clear(Color::White);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (a[i][j] == 0)
                    s.setTextureRect(IntRect(0 * w, 0, w, w));
                else
                    s.setTextureRect(IntRect(1 * w, 0, w, w));
                s.setPosition(i * w, j * w);
                app.draw(s);
            }
        }
        app.display();

        logic(n, m, a);
        sf::Time t1 = sf::milliseconds(50);
        sleep(t1);
    }
}
