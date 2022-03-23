#include <iostream>

using namespace std;

struct Point
{
	double x;
	double y;

	void print() const
	{
		cout << "(" << x << ", " << y << ")"; //(x, y)
	}
};

class Ball
{
	Point center;
	double radius;
public:
	void initalize(Point center, double radius);
	void copy(Ball other);

	void move(Point target);

	void set_radius(double radius);
	double get_radius() const;

	void print() const;
};

void Ball::initalize(Point center, double radius)
{
	move(center);
	set_radius(radius);
}

void Ball::copy(Ball other)
{
	initalize(other.center, other.radius);
}

void Ball::move(Point target)
{
	this->center.x = target.x;
	this->center.y = target.y;
}

void Ball::set_radius(double radius)
{
	if(radius >= 0)
	{
		this->radius = radius; //Ball* this = &curr_object
	}
	else
	{
		this->radius = 0;
	}
}

double Ball::get_radius() const
{
	return this->radius;
}

void Ball::print() const
{
	cout << "Ball is at point ";
	this->center.print();
	cout << " with radius " << this->radius << endl;
}

int main()
{
	Ball my_ball;
	Point target = {-1, 2.3};

	my_ball.initalize(target, 2.3);

	Ball your_ball;

	your_ball.copy(my_ball);

	my_ball.set_radius(4.5);

	my_ball.print();
	your_ball.print();

	/*
	Point my_point = {2, 3};
	Point* point_address = &my_point;

	cout << my_point.x << endl;
	cout << point_address->x << endl;
	*/


	return 0;
}
