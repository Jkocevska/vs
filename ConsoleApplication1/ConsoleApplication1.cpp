// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Klient
{
private:
	string ime;
	int id;
	int balance;
	bool postoi;
public:
	Klient() { postoi = false; };

	void kreirajKlient(string imeKlient, int idKlient, int startBalance)
	{
		if (postoi)
		{
			cout << "vekje postoi klient";
			return;
		}
		this->ime = imeKlient;
		this->id = idKlient;
		if (startBalance > 10000)
		{
			cout << "Sakate da vnesete klient so suma pogolema od 10.000 denari"
				<< endl << "Vnesi klient so pocetna suma od " << startBalance
				<< " Y/N?" << endl;
			char c;
			cin >> c;
			if (c != 'y' || c != 'Y')
			{
				cout << "Kreiran e klient so balans od 0 denari." << endl;
				balance = 0;
				return;
			}
			else balance = startBalance;
		}
	}

	void addMoney(int sum)
	{
		if(this == NULL)
		{
			cout << "ne postoi klient";
			return;
		}
		balance += sum;
		cout << "Dodadeno e: " << sum << " denari.\n";
	}



	int getBalance() const
	{
		return balance;
	}
};

class Shalter
{
private:
	string ime;
	int id;
	Klient* klient;

public:
	Shalter(string _ime, int _id)
	{
		this->id = _id;
		this->ime = _ime;
	}

	void addKlient(string ime, int id, int balance)
	{
		klient = new Klient();
		klient->kreirajKlient(ime, id, balance);
	}

	void uplataa(int sum)
	{
		klient->addMoney(sum);
	}
};

int main()
{
	string imeRabotnik;
	int idRabotnik;
	/*int* intptr;
	intptr = &idRabotnik;*/

	cout << "Rabotnik: ";
	cin >> imeRabotnik;
	cout << "ID: ";
	cin >> idRabotnik;

	Shalter shalter(imeRabotnik, idRabotnik);

	while (true)
	{
		cout << "1. Vnesi klient\t" << "2. Dodadi pari\t" << endl;
		int n;
		cin >> n;
		string imeKlient;
		int idKlinent;
		int pocetnaSmetka;
		switch (n)
		{
		case 1:
			cout << "Ime: ";
			cin >> imeKlient;
			cout << "ID: ";
			cin >> idKlinent;
			cout << "Pocetna smetka: ";
			cin >> pocetnaSmetka;
			shalter.addKlient(imeKlient, idKlinent, pocetnaSmetka);
			break;
		case 2:
			cin >> n;
			shalter.uplataa(n);
			break;
		default:
			cout << "probaj pak";
		}
	}
	return 0;
}
