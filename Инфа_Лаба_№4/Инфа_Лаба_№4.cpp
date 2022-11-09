#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<conio.h>
#define EOL '\n'
using namespace std;

bool continue_check()
{
	bool flag = true;
	char symbol;
	cout << endl << "Do you want to continue?" << endl;
	cout << "If you want - press q or Q" << endl;
	cout << "If you want to quit - press x or X" << endl;
	while (!(cin >> symbol) || flag)
	{
		cin.clear();
		if ((symbol == 'X' || symbol == 'x') && (cin.peek() == EOL)) {
			flag = false;
			return false;
		}
		else if ((symbol == 'Q' || symbol == 'q') && (cin.peek() == EOL)) {
			flag = false;
			return true;
		}
		else {
			flag = true;
		}
		while (cin.get() != EOL);
		cout << "Do you want to continue? --> Q / X / q / x" << endl;
	}
}

vector<vector<char>> massive()
{
	char symbol;
	int i = 0;
	int j = 0;
	vector <vector<char>> input;
	input.push_back(vector<char>());
	ifstream in("words_game.txt");
	if (!in.is_open())
		cout << "This file cant be open!\n";
	else
	{
		while ((symbol = in.get()) != EOF)
		{
			if (symbol != EOL)
				input[i].push_back(symbol);
			else {
				input.push_back(vector<char>());
				++i;
			}
		}
		in.close();
	}
	cout << endl;
	return input;
}

vector<vector<char>> list_of_words = massive();

bool begin()
{
	string answer;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "You have entered a game named 'Words' " << endl << endl;;
	cout << "If you want to be first player print 'me' " << endl;
	cout << "If you want to be second player print 'bot' " << endl;
	cout << "Answer is ->" << '\t';
	cin >> answer;
	cout << "________________________________________________________________________________________________________________________" << endl;
	if (answer == "bot")
		return true;
	if (answer == "me")
		return false;
	while (answer != "me" && answer != "bot")
	{
		cout << "Incorrect input - try again: " << endl;
		cin >> answer;
	}
}

bool checking_word(vector<char> answer, vector<vector<char>> vecn)
{
	for (int i = 0; i < vecn.size(); i++)
	{
		if (answer == vecn[i])
			return true;
	}
	return false;
}

vector<char> entering_first_word()
{
	string a;
	cout << "You are first player" << endl;
	cout << "Enter word from text document" << endl;
	cin >> a;
	cout << "________________________________________________________________________________________________________________________" << endl;
	vector<char> answer;
	for (int i = 0; i < a.size(); i++)
	{
		answer.push_back(a[i]);
	}
	if (!checking_word(answer, list_of_words))
	{
		cout << "Incorrect input - you lose" << endl;
		entering_first_word();
	}
	return answer;
}

vector<char> entering_word(vector<vector<char>>& vecn)
{
	string a;
	cout << "Enter next word from a text document" << endl;
	cin >> a;
	cout << "________________________________________________________________________________________________________________________" << endl;
	vector<char> answer;
	for (int i = 0; i < a.size(); i++)
	{
		answer.push_back(a[i]);
	}
	if (!checking_word(answer, vecn))
	{
		cout << "Incorrect input - try again" << endl;
	}
	return answer;
}

vector<char> iteration_bot()
{
	vector<char> answer;
	cout << "Bot says: " << endl;
	for (int i = 0; i < list_of_words[0].size(); i++)
	{
		answer.push_back(list_of_words[0][i]);
		cout << answer[i];
	}
	cout << endl << "________________________________________________________________________________________________________________________" << endl; ;
	return answer;
}

int iteration_me(vector<char>& vec, vector<vector<char>>& vecn)
{
	vector<vector<char>> list;
	vector<char> answer;
	int p = vec.size();
	char symbol = vec[p - 1];
	for (int i = 0; i < vecn.size(); i++){
		char symbol_next = vecn[i][0];
		if (symbol == symbol_next){
			int h = i;
			int j = vecn[i].size();
			cout << "Next word is: " << endl;
			for (int j = 0; j < vecn[i].size(); j++)
				cout << vecn[i][j];
			cout << endl;
			for (int i = 0; i < h - 1; i++) {
				list.push_back(vecn[i]);
			}
			for (int i = h + 1; i < vecn.size(); i++) {
				list.push_back(vecn[i]);
			}
			answer = vecn[i];
			cout << "________________________________________________________________________________________________________________________" << endl;
			break;
		}
	}
	int l = answer.size();
	char last_letter = answer[l - 1];
	vector<char> me = entering_word(list);
	int f = me.size();
	char first_letter = me[0];
	if (first_letter != last_letter){
		cout << "Your word can't be accepted - you lose" << endl;
		return 0;
	}
	iteration_me(me, list);
}

void post_iteration_bot(vector<char>& bot_answer, vector<vector<char>>& vec)
{
	vector<vector<char>> list;
	int l = bot_answer.size();
	char last_letter = bot_answer[l - 1];
	vector<char> me = entering_word(vec);
	for (int i = 0; i < vec.size(); i++) {
		if (me == vec[i]){
			int h = i;
			for (int i = 0; i < h - 1; i++) {
				list.push_back(vec[i]);
			}
			for (int i = h + 1; i < vec.size(); i++) {
				list.push_back(vec[i]);
			}
		}
	}
	int f = me.size();
	char first_letter = me[0];
	if (first_letter != last_letter)
	{
		cout << "Your word can't be accepted - you lose" << endl;
		return;
	}
	else iteration_me(me, list);
}

void game()
{
	if (!begin())
	{
		vector<char> my_answer = entering_first_word();
		iteration_me(my_answer, list_of_words);
	}
	else
	{
		vector<char> bot_answer = iteration_bot();
		post_iteration_bot(bot_answer, list_of_words);
	}
}

int main()
{
	bool iteration = true;
	while (iteration)
	{
		game();
		iteration = continue_check();
		system("cls");
	}
}