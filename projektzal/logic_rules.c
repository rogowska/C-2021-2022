/*Oliwia Rogowska*/

int logic_rules(int neighbours, int rules)
{
    int rule;
    while (rules)
    {
        rule = rules % 10;
        rules /= 10;
        
        if (neighbours == rule)
        {
            return 1;
        }

    }
    return 0;
}
