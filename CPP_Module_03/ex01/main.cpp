#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap noName;
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");
    ClapTrap bot3(bot1);
    noName = bot1;

    for (int i = 0; i < 11; i++)
    {
        bot1.attack("Bot2");
        bot2.takeDamage(1);
        bot2.beRepaired(1);
    }
    ScavTrap noName1;
    ScavTrap Guardian1("Guardian");
    ScavTrap Guardian2(Guardian1);
    noName1 = Guardian1;

    Guardian1.attack("Bot1");
    bot1.takeDamage(20);
    bot1.beRepaired(1);
    Guardian1.guardGate();
    return 0;
}
/*
int main()
{
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");

    for (int i = 0; i < 3; i++)
    {
        bot1.attack("Bot2");
        bot2.takeDamage(5);
        bot2.beRepaired(1);
    }
    return 0;
}*/
