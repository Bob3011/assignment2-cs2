#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	float x;
	float y;

public:
	Point()
	{
		x = 0.0;
		y = 0.0;
	}

	Point(float a, float b)
	{
		x = a;
		y = b;
	}

	void SetX(float num)
	{
		//srand(time(0));
		x = num;
		
	}
	void SetY(float num)
	{
		//srand(time(0));
		y = num;
	}

	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}

	void display()
	{
		cout << "( " << x << ", " << y << " )" << endl;
	}

	float distanceToCenter(Point p)
	{
		float num;
		num = sqrt((pow(x - (p.x), 2)) + (pow(y - (p.y), 2)));

		return num;
	}

};