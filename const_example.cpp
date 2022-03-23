#include <iostream>

using namespace std;

struct Point
{
	double x;
	double y;

	void print()
	{
		cout << "(" << x << ", " << y << ")";
	}
};

class Ball
{
	Point center;
	double radius;

public:
	void move(Point target);

	void set_radius(/*const*/ double radius); //мутатор
	double get_radius() const; //функция за достъп
};

void Ball::move(Point target)
{
	this->center.x = target.x;
	this->center.y = target.y;
}

void Ball::set_radius(/*const*/ double radius)
{
	this->radius = radius;
}

double Ball::get_radius() const
{
	return radius;
}

int main()
{
	Ball my_ball;

	my_ball.set_radius(2.5);
	cout << my_ball.get_radius() << endl;
	return 0;
}
