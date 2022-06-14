#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int a = 0, sc = 0, num = 0, dist = 8;
	string PName;
	vector<string>Names;

	//Player names input
	while (PName.size() == 0)		//To ignore blank first players` name
	{
		cout << "\n\n\n";
		cout << setw(dist) << "" << "Greetings! \n" << setw(dist) << "";
		cout << "Enter Player" << a + 1 << " name: ";
		getline(cin, PName);
		if (PName.size() == 0)
			system("cls");
	}
	while (PName.size() > 0)
	{
		a++;
		Names.push_back(PName);
		PName.clear();
		cout << "\n";
		cout << setw(dist) << "";
		cout << "Enter Player" << a + 1 << " name or press ENTER to start: ";
		getline(cin, PName);
		//system("cls");			//Optional. To hide previous players while entering names
	}
	vector<int>S(a, 0);

	while (1)
	{
		system("cls");
		cout << "\n\n\n";

		//Draw table with Player numbers
		cout << setw(dist) << "";
		for (int i = 0; i < a; i++)
		{
			int w = Names[i].size() + 2;
			if (w < 10)
			{
				w = 10;
			}
			cout << "|" << "player" << (i + 1) << setw(w - 7) << " ";
			cout << "|";
		}
		cout << endl;

		//Draw table with Player names
		cout << setw(dist) << "";
		for (int i = 0; i < a; i++)
		{
			int w = Names[i].size() + 2;
			if (w < 10)
			{
				w = 10;
			}
			cout << "| " << (Names[i]) << setw(w - 2 - Names[i].size()) << "";
			cout << " |";
		}
		cout << endl;

		//Counting Scores
		if (num > 0 && num <= a)
			S[num - 1] += sc;

		//Draw table with Scores
		cout << setw(dist) << "";
		for (int i = 0; i < a; i++)
		{
			int w = Names[i].size() + 2;
			if (w < 10)
				w = 10;
			cout << "| ";
			cout << setw(4) << S[i];
			cout << setw(w - 5) << "";
			cout << "|";
		}
		cout << endl;

		//Scores input
		if (a > 1)

			cout << "\n\n" << setw(dist) << "";
		cout << "Enter player number (from 1 to " << a << ")" << "\n" << setw(dist) << "" << "Or enter 0 to exit" << "\n" << setw(dist) << "" << endl;
		cout << setw(dist) << "";
		while (!(cin >> num) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << endl << setw(dist) << "";
			cout << "NO!!! Numbers from 1 to " << a << ", please!" << endl << setw(dist) << "";
		}

		//cin >> num;
		if (num == 0)
			return 0;
		if (num > 0 && num <= a)
		{
			cout << endl << setw(dist) << "";
			cout << "How many scores " << Names[num - 1] << " should get?";
			cout << endl << setw(dist) << "";
			while (!(cin >> sc) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << endl << setw(dist) << "";
				cout << "NO!!! Just numbers OK?" << endl << setw(dist) << "";
			}
		}

	}
	return 0;
}