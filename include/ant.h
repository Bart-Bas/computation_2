#ifndef _ANT_H_
#define _ANT_H_

#include <stdlib.h>
#include <stdio.h>

// Enums
typedef enum CellType
{
    CELL_DIRT,
    CELL_WATER,
    CELL_FOOD,
    CELL_HILL,
    CELL_ANT,
    CELL_ANT_ON_OWN_HILL
} CellType;

// Data structures
typedef struct Cell
{
    CellType type;
    unsigned int owner;
} Cell;

typedef struct Map
{
    Cell *cells;
    unsigned int rows;
    unsigned int cols;
} Map;

typedef struct GameSettings
{
    unsigned int loadtime;
    unsigned int turntime;
    unsigned int rows;
    unsigned int cols;
    unsigned int turns;
    unsigned int viewradius2;
    unsigned int attackradius2;
    unsigned int spawnradius2;
    size_t player_seed;
} GameSettings;

// Function prototypes
GameSettings *initialize_game();
void cleanup_game();

int read_turn();

Map *initialize_map(int rows, int cols);
void clear_map(Map *map);
Cell *index_map(Map *map, int row, int col);
void cleanup_map();
void print_map(Map *map, FILE *outputFile);

#endif // _ANT_H_