/*Oliwia Rogowska*/
#include "generate_next_state.h"

int generate_next_state(int neighbours, int row_index, int column_index, int **matrix)
    // jako argumenty: neighbours, row_index, column_index, current_matrix - w związku z tym zmiana zmiennych w całym kodzie
    
/*implementacja logiki wg Conwaya - 
decydowanie o stanie komorki na podstawie liczby sasiadow i jej stanu poprzedniego*/
{
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
