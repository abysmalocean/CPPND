#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <math.h> 
#include <unordered_set>
#include <algorithm>



enum class State 
{
    kEmpty, 
    kObstacle,
    kClosed, 
    kPath,
    KStart,
    KFinish
}; 

const int delta[4][2]
{
    {-1,0},
    {0,-1},
    {1,0},
    {0,1}
}; 




std::vector<State> ParseLine(std::string line)
{
    std::istringstream sline(line); 
    int n; 
    char c; 
    std::vector<State> row; 
    while (sline >> n >> c && c == ',')
    {
        if (n == 0)
        {
            row.push_back(State::kEmpty); 
        } else
        {
            row.push_back(State::kObstacle); 
        }
    }
    return row; 
}

std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
    std::ifstream myfile(path); 
    std::vector<std::vector<State>> board{}; 
    
    if(!myfile.is_open())
    {
        printf("file not open or not found \n"); 
        return board;  
    }
    if (myfile)
    {
        std::string line;
        while(getline(myfile, line))
        {
            std::vector<State> row = ParseLine(line); 
            board.push_back(row); 
        }
    }
    return board; 
}

std::string CellString(State cell) 
{
  switch(cell) 
  {
    case State::kObstacle: return "⛰️   ";
    case State::kPath: return "🚗   ";
    case State::KStart: return "🚦   ";
    case State::KFinish: return "🏁   ";
    default: return "0   "; 
  }
}

void PrintBoard(const std::vector<std::vector<State>> board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
            std::cout <<CellString(board[i][j]);
        }
        std::cout << "\n";
    }
}

// caluculate the l2 distance

double Heuristic(int x1, int y1, int x2, int y2) 
{
    return std::sqrt((x2 - x1)*(x2-x1) + (y2 - y1)*(y2-y1));
}
// manhattan distance
int HeuristicManhattan(int x1, int y1, int x2, int y2) 
{
    return abs(x2 - x1) + abs(y2 - y1); 
}

/*
* Implement the A* algorithm
*/
// Compare the F values of two cells 
bool Compare(const std::vector<int> a, const std::vector<int> b)
{
    int f1 = a[2] + a[3];
    int f2 = b[2] + b[3]; 
    return f1 > f2; 
}

// Sort the tow-dimensional vector if ints in descending order
inline void
CellSort(std::vector<std::vector<int>> &v)
{
    std::sort(v.begin(), v.end(), Compare); 
}

inline void
AddToOpen(int x, int y, int g, int h, 
          std::vector<std::vector<int>> &openlist, std::vector<std::vector<State>> &grid)
{
    openlist.push_back(std::vector<int>{x,y,g,h}); 
    grid[x][y] = State::kClosed; 
}


// check the a cell is valid; on the grid, not an onstacle, and clear. 
inline bool
CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid)
{
    bool on_grid_x = (x >= 0 && x < grid.size()); 
    bool on_grid_y = (y >= 0 && y < grid[0].size()); 
    if (on_grid_x && on_grid_y)
    {
        return grid[x][y] == State::kEmpty; 
    }
    return false; 
}

// Expand current nodes neighbors and add them to the open list
void
ExpandNeighbors(const std::vector<int> &current, int goal[2], 
                std::vector<std::vector<int>> &openlist,
                std::vector<std::vector<State>> &grid)
{
    // get the current node's data
    int x = current[0]; 
    int y = current[1]; 
    int g = current[2]; 

    // loop through current node's potential neighbors
    int size = sizeof(delta) / sizeof(delta[0]); 

    for (int i =0; i < size; ++i)
    {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        if (CheckValidCell(x2,y2,grid))
        {
            // Increment g value and add neigbor to open list
            int g2 = g + 1; 
            int h2 = HeuristicManhattan(x2, y2, goal[0], goal[1]); 
            AddToOpen(x2, y2, g2, h2, openlist, grid); 
        }

    }
}

/*
* Implement A* algorithm
*/

void 
Search(std::vector<std::vector<State>>& grid, int init[2], int goal[2])
{
    // create the vector of ipen nodes
    std::vector<std::vector<int>> open{}; 

    // Initialize the stating node
    int g = 0; 
    int h = HeuristicManhattan(init[0], init[1], goal[0], goal[1]); 
    AddToOpen(init[0], init[1], g, h, open, grid); 

    while(open.size() > 0)
    {
        // Get the next node
        CellSort(open); 
        std::vector<int> current = open.back(); 
        open.pop_back(); 
        int x = current[0]; 
        int y = current[1]; 
        grid[x][y] = State::kPath; 

        // check if we're done. 
        if (x == goal[0] && y == goal[1])
        {
            printf("Found a Path\n");
            return; 
        }

        ExpandNeighbors(current, goal, open, grid);
    }
    printf("No path has been found\n"); 
    
}



int main()
{
    int init[2] = {0,0}; 
    int goal[2] = {5,5}; 
    std::vector<std::vector<State>> board = ReadBoardFile("1.board");
    Search(board, init, goal); 
    PrintBoard(board);
}