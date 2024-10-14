#include <iostream>
#include "clsLoginScreen.h"

int main()
{

	
	while (true)
	{
		//system("Color 9");		
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}
    return 0;
}