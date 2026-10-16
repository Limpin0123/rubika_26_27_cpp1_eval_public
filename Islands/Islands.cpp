#include <vector>
#include <assert.h>

#include <hash_set>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

struct Index {
    int x;
    int y;

    Index(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};


int count_islands(std::vector<std::vector<char>>& grid)
{
    std::hash_set<Index> visitedTiles;
    int islandFound = 0;

    for (int y = 0; y < grid.size(); y ++)
    {
        for (int x = 0; x < grid.at(y).size(); x++)
        {
            Index i = Index(x, y);
            VisiteTile(i, grid);
        }
    }
	return -1;
}
void VisiteTile(Index& index, std::vector<std::vector<char>>& grid)
{
    Index aboveTile = Index(index.x, index.y-1);
    Index rightTile = Index(index.x+1, index.y);
    Index belowTile = Index(index.x, index.y+1);
    Index leftTile = Index(index.x-1, index.y);


    //L'objectif était de faire des appels récursifs jusqu'à ce qu'aucun voisin ne soit valide ou du sol.
    //Dès lors, on sort de cette fonction et on incrémente le nombre d'ile de 1
    //On boucle ainsi sur toute les tile en faisant attention de ne pas recommencé le process sur une tile déjà visitée (d'où la présence du hash_set)
    if (IsIndexValid(aboveTile, grid))
    {
        if (IsLand(index, grid))
        {

        }
    }
    if (IsIndexValid(rightTile, grid))
    {
        if (IsLand(index, grid))
        {

        }
    }
    if (IsIndexValid(belowTile, grid))
    {
        if (IsLand(index, grid))
        {

        }
    }
    if (IsIndexValid(leftTile, grid))
    {
        if (IsLand(index, grid))
        {

        }
    }
}
bool IsIndexValid(Index& index, std::vector<std::vector<char>>& grid)
{
    if (index.x < 0 || index.x > grid.size()) return false;

    if (index.y < 0 || index.y > grid.at(index.x).size()) return false;

    return true;
}
bool IsLand(Index& index, std::vector<std::vector<char>>& grid)
{
    return grid.at(index.x).at(index.y) == '1';
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };
        assert(count_islands(grid) == 3);
    }

    return 0;
}