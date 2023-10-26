#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

// Structure to represent 2D points
struct Point
{
	int x, y;
};

// Global variable to store the starting point for the convex hull
Point p0;

// Function to get the point second from the top of the stack without modifying it
Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

// Function to swap two Point structures
void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

// Function to calculate the square of the Euclidean distance between two points
int distSq(Point p1, Point p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Function to determine the orientation of three points: collinear, clockwise, or counterclockwise
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // Collinear
	return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Comparison function for qsort to sort points based on polar angle and distance from p0
int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;

	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
	return (o == 2) ? -1 : 1;
}

// Convex Hull algorithm
void convexHull(Point points[], int n)
{
	// Find the point with the lowest y-coordinate and leftmost x-coordinate
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].y;

		if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
			ymin = points[i].y, min = i;
	}

	// Swap the lowest point with the first point
	swap(points[0], points[min]);

	// Set p0 to the lowest point
	p0 = points[0];

	// Sort the points based on polar angle and distance from p0
	qsort(&points[1], n - 1, sizeof(Point), compare);

	// Initialize the modified size of the array
	int m = 1;

	// Remove collinear points and update the size of the modified array
	for (int i = 1; i < n; i++)
	{
		while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
			i++;
		points[m] = points[i];
		m++;
	}

	// If the modified array has less than 3 points, no convex hull exists
	if (m < 3)
		return;

	// Initialize a stack for the convex hull and push the first three points
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	// Process the remaining points
	for (int i = 3; i < m; i++)
	{
		while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
			S.pop();
		S.push(points[i]);
	}

	// Print the points on the convex hull
	while (!S.empty())
	{
		Point p = S.top();
		cout << "(" << p.x << ", " << p.y << ")" << endl;
		S.pop();
	}
}

int main()
{
	Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
					{0, 0}, {1, 2}, {3, 1}, {3, 3}};
	int n = sizeof(points) / sizeof(points[0]);

	// Call the convexHull function to find and print the convex hull points
	convexHull(points, n);

	return 0;
}
