#include "game.h"

int main()
{
	Music music;  //создаем объект музыки
	music.openFromFile("../Music/ibi.ogg");  //загружаем файл
	music.play();  //воспроизводим музыку
    Texture t;
    t.loadFromFile("../img/wb.jpg");
    Sprite s(t);
    int w = 15;
    int n = 70, m = 40;
    RenderWindow app(VideoMode(1050, 650), "game-of-life");
Image icon;
  if (!icon.loadFromFile("../img/wb.jpg")) {
    return 1;
  }
  app.setIcon(15, 15, icon.getPixelsPtr());
    vector< vector< int > > a(n, vector< int >(m, 0));
    while (app.isOpen()) {
        outp(n, m, a, app, s, w);
        logic(n, m, a);
	sf::Time t = sf::milliseconds(70);
        sf::sleep(t);
    }
    return 0;
}
