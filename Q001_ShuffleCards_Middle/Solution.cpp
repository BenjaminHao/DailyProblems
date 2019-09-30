#include <iostream>
#include <cstdlib>
#include <ctime>

class Card
{
public:
	Card() {};

	void SetCard(char* cardName)
	{
		Name = (char*)malloc(sizeof(cardName));
		/** Name = cardName; is not right here
		 *  What we want is copying the card name
		 *  But this means Name is pointing to where cardName pointing at
		 *  Then there's no pinters pointing to the memory we just allocted
		 *  Which caused memory leak.
		 *  memcpy is what we want here.
		 **/
		memcpy(Name, cardName, sizeof(cardName));
	}

	const char* GetCardName()
	{
		return Name;
	}

	Card& operator=(const Card& c)
	{
		SetCard(c.Name);
		return *this;
	} 

	~Card()
	{
		// when destrocting Cards, free the memory we allocated to pervent memory leak
		free(Name);
	};

private:
	char* Name;
};

char deck[][52] = { "AC", "AD", "AH", "AS", "2C", "2D", "2H", "2S", "3C", "3D", "3H", "3S",
"4C", "4D", "4H", "4S","5C", "5D", "5H", "5S", "6C", "6D", "6H", "6S", "7C", "7D", "7H", "7S",
"8C", "8D", "8H", "8S", "9C", "9D", "9H", "9S", "TC", "TD", "TH", "TS", "JC", "JD", "JH", "JS",
"QC", "QD", "QH", "QS", "KC", "KD", "KH", "KS" };

void DisplayCards(Card*);
void ShuffleCards(Card*);

// Do NOT modify main function
int main()
{
	Card sortedCards[52];
	Card shuffledCards[52];

	for (int i = 0; i < 52; ++i)
	{
		sortedCards[i].SetCard(deck[i]);
		shuffledCards[i] = sortedCards[i];

	}

	ShuffleCards(shuffledCards);
	DisplayCards(shuffledCards);

	return 0;
}

// Do NOT modify DisplayCards function
void DisplayCards(Card* card)
{
	std::cout << "The Cards are: " << std::endl;
	for (int i = 0; i < 52; ++i)
	{
		std::cout << card[i].GetCardName() << '\t';
		if ((i + 1) % 4 == 0) std::cout << '\n';
	}
	std::cout << std::endl;
}


void ShuffleCards(Card* card)
{
	// random number seed
	std::srand(std::time(0));

	// iterate entire card array
	for (int i = 0; i < 52; ++i)
	{
		// get a random index
		int r = i + (std::rand() % (52 - i));
		// swap two cards
		Card tmp = card[i];
		card[i] = card[r];
		card[r] = card[i];
	}
}