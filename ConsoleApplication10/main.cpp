#include<iostream>
using namespace std;

#define tab "\t"

class Point
{

	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		if (x >= -100 && x <= 100)
		{
			this->x = x;
		}
		else
		{
			throw exception("Bad x");
			//this->x = 0;
		}
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(Point other)
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		return sqrt(x_distance*x_distance + y_distance * y_distance);*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));

		//function sqrt - вычисляет квадратный корень

	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	int a;
	Point A;
	//A.x = 2;
	//A.y = 3;
	A.set_x(-2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;
	Point* pA = &A;
	cout << pA->get_x() << tab << pA->get_y() << endl;
	cout << (*pA).get_x() << tab << (*pA).get_y() << endl;
	Point B;
	B.set_x(2);
	B.set_y(5);
	cout << A.distance(B) << endl;
}