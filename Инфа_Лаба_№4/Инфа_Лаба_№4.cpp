#include"Design.h"
#define EOL '\n'
using namespace std;

bool continue_check()
{
	bool flag = true;
	char symbol;
	cout << endl << "Do you want to continue?" << endl;
	cout << "If you want - press q or Q" << endl;
	cout << "If you want to quit - press x or X" << endl;
	while (!(cin >> symbol) || flag){
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

vector<vector<char>> massive(){
	char symbol;
	int i = 0;
	vector <vector<char>> input;
	input.push_back(vector<char>());
	ifstream in("words_game.txt");
	while ((symbol = in.get()) != EOF) {
		if (symbol != EOL)
			input[i].push_back(symbol);
		else {
			input.push_back(vector<char>());
			++i;
		}
	}
	in.close();
	cout << endl;
	return input;
}

vector<vector<char>> list_of_words = massive();

bool begin(){
	string answer;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "You have entered a game named 'Words' " << endl << endl;;
	cout << "If you want to be first player print 'me' " << endl;
	cout << "If you want to be second player print 'bot' " << endl;
	cout << "Answer is ->" << '\t';
	cin >> answer;
	cout << "________________________________________________________________________________________________________________________" << endl;
	if (answer == "bot")
		return false;
	if (answer == "me")
		return true;
	while (answer != "me" && answer != "bot"){
		cout << "Incorrect input - try again: " << endl;
		cin >> answer;
	}
}

bool checking_word(vector<char> answer, vector<vector<char>> vecn){
	for (int i = 0; i < vecn.size(); i++){
		if (answer == vecn[i])
			return true;
	}
	return false;
}

vector<char> entering_first_word(){
	string a;
	cout << "You are first player" << endl;
	cout << "Enter word from text document" << endl;
	cin >> a;
	cout << "________________________________________________________________________________________________________________________" << endl;
	vector<char> answer;
	for (int i = 0; i < a.size(); i++)
		answer.push_back(a[i]);
	return answer;
}

vector<vector<char>> list_of_words_me(vector<char>& vec){
	vector<vector<char>> a;
	for (int i = 0; i < list_of_words.size(); i++){
		if (vec == list_of_words[i]){
			int h = i;
			for (int i = 0; i < h - 1; i++)
				a.push_back(list_of_words[i]);
			for (int i = h + 1; i < list_of_words.size(); i++)
				a.push_back(list_of_words[i]);
		}
	}
	return a;
}

vector<char> entering_word(vector<vector<char>>& vecn){
	string a;
	cout << "You: " << endl;
	cin >> a;
	cout << "________________________________________________________________________________________________________________________" << endl;
	vector<char> answer;
	for (int i = 0; i < a.size(); i++)
		answer.push_back(a[i]);
	return answer;
}

vector<char> iteration_bot(){
	vector<char> answer;
	cout << "Bot says: " << endl;
	for (int i = 0; i < list_of_words[0].size(); i++){
		answer.push_back(list_of_words[0][i]);
		cout << answer[i];
	}
	cout << endl << "________________________________________________________________________________________________________________________" << endl; ;
	return answer;
}

vector<vector<char>> post_list_bot() {
	vector<vector<char>> a;
	for (int i = 1; i < list_of_words.size(); i++)
		a.push_back(list_of_words[i]);
	return a;
}

int iteration_me(vector<char>& vec, vector<vector<char>>& vecn){
	vector<vector<char>> list;
	vector<char> answer;
	int p = vec.size();
	char symbol = vec[p - 1];
	for (int i = 0; i < vecn.size(); i++){
		char symbol_next = vecn[i][0];
		if (symbol == symbol_next){
			int h = i;
			int j = vecn[i].size();
			cout << "Bot: " << endl;
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
	if (first_letter != last_letter || !checking_word(me, list)){
		cout << "Your word can't be accepted - you lose" << endl;
		return 0;
	}
	vector<vector<char>> list_2;
	for (int i = 0; i < list.size(); i++){
		if (me == list[i]){
			int u = i;
			for (int i = 0; i < u - 1; i++)
				list_2.push_back(list[i]);
			for (int i = u + 1; i < list.size(); i++)
				list_2.push_back(list[i]);
		}
	}
	iteration_me(me, list_2);
}

void post_iteration_bot(vector<char>& bot_answer, vector<vector<char>>& vec){
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
	if (first_letter != last_letter || !checking_word(me, vec)){
		cout << "Your word can't be accepted - you lose" << endl;
		return;
	}
	else iteration_me(me, list);
}

void game(){
	if (begin()){
		vector<char> my_answer = entering_first_word();
		if (!checking_word(my_answer, list_of_words)) {
			cout << "Your word is incorrect - you lose" << endl;
			return;
		}
		vector<vector<char>> list_of_words_after_me = list_of_words_me(my_answer);
		iteration_me(my_answer, list_of_words_after_me);
	}
	else{
		vector<char> bot_answer = iteration_bot();
		vector<vector<char>> list_of_words_after_bot = post_list_bot();
		post_iteration_bot(bot_answer, list_of_words_after_bot);
	}
}

void start_menu()
{
	string a;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "You are in startup menu" << endl << endl;
	cout << " ---> If you want to change design of console press 'd' or 'D'" << endl << endl;
	cout << " ---> If you want to start game press q or Q " << endl << endl;
	getline(cin, a);
	while (a != "d" && a != "D" && a != "q" && a != "Q") {
		getline(cin, a);
	}
	if (a == "d" || a == "D"){
		system("cls");
		design_of_console();
		system("cls");
		start_menu();
	}
	if (a == "q" || a == "Q") return;
}

int main(){
	bool iteration = true;
	while (iteration){
		start_menu();
		system("cls");
		game();
		iteration = continue_check();
		system("cls");
	}
}
