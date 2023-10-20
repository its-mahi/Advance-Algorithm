/**
 * @author : its_mahi
 * 
 * Code : Randomized algorithm
*/

#include <bits/stdc++.h>
using namespace std;
void shift(char *edgeList, int index, int ub)
{
    for (int i = index; i <= ub; i++)
    {
        edgeList[i] = edgeList[i + 1];
    }
    for (int i = 0; i < ub; i++)
    {
        cout << edgeList[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> vertexCover;
    vector<int> edgesCovered;

    char edgePart1[7] = {'A', 'B', 'B', 'B', 'A', 'E', 'C'};
    char edgePart2[7] = {'B', 'D', 'C', 'E', 'E', 'D', 'D'};
    int ub = 6;
    int lb = 0;

    bool flag = false;
    while (edgesCovered.size() != 7)
    {

        if (edgesCovered.size() == 6)
        {
            for (int i = 0; i < vertexCover.size(); i++)
            {
                cout << "vertexCover: " << char(vertexCover[i]) << endl;

                if (vertexCover[i] == edgePart1[0] || vertexCover[i] == edgePart2[0])
                {
                    cout << "heyy: " << endl;
                    flag = true;

                    break;
                }
            }
            if (flag == true)
            {
                break;
            }
        }
        int index = (rand() % (ub - lb + 1)) + lb;
        edgesCovered.push_back(index);
        vertexCover.push_back(edgePart1[index]);
        vertexCover.push_back(edgePart2[index]);
        cout << "chosen vertex from A: " << edgePart1[index] << " " << edgePart2[index] << endl;

        shift(edgePart1, index, ub);
        shift(edgePart2, index, ub);
        ub--;

        for (int i = 0; i < ub; i++)
        {
            if (edgePart1[i] == edgePart1[index] || edgePart1[i] == edgePart2[index])
            {
                edgesCovered.push_back(i);
                shift(edgePart1, i, ub);
                shift(edgePart2, i, ub);
                ub--;
            }

            if (edgePart2[i] == edgePart2[index] || edgePart2[i] == edgePart1[index])
            {
                edgesCovered.push_back(i);
                shift(edgePart1, i, ub);
                shift(edgePart2, i, ub);
                ub--;
            }
        }
    }

    set<char> s;

    for (int X : vertexCover)
    {
        s.insert(X);
    }

    vector<int> vc(s.begin(), s.end());

    cout << "final answer : " << endl;
    for (int i = 0; i < vc.size(); i++)
    {
        cout << char(vc[i]) << " ";
    }
    cout << endl;
}
