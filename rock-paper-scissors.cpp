#include <iostream>
#include <string>

using namespace std;

// Weapon class //

class Weapon
{
private:
	int strength;
	char type;
	int modified;

public:
	Weapon()
	{
		strength = 0;
		type = '0';
		modified = 0;
	}
	void setPower (const int& pwr) { this -> strength = pwr; }
	void setType (const char& t) { this -> type = t; }
	void setModified (const int& mod) { this -> modified = mod; }
	int return_strength() const { return strength; }
	char return_type() const { return type; }
	int return_modified() const { return modified; }
};

// Rock //

class Rock : public Weapon
{
public:
	Rock()
	{
		int rock;
		cout << "Rock's strength? ";
		cin >> rock;
		setPower(rock);
		setType('r');
		setModified(rock);
	}
	bool battle (Weapon& x);
};

bool Rock::battle(Weapon& x)
{
	if (x.return_type() == 's')
	{
		setModified(return_strength()*2);
		x.setModified(x.return_strength()/2);

		if (return_modified() <= x.return_modified())
			return 0;

		else
			return 1;
	}

	else if (x.return_type() == 'p')
	{
		setModified(return_strength()/2);
		x.setModified(x.return_modified()*2);

		if (return_modified() <= x.return_modified())
			return 0;

		else
			return 1;
	}
}

// Paper //

class Paper : public Weapon
{
public:
	Paper()
	{
		int paper;
		cout << "Paper's strength? ";
		cin >> paper;
		setPower(paper);
		setType('p');
		setModified(paper);
	}
	bool battle (Weapon& x);
};

bool Paper::battle(Weapon& x)
{
	if (x.return_type() == 'r')
	{
		setModified(return_strength()*2);
		x.setModified(x.return_strength()/2);

		if (return_modified() <= x.return_modified())
			return 0;

		else
			return 1;
	}

	else if (x.return_type() == 's')
	{
		setModified(return_strength()/2);
		x.setModified(x.return_modified()*2);

		if (return_modified() <= x.return_modified())
			return 0;

		else
			return 1;
	}
}

// Scissor //

class Scissor : public Weapon
{
public:
	Scissor()
	{
		int scissor;
		cout << "Scissor's strength? ";
		cin >> scissor;
		setPower(scissor);
		setType('s');
		setModified(scissor);
	}
	bool battle (Weapon& x);
};

bool Scissor::battle(Weapon& x)
{
	if (x.return_type() == 'p')
	{
		setModified(return_strength()*2);
		x.setModified(x.return_strength()/2);

		if (return_modified() <= x.return_modified())
			return 0;

		else
			return 1;
	}

	else if (x.return_type() == 'r')
	{
		setModified(return_strength()/2);
		x.setModified(x.return_modified()*2);

		if (return_modified() <= x.return_modified())
			return 0;

		else
			return 1;
	}
}

// Main function //

int main()
{
	Rock r;
	Paper p;
	Scissor s;

	cout << "Battle 1 - Rock v/s Paper: \n\t" << (r.battle(p) ? "Rock" : "Paper") << " wins!\n\n";
	cout << "Battle 2 - Paper v/s Scissors: \n\t" << (p.battle(s) ? "Paper" : "Scissors") << " wins!\n\n";
    cout << "Battle 3 - Scissors v/s Rock: \n\t" << (s.battle(r) ? "Scissors" : "Rock") << " wins!\n\n";

	system("Pause");
	return 0;
}
