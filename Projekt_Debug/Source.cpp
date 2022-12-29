#include <SFML/Graphics.hpp>
#include "Snake.h"
#include <time.h>
#include "apple.h"

using namespace sf;

int N = 30, M = 20;//размер поля
int ts = 25;//размер самих плиток
int dir = 2;//Направление движения змеича в нашем случае вправо
int num = 4;//Длина Змеича
bool game = true; //Необходимо для создания проигрыша
void Tick() {
	for (int i = num; i > 0; i--) {
		s[i].x = s[i - 1].x;//Старт// нужно чтобы все ячейкм Змеича следовали за ним
		s[i].y = s[i - 1].y;

	}


	if (dir == 0)//Условия чтобы Змеич мог двигаться в другие стороны
		s[0].y += 1;//Вниз
	if (dir == 1)
		s[0].x -= 1;//Влево
	if (dir == 2)
		s[0].x += 1;//Вправо
	if (dir == 3)
		s[0].y -= 1;//Вверх



	if (s[0].x > N)
		s[0].x = 0;//Условие чтобы Змеич возвращался с другой стороын когда касаестя стенок
	if (s[0].x < 0)
		s[0].x = N;
	if (s[0].y > M)
		s[0].y = 0;
	if (s[0].y < 0)
		s[0].y = M;

	if ((s[0].x == f.x) && s[0].y == f.y) {//Если координата головы касается координаты яблока
		num++; //Когда координаты яблока и головы =, развер тела увеличивается на 1
		f.x = rand() % N;//Рандомные кординаты для следующего яблочка
		f.y = rand() % M;
	}
	for (int i = 1; i < num; i++) {

		if ((s[0].x == s[i].x) && (s[0].y == s[i].y)) {

			game = false;
		}
	}

}











int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(ts * N, ts * M), "3meuch");

	Texture t;
	t.loadFromFile("C:/Paint/tiles.png");//Подключаем png файл с полем
	Sprite tiles(t);
	Texture sn;
	sn.loadFromFile("C:/Paint/snake.png"); //Подключаем png файл со змейкой
	Sprite snake(sn);
	Texture ap;
	ap.loadFromFile("C:/Paint/apple.png");//Подключаем png с яблочком
	Sprite apple(ap);
	Texture go;
	go.loadFromFile("C:/Paint/gameover.png");// Подключаем png с надпиью "Game Over"
	Sprite gameover(go);
	gameover.setPosition(0, 175); //Такие Значения чтобы надписть была по центру
	Clock clock;
	float timer = 0, delay = 0.1; //Скорость самого Змеича
	f.x = 10;
	f.y = 10;//Зададим начальные координаты яблочка

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();//Делаем привязку ко времени//без этого движения не будет
		timer += time;
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed) {
				window.close();
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			dir = 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) { //Переносим Значения с Dir на клавиатуру то есть мы задаем направление
			dir = 2;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			dir = 3;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			dir = 0;

		}
		if (timer > delay && game) { //Условие чтобы змеичем можно было управлять и условие для проигрыша
			timer = 0;
			Tick();
		
		
		}
		window.clear();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++) {
				tiles.setPosition(i * ts, j * ts);//Создаем двумерный цикл рисующий плиточки
				window.draw(tiles);

			}


		}
		for (int i = 0; i < num; i++) {//Сделаем нашего Змеича видимым
			if (i != 0)//не является головой
				snake.setTextureRect(IntRect(0, 0, ts, ts));//Вставляем  зеленый квадрат(не голова) и размер 
			else //Является головой
				snake.setTextureRect(IntRect(dir*ts, ts, ts, ts));//Вставляем  2 кадра головы
			snake.setPosition(s[i].x * ts, s[i].y * ts);//Зададим позицию для Змеича
			window.draw(snake);

		}
		apple.setPosition(f.x * ts, f.y * ts);
		window.draw(apple);
		if (!game)
			window.draw(gameover);
		window.display();



	}
	return 0;






}



	