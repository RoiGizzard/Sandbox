#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rows = 3, cols = 4, init = 7;
    vector<vector<int>> grid(rows, vector<int>(cols, init));

    grid[1].push_back(8);

    grid[2][2] = 9;

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[row].size(); col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
