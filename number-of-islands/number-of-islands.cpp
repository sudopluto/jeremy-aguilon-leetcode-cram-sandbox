class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       // plan:
       // iterate over vector, cell by cell.
       // if cell is 1 (land), increment counter by 1 and init flood fill to 0 (water)

        // if the grid is empty
       if (grid.empty() || grid[0].empty())
       {
           return 0;
       }

        int count = 0;
        int height = grid.size();
        int width = grid[0].size();
        // iter over height
       for (int ii = 0; ii < grid.size(); ++ii)
       {
           // iter of width
           for (int jj = 0; jj < grid[ii].size(); ++jj)
           {
               if (grid[ii][jj] == '1')
               {
                   ++count;
                   floodfill(grid, ii, jj, height, width);
                   // floodfill
               }
           }
       }

       return count;
    }
private:
    // if the given x and y are within the given bounds,
    // will zero out the element, and recursively call on
    // the 4 neighbors in the cardinal directions 
    void floodfill(vector<vector<char>>& grid, int ii, int jj, int height, int width)
    {
        // bounds
        if ((ii >= 0 && ii < height) && (jj >= 0 && jj < width))
        {
            // check element
            if (grid[ii][jj] == '1')
            {
                grid[ii][jj] = '0';
                floodfill(grid, ii -1, jj, height, width);
                floodfill(grid, ii +1, jj, height, width);
                floodfill(grid, ii, jj -1, height, width);
                floodfill(grid, ii, jj +1, height, width);
            }
        }
    }
};