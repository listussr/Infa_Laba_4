#pragma once

#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<conio.h>

void background_choosing()
{
	std::cout << "What color of background do you want to have?" << std::endl;
	std::cout << "light green -> A" << std::endl
		<< "light blue -> B" << std::endl
		<< "light red -> C" << std::endl
		<< "light purple -> D" << std::endl
		<< "light yellow -> E" << std::endl
		<< "white -> F" << std::endl;
	std::string a;
	std::cin >> a;
	while (a != "A" && a != "B" && a != "C" && a != "D" && a != "E" && a != "F")
	{
		getline(std::cin, a);
	}
	if (a == "A") system("Color A0");
	if (a == "B") system("Color B0");
	if (a == "C") system("Color C0");
	if (a == "D") system("Color D0");
	if (a == "E") system("Color E0");
	if (a == "F") system("Color F0");
}

void color_choosing()
{
	std::cout << "What color of console do you want to have?" << std::endl;
	std::cout << "black -> 1" << std::endl
		<< "blue -> 2" << std::endl
		<< "green -> 3" << std::endl
		<< "red -> 4" << std::endl
		<< "purple -> 5" << std::endl
		<< "yellow -> 6" << std::endl
		<< "white -> 7" << std::endl
		<< "gray -> 8" << std::endl
		<< "light blue -> 9" << std::endl;
	std::string a;
	std::cin >> a;
	while (a != "1" && a != "2" && a != "3" && a != "4" && a != "5" && a != "6" && a != "7" && a != "8" && a != "9")
	{
		getline(std::cin, a);
	}
	if (a == "1") system("Color 1");
	if (a == "2") system("Color 2");
	if (a == "3") system("Color 3");
	if (a == "4") system("Color 4");
	if (a == "5") system("Color 5");
	if (a == "6") system("Color 6");
	if (a == "7") system("Color 7");
	if (a == "8") system("Color 8");
	if (a == "9") system("Color 9");
}

void color_background_choosing()
{
	std::cout << "What color of background do you want to have?" << std::endl;
	std::cout << "light green -> A" << std::endl
		<< "light blue -> B" << std::endl
		<< "light red -> C" << std::endl
		<< "light purple -> D" << std::endl
		<< "light yellow -> E" << std::endl
		<< "white -> F" << std::endl;
	std::string a;
	std::cin >> a;
	while (a != "A" && a != "B" && a != "C" && a != "D" && a != "E" && a != "F")
	{
		getline(std::cin, a);
	}
	if (a == "A") {
		std::cout << "What color of console do you want to have?" << std::endl;
		std::cout << "black -> 1" << std::endl
			<< "blue -> 2" << std::endl
			<< "green -> 3" << std::endl
			<< "red -> 4" << std::endl
			<< "purple -> 5" << std::endl
			<< "yellow -> 6" << std::endl
			<< "white -> 7" << std::endl
			<< "gray -> 8" << std::endl
			<< "light blue -> 9" << std::endl;
		std::string b;
		std::cin >> b;
		while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "6" && b != "7" && b != "8" && b != "9")
		{
			getline(std::cin, a);
		}
		if (b == "1") system("Color A1");
		if (b == "2") system("Color A2");
		if (b == "3") system("Color A3");
		if (b == "4") system("Color A4");
		if (b == "5") system("Color A5");
		if (b == "6") system("Color A6");
		if (b == "7") system("Color A7");
		if (b == "8") system("Color A8");
		if (b == "9") system("Color A9");
	}
	if (a == "B") {
		std::cout << "What color of console do you want to have?" << std::endl;
		std::cout << "black -> 1" << std::endl
			<< "blue -> 2" << std::endl
			<< "green -> 3" << std::endl
			<< "red -> 4" << std::endl
			<< "purple -> 5" << std::endl
			<< "yellow -> 6" << std::endl
			<< "white -> 7" << std::endl
			<< "gray -> 8" << std::endl
			<< "light blue -> 9" << std::endl;
		std::string b;
		std::cin >> b;
		while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "6" && b != "7" && b != "8" && b != "9")
		{
			getline(std::cin, a);
		}
		if (b == "1") system("Color B1");
		if (b == "2") system("Color B2");
		if (b == "3") system("Color B3");
		if (b == "4") system("Color B4");
		if (b == "5") system("Color B5");
		if (b == "6") system("Color B6");
		if (b == "7") system("Color B7");
		if (b == "8") system("Color B8");
		if (b == "9") system("Color B9");
	}
	if (a == "C") {
		std::cout << "What color of console do you want to have?" << std::endl;
		std::cout << "black -> 1" << std::endl
			<< "blue -> 2" << std::endl
			<< "green -> 3" << std::endl
			<< "red -> 4" << std::endl
			<< "purple -> 5" << std::endl
			<< "yellow -> 6" << std::endl
			<< "white -> 7" << std::endl
			<< "gray -> 8" << std::endl
			<< "light blue -> 9" << std::endl;
		std::string b;
		std::cin >> b;
		while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "6" && b != "7" && b != "8" && b != "9")
		{
			getline(std::cin, a);
		}
		if (b == "1") system("Color C1");
		if (b == "2") system("Color C2");
		if (b == "3") system("Color C3");
		if (b == "4") system("Color C4");
		if (b == "5") system("Color C5");
		if (b == "6") system("Color C6");
		if (b == "7") system("Color C7");
		if (b == "8") system("Color C8");
		if (b == "9") system("Color C9");
	}
	if (a == "D") {
		std::cout << "What color of console do you want to have?" << std::endl;
		std::cout << "black -> 1" << std::endl
			<< "blue -> 2" << std::endl
			<< "green -> 3" << std::endl
			<< "red -> 4" << std::endl
			<< "purple -> 5" << std::endl
			<< "yellow -> 6" << std::endl
			<< "white -> 7" << std::endl
			<< "gray -> 8" << std::endl
			<< "light blue -> 9" << std::endl;
		std::string b;
		std::cin >> b;
		while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "6" && b != "7" && b != "8" && b != "9")
		{
			getline(std::cin, a);
		}
		if (b == "1") system("Color D1");
		if (b == "2") system("Color D2");
		if (b == "3") system("Color D3");
		if (b == "4") system("Color D4");
		if (b == "5") system("Color D5");
		if (b == "6") system("Color D6");
		if (b == "7") system("Color D7");
		if (b == "8") system("Color D8");
		if (b == "9") system("Color D9");
	}
	if (a == "E") {
		std::cout << "What color of console do you want to have?" << std::endl;
		std::cout << "black -> 1" << std::endl
			<< "blue -> 2" << std::endl
			<< "green -> 3" << std::endl
			<< "red -> 4" << std::endl
			<< "purple -> 5" << std::endl
			<< "yellow -> 6" << std::endl
			<< "white -> 7" << std::endl
			<< "gray -> 8" << std::endl
			<< "light blue -> 9" << std::endl;
		std::string b;
		std::cin >> b;
		while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "6" && b != "7" && b != "8" && b != "9")
		{
			getline(std::cin, a);
		}
		if (b == "1") system("Color E1");
		if (b == "2") system("Color E2");
		if (b == "3") system("Color E3");
		if (b == "4") system("Color E4");
		if (b == "5") system("Color E5");
		if (b == "6") system("Color E6");
		if (b == "7") system("Color E7");
		if (b == "8") system("Color E8");
		if (b == "9") system("Color E9");
	}
	if (a == "F") {
		std::cout << "What color of console do you want to have?" << std::endl;
		std::cout << "black -> 1" << std::endl
			<< "blue -> 2" << std::endl
			<< "green -> 3" << std::endl
			<< "red -> 4" << std::endl
			<< "purple -> 5" << std::endl
			<< "yellow -> 6" << std::endl
			<< "white -> 7" << std::endl
			<< "gray -> 8" << std::endl
			<< "light blue -> 9" << std::endl;
		std::string b;
		std::cin >> b;
		while (b != "1" && b != "2" && b != "3" && b != "4" && b != "5" && b != "6" && b != "7" && b != "8" && b != "9")
		{
			getline(std::cin, a);
		}
		if (b == "1") system("Color F1");
		if (b == "2") system("Color F2");
		if (b == "3") system("Color F3");
		if (b == "4") system("Color F4");
		if (b == "5") system("Color F5");
		if (b == "6") system("Color F6");
		if (b == "7") system("Color F7");
		if (b == "8") system("Color F8");
		if (b == "9") system("Color F9");
	}
}

void design_of_console()
{
	std::string a;
	std::cout << "If you want to change only text - press 'w' or 'W'" << std::endl;
	std::cout << "If you want to change only background - press 'b' or 'B'" << std::endl;
	std::cout << "If you want to change text and background - press 'a' or 'A'" << std::endl;
	getline(std::cin, a);
	while (a != "w" && a != "W" && a != "b" && a != "B" && a != "a" && a != "A")
	{
		getline(std::cin, a);
	}
	if (a == "w" || a == "W") color_choosing();
	else if (a == "b" || a == "B") background_choosing();
	else color_background_choosing();
}

