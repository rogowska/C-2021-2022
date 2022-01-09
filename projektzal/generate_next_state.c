/*Oliwia Rogowska*/
#include "generate_next_state.h"

int generate_next_state(int neighbours, int row_index, int column_index, int **matrix)
    
/*Implementation of Conway logic - 
deciding the state of a cell based on the number of its neighbours and the previous state*/
{
    /*Calculating next state for the dead cell*/
    if (matrix[column_index][row_index] == 0)
    {
        if (neighbours == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    /*Calculating next state for the living cell*/
    if (matrix[column_index][row_index] == 1)
    {
        if (neighbours == 2 || neighbours == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
