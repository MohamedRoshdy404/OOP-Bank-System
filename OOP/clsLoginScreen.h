#pragma once
#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsUser.h"


class clsLoginScreen : protected clsScreen
{

private:

	static void _Login()
	{

		short Counter = 0;

		bool loginFaild = false;

		string Username, Password;
		do
		{
			Counter++;

			if (Counter <= 4)
			{

				if (loginFaild)
				{
					cout << "\nInvalaid Username/Password , Number of login attempts [ 3 ]";
					cout << "\nTry number [ " << Counter - 1 << " ]";
					_sleep(1000);
				}

				cout << "\nEnter Username? ";
				cin >> Username;

				cout << "\nEnter Password? ";
				cin >> Password;

				CurrentUser = clsUser::Find(Username, Password);

				loginFaild = CurrentUser.IsEmpty();


			}
			else
			{
				cout << "You are not authorized to access the system. Please contact the admin personally to solve the problem." << endl;
				return;
			}



		} while (loginFaild);

		cout << "\a";
		system("color 9");
		clsMainScreen::ShowMainMenue();
	}


public:


	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}


};

