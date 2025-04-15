#include <bits/stdc++.h>
using namespace std;
int add(int freqen[], int i, int j);
int optimalSearTree(int key[], int freqen[], int n)
{
  int optCost[n][n];
  for (int i = 0; i < n; i++)
    optCost[i][i] = freqen[i];
  for (int l = 2; l <= n; l++)
  {
    for (int i = 0; i <= n - l + 1; i++)
    {
      int j = i + l - 1;
      optCost[i][j] = INT_MAX;
      for (int r = i; r <= j; r++)
      {
        int cost = ((r > i) ? optCost[i][r - 1] : 0) +
                   ((r < j) ? optCost[r + 1][j] : 0) +
                   add(freqen, i, j);
        if (cost < optCost[i][j])
          optCost[i][j] = cost;
      }
    }
  }
  return optCost[0][n - 1];
}
int add(int freqen[], int i, int j)
{
  int sum = 0;
  for (int k = i; k <= j; k++)
    sum += freqen[k];
  return sum;
}
int main()
{
  int key[] = {10, 12, 20};
  int freqen[] = {34, 8, 50};
  int n = sizeof(key) / sizeof(key[0]);
  cout << "The Cost of Optimal BST is: " << optimalSearTree(key, freqen, n);
  return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

// Function for calculating the sum of array elements: freqen[i] to freqen[j]
int add(int freqen[], int i, int j);

// A recursive function for calculating the cost of the best binary search tree
int optimalCost(int freqen[], int i, int j){
    // Base cases
    if (j < i)
        return 0;
    if (j == i)
        return freqen[i];

    // Calculate the sum of freqen[i] to freqen[j]
    int freqSum = add(freqen, i, j);

    int minim = INT_MAX;

    // Consider each element as a root and recursively calculate the BST cost. 
    // Compare the cost to the minimum and, if necessary, update the minimum.
    for (int r = i; r <= j; ++r){
        int optCost = optimalCost(freqen, i, r - 1) +
                   optimalCost(freqen, r + 1, j);
        if (optCost < minim)
            minim = optCost;
    }

    return minim + freqSum;
}

// The main function responsible for calculating the minimum cost of a binary search tree. 
// It primarily uses optimalCost() to determine the optimal cost.
int optimalSearchTree(int key[],
                      int freqen[], int n){
    return optimalCost(freqen, 0, n - 1);
}

// Function for calculating the sum of array elements: freqen[i] to freqen[j]
int add(int freqen[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freqen[k];
    return s;
}

// Driver Code
int main(){
    int key[] = {10, 12, 20};
    int freqen[] = {34, 8, 50};
    int n = sizeof(key) / sizeof(key[0]);
    cout << "The Cost of Optimal BST is: "
         << optimalSearchTree(key, freqen, n);
    return 0;
}*/