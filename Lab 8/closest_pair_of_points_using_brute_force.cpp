/**
 * @author : its_mahi
 * Code : Geometric Algorithms - Find closest pair of points from a given set of n points using Brute-force approach.
 * 
 * Desc : 
*/

#include <bits/stdc++.h>
using namespace std;

int check_dist(int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main() {
    
    cout << "Enter a number of points : ";
    int n;
    cin >> n;
    
    vector<pair<int, int>> pts;
    
    cout << "Enter the data of all points" << endl;
    for(int i=0 ; i<n ; i++) {
        int a,b;
        cin >> a >> b;
        
        pts.push_back({a, b});
    }
    
    int min_dist = INT_MAX;
    pair<int, int> pt1, pt2;
    
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            int dist = check_dist(pts[i].first, pts[i].second, pts[j].first, pts[j].second);
            
            if(min_dist > dist) {
                min_dist = dist;
                pt1 = pts[i];
                pt2 = pts[j];
            }
        }
    }
    
    cout << "Minimum distance is : " << min_dist << endl;
    cout << "First points is : (" << pt1.first << ", " << pt1.second << ")" << endl;
    cout << "Second points is : (" << pt2.first << ", " << pt2.second << ")" << endl;
    
    return 0;
}
