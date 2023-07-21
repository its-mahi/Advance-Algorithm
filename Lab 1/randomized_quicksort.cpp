/**
 * @author : its-mahi
*/

//Randomized Quick Sort.
#include <bits/stdc++.h>
using namespace std;

int comp = 0, swaps = 0;

int partition(int a[], int p, int r) {
   int x = a[r];
   int i = p-1;
   int j;
  
   for(j=p; j<=r-1; j++) {
       comp++;
       if(a[j] <= x) {
           i++;
           if(a[i] != a[j]) {
               swaps++;
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


void randomized_QuickSort(int a[], int p, int r) {
   if(p < r) {
       int q = randomized_partition(a,p,r);
       randomized_QuickSort(a, p, q-1);
       randomized_QuickSort(a, q+1, r);
   }
}


int main() {
   int n;
   cin >> n;
  
   int a[n];
  
   for(int i=0; i<n; i++) {
       cin >> a[i];
   }
  
   randomized_QuickSort(a, 0, n-1);
  
   for(int i=0; i<n; i++) cout << a[i] << " ";
  
   cout << "\nNo. of comparisons :" << comp << endl;
   cout << "No. of swaps :" << swaps << endl;
   return 0;
}
