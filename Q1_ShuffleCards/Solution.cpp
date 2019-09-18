#include <iostream>
#include <cstdlib>
#include <ctime>

class Card
{
public:
	Card() {};

	void SetCard(char* card)
	{
		Name = (char*)malloc(sizeof(card));
		//Name = card;
        memcpy(Name, card, sizeof(card));
	}

	const char* GetCardName()
	{
		return Name;
	}

	~Card() 
    {
        free(Name);  // when destrocting Cards, free the memory we allocated to pervent memory leak
    };

private:
	char* Name;
};

char* deck[52] = { "AC", "AD", "AH", "AS", "2C", "2D", "2H", "2S", "3C", "3D", "3H", "3S",
"4C", "4D", "4H", "4S","5C", "5D", "5H", "5S", "6C", "6D", "6H", "6S", "7C", "7D", "7H", "7S",
"8C", "8D", "8H", "8S", "9C", "9D", "9H", "9S", "TC", "TD", "TH", "TS", "JC", "JD", "JH", "JS",
"QC", "QD", "QH", "QS", "KC", "KD", "KH", "KS"};

void DisplayCard(Card*);
void RandomizeCard(Card*);

int main(int argc, char* argv[])
{
	Card cards[52];

	for (int i = 0; i != 52; ++i)
	{
        cards[i].SetCard(deck[i]);
	}
	
    RandomizeCard(cards);
	DisplayCard(cards);

	return 0;
}

void DisplayCard(Card* card)
{
	std::cout << "The Cards are: " << std::endl;
	for (int i = 0; i != 52; ++i)
	{
		std::cout << card[i].GetCardName() << std::endl;
	}
}

void RandomizeCard(Card* card)
{
    std::srand(std::time(NULL));
    
}
