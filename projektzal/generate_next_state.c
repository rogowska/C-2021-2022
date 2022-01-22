/*Oliwia Rogowska*/
#include "generate_next_state.h"
#include "logic_rules.h"

int generate_next_state(int neighbours, int row_index, int column_index, int **matrix)
    
/*Implementation of Conway logic - 
deciding the state of a cell based on the number of its neighbours and the previous state*/
{
    /*Calculating next state for the dead cell, born rules*/
    if (matrix[column_index][row_index] == 0)
    {
        if (logic_rules(neighbours,3))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    /*Calculating next state for the living cell, survive rules*/
    if (matrix[column_index][row_index] == 1)
    {
        if (logic_rules(neighbours,23))
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
