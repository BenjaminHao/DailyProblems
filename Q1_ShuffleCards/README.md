### 1. Create a new Cards and make sure it has randomized value
### 2. The original code has some issues, try to fix them

```c++
#include <iostream>

class Cards
{
public:
	Cards() {};
	~Cards() {};

	void SetCards(const char* card)
	{
		Name = (char*)malloc(sizeof(card));
		Name = card;
	}

	const char* GetCardName()
	{
		return Name;
	}

private:
	const char* Name;
};

const char* deck[52] = { "AC", "AD", "AH", "AS", "2C", "2D", "2H", "2S", "3C", "3D", "3H", "3S",
"4C", "4D", "4H", "4S","5C", "5D", "5H", "5S", "6C", "6D", "6H", "6S", "7C", "7D", "7H", "7S",
"8C", "8D", "8H", "8S", "9C", "9D", "9H", "9S", "TC", "TD", "TH", "TS", "JC", "JD", "JH", "JS",
"QC", "QD", "QH", "QS", "KC", "KD", "KH", "KS"};

void DisplayCard(Cards*);

int main(int argc, char* argv[])
{
	Cards originalCards[52];

	for (int i = 0; i != 52; ++i)
	{
		originalCards[i].SetCards(deck[i]);
	}
	
	DisplayCard(originalCards);

	return 0;
}

void DisplayCard(Cards* card)
{
	std::cout << "The Cards are: " << std::endl;
	for (int i = 0; i != 52; ++i)
	{
		std::cout << card[i].GetCardName() << std::endl;
	}
}
```
