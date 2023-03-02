#include <iostream>
#include "ClassPoint.h"
#include <ctime>
#include <cstdlib>
using namespace std;


Point centerPoints(Point* a, float n)				// findes the center of a cluster by adding all x and all y then div by (n) num 
{													//then div by (n) num of points
	float sum_x = 0;
	float sum_y = 0;
	float av_x = 0;
	float av_y = 0;

	for (int i = 0; i < n; i++)
	{
		sum_x += a[i].GetX();
	}

	for (int i = 0; i < n; i++)
	{
		sum_y += a[i].GetY();
	}

	av_x = sum_x / n;
	av_y = sum_y / n;

	Point center(av_x, av_y);

	return center;
}

void closestCluster(Point* a, int num, Point* b, int num2, Point* p, int num3)
{
	Point CofCA;		//center of cluster A
	Point CofCB;		//cneter of cluster B
	float DistanceA;
	float DistanceB;
	char cLetter;		//cluster letter 

	CofCA = centerPoints(a, num);
	CofCB = centerPoints(b, num2);

	for (int i = 0; i < num3; i++)
	{
		Point c;
		float x;
		float y;

		x = (p + i)->GetX();
		y = (p + i)->GetY();

		c.SetX(x);
		c.SetY(y);

		DistanceA = CofCA.distanceToCenter(c);
		DistanceB = CofCB.distanceToCenter(c);

		if (DistanceA > DistanceB)
		{
			cout << "point p" << i + 1 << " is closer to cluster B" << endl;
		}
		else if (DistanceB > DistanceA)
		{
			cout << "point p" << i + 1 << " is closer to cluster A" << endl;
		}
		else if (DistanceA == DistanceB)
		{
			cout << "point p" << i + 1 << " is int he middel of both cluster" << endl;
		}
	}
}

int main()
{
	Point* a;
	Point* b;
	Point* p;
	Point centerA;
	Point centerB;
	float num;
	float num2;
	float num3;

	srand(time(NULL));

	cout << "please enter a number of points for cluster a" << endl;
	cin >> num;

	cout << "please enter a number of points for cluster b" << endl;
	cin >> num2;

	cout << "please enter a number of points for Point p" << endl;
	cin >> num3;

	a = new Point[num];
	b = new Point[num2];
	p = new Point[num3];

	for (int i = 0; i < num; i++)				//setting x for object a
	{
		float temp;
		temp = rand() % 21;
		float random = temp + 70;
		(*(a+i)).SetX(random);

	}

	for (int i = 0; i < num; i++)				//setting y for object a
	{
		float temp;
		temp = rand() % 21;
		float random = temp + 70;
		(a+i)->SetY(random);
	}

	/*for (int i = 0; i < num; i++)			// diplay to debug
	{
		a[i].display();
	}*/

	for (int i = 0; i < num; i++)				//setting x for object b
	{
		float temp=0;
		temp = 20 + (rand() % 21);
		(b+i)->SetX(temp);
	}

	for (int i = 0; i < num; i++)				//setting y for object b
	{
		float temp=0;
		temp = 20 + (rand() % 21);
		(b+i)->SetY(temp);
	}

	/*for (int i = 0; i < num; i++)			// display to debug
	{
		b[i].display();
	}*/

	for (int i = 0; i < num3; i++)				//setting x for object p
	{
		float temp = 0;
		temp = 5 + (rand() % 96);
		(p + i)->SetX(temp);
	}

	for (int i = 0; i < num3; i++)				//setting y for object p
	{
		float temp = 0;
		temp = 5 + (rand() % 96);
		(p + i)->SetY(temp);
	}

	cout << "the center of cluster A is: ";
	centerA = centerPoints(a, num);
	centerA.display();

	cout << "the center of cluster B is: ";
	centerB = centerPoints(b, num);
	centerB.display();

	cout << endl;

	closestCluster(a, num, b, num2, p, num3);
	
	return 0;
}