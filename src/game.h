#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
using namespace sf;
using namespace std;
extern void fillrand(int n, int m, vector< vector< int > >& a);
extern void logic(int n, int m, vector< vector< int > >& a);
extern void fillbill(int n, int m, vector< vector< int > >& a);
extern void fillpuls(int n, int m, vector< vector< int > >& a);
extern void fillskre(int n, int m, vector< vector< int > >& a);
extern void filltumb(int n, int m, vector< vector< int > >& a);
extern void fillpalk(int n, int m, vector< vector< int > >& a);
extern void fillprac(int n, int m, vector< vector< int > >& a);
extern void filldroz(int n, int m, vector< vector< int > >& a);
extern void
outp(int n,
     int m,
     std::vector< std::vector< int > >& a,
     RenderWindow& app,
     Sprite& s,
     int w);
