// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <windows.h>
using namespace std;

string EnterEnglishWord();
string EnterRusWord();
void ShowTheVocabulary(map<string, string>);

int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	map<string, string> Vocabulary;
	int choice = 0;
	do
	{
		cout << "Menu: " << endl;
		cout << "1 - Add the word" << endl;
		cout << "2 - Edit the word" << endl;
		cout << "3 - Delete the word by word" << endl;
		cout << "4 - Delete the word by number" << endl;
		cout << "5 - Show the vocabulary" << endl;
		cout << "6 - Find the word" << endl;
		cout << "Your choice --> ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			system("cls");
			Vocabulary.insert(pair<string, string>(EnterRusWord(), EnterEnglishWord()));
			break;
		}
		case 2:
		{
			system("cls");
			int edit_choice = 0;
			int number = 1;
			cout << "Enter the number of word you want to edit --> ";
			int number_of_word = 0;
			cin >> number_of_word;
			cin.ignore();

			cout << "Choose the word you want to edit" << endl;
			cout << "1 - English word" << endl;
			cout << "2 - Русское слово" << endl;
			cout << "Your choice --> ";
			cin >> edit_choice;
			cin.ignore();
			switch (edit_choice)
			{
			case 1:
			{
				for (auto i = Vocabulary.begin(); i != Vocabulary.end(); ++i)
				{
					if (number_of_word == number)
					{
						i->second = EnterEnglishWord();
					}
					number++;
				}
				break;
			}
			case 2:
			{
				string word;
				for (auto i = Vocabulary.begin(); i != Vocabulary.end(); ++i)
				{
					if (number_of_word == number)
					{
						word = i->second;
						Vocabulary.erase(i->first);
						break;
					}
					number++;
				}
				Vocabulary.insert(pair<string, string>(EnterRusWord(), word));
				break;
			}
			}
		}
		case 3:
		{
			system("cls");
			cout << "Enter the word you want to delete -->";
			string str;
			getline(cin, str);
			for (auto i = Vocabulary.begin(); i != Vocabulary.end(); ++i)
			{
				if (i->first == str || i->second == str)
				{
					Vocabulary.erase(i->first);
					break;
				}
			}
			cout << "The word was deleted" << endl;
			break;
		}
		case 4:
		{
			system("cls");
			int number = 1;
			cout << "Enter the number of word you want to delete --> ";
			int number_of_word = 0;
			cin >> number_of_word;
			cin.ignore();
			for (auto i = Vocabulary.begin(); i != Vocabulary.end(); ++i)
			{
				if (number_of_word == number)
				{
					Vocabulary.erase(i->first);
					break;
				}
				number++;
			}
			cout << "The word was deleted" << endl;
			break;
		}
		case 5:
		{
			system("cls");
			ShowTheVocabulary(Vocabulary);
			break;
		}
		case 6:
		{
			cout << "Lakad Matataaag!" << endl;
			choice = 0;
		}
		}
	} while (choice != 0);
	return 0;
}

string EnterEnglishWord()
{
	string Word;
	cout << "Input the english word --> ";
	getline(cin, Word);
	cout << "The english word was added" << endl;
	return Word;
}

string EnterRusWord()
{
	string Word;
	cout << "Введите перевод слова --> ";
	getline(cin, Word);
	cout << "Перевод слова добавлен" << endl;
	return Word;
}

void ShowTheVocabulary(map<string, string> Vocabulary)
{
	cout << "VOCABULARY:" << endl;
	for (auto i = Vocabulary.begin(); i != Vocabulary.end(); ++i)
	{
		cout << "Рус: " << i->first << " Eng:" << i->second << endl;
	}
}
