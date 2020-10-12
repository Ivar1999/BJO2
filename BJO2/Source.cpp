#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;


string arraytype[] = { " of clubs", " of diamonds", " of spades", " of hearts" };
string arraynumber[] = { "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace" };

struct cardtype
{
	int type;
	int number;
};
vector <cardtype> availablecards;
vector <cardtype> usedcards;
struct card
{
	int value;
	string display;
	cardtype type;
};
struct Hand
{
	vector <card> cards;
	int getsum() {
		int hand = 0;
		cout << "\n\n\n";
		for (int i = 0; i < cards.size(); i++)
		{
			//cout << i+1 << ". card is: " << cards.at(i).value << endl;
			cout << i +1 << ". card is: " <<cards.at(i).display << endl;
			hand += cards.at(i).value;

		}
		return hand;
	}	
};

card getrandomcard();
card getrandomcard()
{
	const int randomnumber = rand() % availablecards.size();
	//cout << "randomnumber: " << randomnumber << endl;
	//cout << "availablecards.size(): " << availablecards.size() << endl;
	usedcards.push_back(availablecards[randomnumber]);	
	card Card;
	Card.type = availablecards[randomnumber];
	availablecards.erase(availablecards.begin() + randomnumber);
	//cout << "Card.type.number: " << Card.type.number << endl;
	switch (Card.type.number)
	{
	case 9: Card.value = 10;
		break;
	case 10: Card.value = 10;
		break;
	case 11: Card.value = 10;
		break;
	case 12: Card.value = 11;
		break;
	default: Card.value = Card.type.number+2;
		break;
	}
	Card.display = arraynumber[Card.type.number] + arraytype[Card.type.type];
	

	return Card;
}
void shuffle();
void shuffle() // used cards after 1 round back into available cards
{
	for (int i = 0; i < usedcards.size(); i++)
	{
		availablecards.push_back(usedcards[i]);
	}
	usedcards.erase(usedcards.begin(), usedcards.end());
}
/*int wincon();
int wincon()
{

}*/


int main() {
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cardtype type;
			type.number = j;
			type.type = i;
			availablecards.push_back(type);
		}
	}
	//card Card = getrandomcard();
	//cout << Card.value << " " << Card.display; // value, number&type
	//cout << Card.display;
	
	int option;
	int money = 100;
	do
	{
		Hand player;
		Hand dealer;
		dealer.cards.push_back(getrandomcard());
		player.cards.push_back(getrandomcard());
		player.cards.push_back(getrandomcard());
		do
		{
			system("cls");
			cout << "Your hand is: " << player.getsum() << endl;
			cout << "Dealers card is: " << dealer.getsum() << endl;
			//cout << "hand value:" << player.getsum() << "\ncard value:" << Card.value << endl;
			//cout << Card.display << endl;
			cout << "\nhit or stand\n";
			cout << " 1       2  \n";
			cin >> option;
			if (option == 1)
			{
				system("cls");
				player.cards.push_back(getrandomcard());
			}
			
			
		} while ( option == 1 && player.getsum() < 21);// hand value < 21 || stand
		system("cls");
		cout << "Your hand is: " << player.getsum() << endl;
		dealer.cards.push_back(getrandomcard());

		if (player.getsum() > 21)
		{
			system("cls");
			cout << "Your hand is: " << player.getsum() << "\nYou went over 21." << endl;
		}
		else
		{
			do
			{
				dealer.cards.push_back(getrandomcard());

			} while (dealer.getsum() < 17);
			if (dealer.getsum() > 21)
			{
				system("cls");
				cout << "Your hand is: " << player.getsum() << endl;
				cout << "\n\n\nDealers hand is: " << dealer.getsum() << "\nDealer went over 21.\nPlayer wins." << endl;
			}
			else
			{
				system("cls");
				cout << "Your hand is: " << player.getsum() << endl;
				cout << "Dealers hand is: " << dealer.getsum() << endl;
				if (player.getsum() > dealer.getsum())
				{
					cout << "Player wins." << endl;
				}
				else if (player.getsum() == dealer.getsum())
				{
					cout << "It's a draw." << endl;
				}
				else
				{
					cout << "Dealer wins." << endl;
				}
			}


		}
		

		// if hand > dealer bet x2 -> money
		shuffle();
		system("pause");
		system("cls");

		cout << "test\n";
	} while (true); // money > 0
	

	return 0;
}