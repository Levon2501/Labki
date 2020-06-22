#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
struct point 
{
	double x;
	double y;
};

double det(struct point p1, struct point p2) 
{
	return p1.x * p2.y - p1.y * p2.x;
}

int fun(int count, ...) 
{

	struct point pointsArray[count];
	struct point vectorsArray[count];
	va_list points;
	va_start(points, count);

	for (int i = 0; i < count; ++i) 
	{
		pointsArray[i] = va_arg(points, struct point);
	}
	vectorsArray[count - 1].x = pointsArray[0].x - pointsArray[count - 1].x;
	vectorsArray[count - 1].y = pointsArray[0].y - pointsArray[count - 1].y;

	for (int i = 0; i < count - 1; ++i) 
	{
		vectorsArray[i].x = pointsArray[i + 1].x - pointsArray[i].x;
		vectorsArray[i].y = pointsArray[i + 1].y - pointsArray[i].y;
	}

	double curDet = 0;
	double prevDet = 0;
	for (int i = 0; i < count - 1; ++i) 
	{
		curDet = det(vectorsArray[i], vectorsArray[i + 1]);
		if (curDet * prevDet < 0) 
		{
			return 0;
		}
		prevDet = curDet;
	}
	va_end(points);

	return 1;
}

int main() 
{
	struct point p1; struct point p2; struct point p3; struct point p4; struct point p5; struct point p6;
	p1.x = 0; p1.y = 0;
	p2.x = 0; p2.y = 1;
	p3.x = 1; p3.y = 1;
	p4.x = 1; p4.y = 0;
	printf("%d\n", fun(4, p1, p2, p3, p4, p5, p6));
	p1.x = 0; p1.y = 0;
	p2.x = 2; p2.y = 0;
	p3.x = 2; p3.y = 2;
	p4.x = 0; p4.y = 2;
	printf("%d\n", fun(4, p1, p2, p3, p4, p5, p6));
}
