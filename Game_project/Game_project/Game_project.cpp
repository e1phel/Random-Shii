#include<iostream>
#include<string>
#include <cstdlib>
#include<conio.h>
using namespace std;

//variables
string cards_sym[4] = { "  d","  h","  s","  c" };
string alpha[5] = { "(a)","(b)","(c)","(d)","(e)" };
int cards_no[5] = { 1,2,3,4,5 };
string card_fam[4] = { "King","Queen","Jester","Knight" };
string mimic_fam[4] = { "knight","jester","king","queen" };
string real_fam[4];
string fake_fam[4];
int mimic_no[5] = { 5,2,1,2,4 };
int fake_no[5];
int real_no[5];
string cards[5];
string real_cards[5];
string ins_sym[5];
int ins_no[5];
string ins_fam[5];
char c1, c2, c3;
int score = 0;
int j = 0;
int plays = 5;
int target = 200;
char disc;
char dsc[2];
int discards=3;
int debuff;
int ins_score;

void mainmenu()
{
	int on = 0;;
	char input;
	
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t\tSYNC";
		cout << "\n\t\t   Choose an Option";
		if (on == 0 )
		{
			cout << "\n\t\t     >>>PLAY<<<";
			cout << "\n\t\t\tRules";
			cout << "\n\t\t\tQuit";
		
		}
		else if(on==1)
		{
			cout << "\n\t\t\tPlay";
			cout << "\n\t\t     >>>RULES<<<";
			cout << "\n\t\t\tQuit";
		
		}
		else if (on == 2 )
		{
			cout << "\n\t\t\tPlay";
			cout << "\n\t\t\tRules";
			cout << "\n\t\t     >>>QUIT<<<";
		}
		input = _getch();
		if (input == 'w'|| input == 'W')
		{
			on--;
			if (on < 0)
			{
				on = 2;
			}
		}
		else if (input == 's'||input == 'S')
		{
			on++;
			if (on > 2)
			{
				on = 0;
			}
		}
		else if (input == 's' || input == 'S')
		{
			on = 2;
		}
		else if (input == '\r')
		{
			if (on == 2)
			{
				exit(0);
			}
			else if(on==0)
				break;
			else if (on == 1)
			{
				system("cls");
				cout << "\n\n\t\t\t\t-----RULES-----";
				cout << "\n\n\n\tA).Same Number";
				cout << "\n\n\n\tB).Same Symbol";
				cout << "\n\n\n\tC).Same Family";
				cout << "\n\n\n\tD).Descending Order";
				_getch();
			
			}
		}

	}
	system("cls");
}
void card_spawn()
{
	for (int i = 0; i < 5; i++)
	{
		int f = rand() % 4;
		int n = rand() % 5;
		int fam = rand() % 4;
		debuff = rand() % 4;
		int mimic = rand() % 8;
		if (mimic == 0)
		{
			real_fam[fam] = card_fam[fam];
			fake_fam[fam] = mimic_fam[fam];
			real_no[n] = cards_no[n];
			fake_no[n] = mimic_no[n];
			cards[i] = fake_fam[fam] + cards_sym[f] + to_string(fake_no[n]);
		}
		else
		{
			real_fam[fam] = card_fam[fam];
			real_no[n] = cards_no[n];
			cards[i] = card_fam[fam] + cards_sym[f] + to_string(cards_no[n]);
		}
		ins_sym[i] = cards_sym[f];
		ins_no[i] = cards_no[n];
		ins_fam[i] = card_fam[fam];
		real_cards[i] = real_fam[fam] + cards_sym[f] + to_string(real_no[n]);
		cout <<alpha[i] <<cards[i] << "\t";
		
	}
}
void discard()
{
	
		if (disc == 'y')
		{

			cout << "\n Choose Cards to Discard  ";
			cin >> dsc[0] >> dsc[1];
			int inx;
			string cards_new[2];
			srand(time(0));
			cout << "\n New cards are : ";
			for (int i = 0; i < 2; i++)
			{
				inx = dsc[i] - 'a';
				int f = rand() % 4;
				int n = rand() % 5;
				int fam = rand() % 4;
				cards_new[i] = card_fam[fam] + cards_sym[f] + to_string(cards_no[n]);
				ins_sym[inx] = cards_sym[f];
				ins_no[inx] = cards_no[n];
				ins_fam[inx] = card_fam[fam];
				cards[inx] = cards_new[i];

			}
			for (int i = 0; i < 5; i++)
			{
				cout << "\t" << cards[i];
			}
			discards--;
		}
		
	
}
void play()
{
	cout << "\n Choose your Cards:  ";
	cin >> c1 >> c2 >> c3;
	int inx1 = c1 - 'a';
	int inx2 = c2 - 'a';
	int inx3 = c3 - 'a';
	cout << "\n You Placed : " << "\t" << real_cards[inx1] << "\t" << real_cards[inx2] << "\t" << real_cards[inx3];
	if ((ins_sym[inx1] == ins_sym[inx2]) && (ins_sym[inx2] == ins_sym[inx3]))
	{
		int sym = 11;
		ins_score = ((sym + sym + sym) * 3);
		if (card_fam[debuff] == ins_fam[inx1] || (card_fam[debuff] == ins_fam[inx2]) || (card_fam[debuff] == ins_fam[inx3]))
		{
			ins_score = ins_score / 2;
		}
		score += ins_score;
		cout << "\nYour score is : " << "+" << score ;
	}
	else if ((ins_no[inx1] == ins_no[inx2]) && (ins_no[inx2] == ins_no[inx3]))
	{
		ins_score = ((ins_no[inx1] + ins_no[inx2] + ins_no[inx3]) * 3);
		if (card_fam[debuff] == ins_fam[inx1] || (card_fam[debuff] == ins_fam[inx2]) || (card_fam[debuff] == ins_fam[inx3]))
		{
			ins_score = ins_score / 2;
		}
		score += ins_score; 
		cout << "\nYour score is :  " << "+" << score ;
	}
	else if ((ins_no[inx1] == ins_no[inx2]+1) && (ins_no[inx2] == ins_no[inx3]+1))
	{
		ins_score = (((ins_no[inx1] + ins_no[inx2] + ins_no[inx3]) * 3) * 2);
		if (card_fam[debuff] == ins_fam[inx1] || (card_fam[debuff] == ins_fam[inx2]) || (card_fam[debuff] == ins_fam[inx3]))
		{
			ins_score = ins_score / 2;
		}
		score += ins_score;
		cout << "\nYour score is :  " << "+" << score;

	}
	else if ((ins_fam[inx1] == ins_fam[inx2]) && (ins_fam[inx2] == ins_fam[inx3]))
	{
		int fam_po = 11, no;
		no = inx1 + inx2 + inx3;
		ins_score = (((fam_po * 3) + no) / 3);
		if ((card_fam[debuff] == ins_fam[inx1]) || (card_fam[debuff] == ins_fam[inx2]) || (card_fam[debuff] == ins_fam[inx3]))
		{
			ins_score = ins_score / 2;
		}
		score += ins_score;
		cout << "\nYour score is: + " << score ;
	}
	else
	{
		ins_score = 3;
		if (card_fam[debuff] == ins_fam[inx1] || (card_fam[debuff] == ins_fam[inx2]) || (card_fam[debuff] == ins_fam[inx3]))
		{
			ins_score = ins_score / 2;
		}
		score += ins_score;
		cout << "\n Your score is:  " << score ;
	}
}
int main()
{
	
	mainmenu();
	while ((score < target) && (plays > 0))
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tTarget Score is :  " << target;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tNo of plays left :  " << plays;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tNo of Discards left : " <<discards;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tScore left to win:  " << target - score;
		cout << "\n\n Your cards are : " << "\t";
		srand(time(0));
		card_spawn();
		cout << "\n Your Score is: " << score;
		cout << "\n Debuffed Family is :  " << card_fam[debuff];
		if (discards > 0)
		{
			cout << "\n do you want to discard?(y.n)  ";
			cin >> disc;
			discard();
		}
		play();
		j++;
		plays--;
	}
	if (plays <= 0)
	{
		cout << "\n\n YOU LOSE !";
	}
	else
	{
		cout << "\n You Win";
	}
	return 0;


}

