/**
 * @author : its_mahi
 * Code : Line Segment Intersection Algorithm
 * 
 * Desc : Implement constant time algorithm to check if line segments P1P2 intersect with the line segment P3P4 or not.
 * Time Complexity : O(c)
*/


#include <iostream>
using namespace std;

int direction(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int res = (p3.first - p1.first)*(p2.second - p1.second) - (p3.second - p1.second)*(p2.first - p1.first);
    
    return res;
}

bool on_segment(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    if(min(p1.first, p2.first) <= p3.first && p3.first <= max(p1.first, p2.first) && min(p1.second, p2.second) <= p3.second && p3.second <= max(p1.second, p2.second)) {
        return true;
    }
    
    return false;
}

bool segment_intersect(pair<int, int> p1, pair<int, int> p2, pair<int, int> q1, pair<int, int> q2) {
    int d1 = direction(p1, p2, q1);
    int d2 = direction(p1, p2, q2);
    int d3 = direction(q1, q2, p1);
    int d4 = direction(q1, q2, p2);
    
    if(d1*d2 < 0 || d3*d4 < 0) {
        return true;
    }
    else if (d1 == 0 && on_segment(p1, p2, q1)) {
        return true;
    }
    else if (d2 == 0 && on_segment(p1, p2, q2)) {
        return true;
    }
    else if (d3 == 0 && on_segment(q1, q2, p1)) {
        return true;
    }
    else if (d4 == 0 && on_segment(q1, q2, p2)) {
        return true;
    }
    
    return false;
}

int main() {
    
    cout << "Line Segment Intersection Algorithm" << endl;
    
    cout << "Enter the value of 4 points coordinates x and y : " << endl;
    pair<int, int> p1;
    pair<int, int> p2;
    pair<int, int> q1;
    pair<int, int> q2;
    
    cout << "Enter the values of first points :" << endl;
    cin >> p1.first >> p1.second;
    
    cout << "Enter the values of second points :" << endl;
    cin >> p2.first >> p2.second;
    
    cout << "Enter the values of third points :" << endl;
    cin >> q1.first >> q1.second;
    
    cout << "Enter the values of fourth points :" << endl;
    cin >> q2.first >> q2.second;
    
    if(segment_intersect(p1, p2, q1, q2)) {
        cout << "This 2 segment are intersecting" << endl;
    }
    else {
        cout << "This 2 segment are not intersection" << endl;
    }
    
    return 0;
}
