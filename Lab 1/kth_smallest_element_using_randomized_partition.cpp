/**
 * @author : its-mahi
*/

//Finding Kth smallest element using randomized partition.
#include <bits/stdc++.h>
using namespace std;
	

int partition(int a[], int p, int r) {
  int x = a[r];
  int i = p-1;
  int j;
   for(j=p; j<=r-1; j++) {
      if(a[j] <= x) {
          i++;
          if(a[i] != a[j]) {
              swap(a[i], a[j]);
          }
      }
  }
  swap(a[i+1], a[r]);
  return i+1;
}


int randomized_partition(int a[], int p, int r) {
  srand(time(NULL));
  int i = p + (rand() % (r - p + 1)); //range from p to r.
  swap(a[i], a[r]);
  return partition(a, p, r);
}


int findkthsmallest(int a[], int p, int r, int k) {
  if(p < r) {
      int q = randomized_partition(a,p,r);
      if(q == k) return a[q-1];
      if(q > k) {
          return findkthsmallest(a, p, q-1, k);
      } else {
          return findkthsmallest(a, q+1, r, k);
      }
  }
}


int main() {
   int n;
   cin >> n;
  
   int a[n];
  
   for(int i=0; i<n; i++) {
       cin >> a[i];
   }
  
   int k;
   cin >> k;
  
   cout << findkthsmallest(a, 0, n-1, k);
 
   return 0;
}
