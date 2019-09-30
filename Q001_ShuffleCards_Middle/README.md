## Question
### 1. Implement `ShuffleCards` function to shuffle cards perfectly. (Easy)
* A perfect shuffle means cards are **totally different** every time you start the program.
* Do NOT change other functions.
* Do NOT use STL(like std::shuffle, std::random_shuffle, etc).
### 2. The original design of `Card` class  is bad, try to improve it.
* Do NOT try to delete or overwrite the methods, only tweaks are allowed.

## Source code:
```cpp
#include <iostream>

class Card
{
public:
	Card() {};
	~Card() {};

	void SetCard(char* cardName)
	{
		Name = (char*)malloc(sizeof(cardName));
		Name = cardName;
	}

	const char* GetCardName()
	{
		return Name;
	}

private:
	char* Name;
};

char deck[][52] = { "AC", "AD", "AH", "AS", "2C", "2D", "2H", "2S", "3C", "3D", "3H", "3S",
"4C", "4D", "4H", "4S","5C", "5D", "5H", "5S", "6C", "6D", "6H", "6S", "7C", "7D", "7H", "7S",
"8C", "8D", "8H", "8S", "9C", "9D", "9H", "9S", "TC", "TD", "TH", "TS", "JC", "JD", "JH", "JS",
"QC", "QD", "QH", "QS", "KC", "KD", "KH", "KS"};

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
	// TODO: Implement ShuffleCards function.
}
```

---

## Thinking
### 1. Implement `ShuffleCards()`
We need a perfect shuffle, so we cannot just use `std::rand()`. Because `std::rand()` is just a *fake* random. It is a very complicated algorithm that returns a so-called random number. Every time we start a new program, the random number would be the same since the algorithm is the same. So, we need to initialize random number generator by using `std::srand()`  
In order to generate random-like numbers, `srand()` is usually initialized to some distinctive runtime value, like the value returned by function `time()` (declared in header `<ctime>`). This is distinctive enough for most trivial randomization needs.  
This is the only thing that might be new in this question. The things left are very easy. We iterate the `Card` array, get a random index, then swap these two indices.

### 2. Fixing memory issues.
Go through source code, we have a class called `Card`. In `Card` class, there's a method called `SetCard()`. We allocate memory for `Name`. However, we didn't `free()` the memory we allocated. Where should we free the memory? Of course, in the destructor. Because we want to free the memory after we are done using it. So in `~Card()`, we `free(Name)`.

Still in the `SetCard()` method, we allocate memory for `Name`. Then, what we want is to assign the `cardName` string to `Name` string. However, `Name = cardName` here means we let `Name` point to where `cardName` pointing at. Although we got what we want, there's no pointer pointing the memory we just allocated! That caused **memory leak**. The correct way is copying the memory by using `memcpy()`.

In `main()` function, we initialized 2 Card arrays, and then, here is the trick part. We iterate the `sortedCard` array, and called method `SetCard()`. Then instead of calling `SetCard()` for `shuffledCards` array, we assign `sortedCards` to `shuffledCards`.  
It seems ok. However, it is not. Because we don't have a **assignment operator** (Not *copy constructor* [<sup>1</sup>](#1)) for `Card` class. So the complier will generate a default one for us. Using default assignment operator will result in **shallow copy**, which means **the object and the copied object will point to the same memory location**. So what's wrong here?  
After reaching the end of the program (at then end of `main()` function), `sortedCards` and `shuffledCards` will be killed. First, `sortedCards` gets killed. The destructor of `Card` will be called, and then the memory we allocated will be freed. Everything seems good. Then, `shuffledCards` gets killed. Same thing, the destructor of `Card` gets to called. However, the memory we allocated has already been freed, which will cause *undefined behavior*.  
So we need to create a **assignment operator** for class `Card`.
```cpp
Card& Card::operator=(const Card& c)
{
	SetCard(c.Name);
	return *this;
} 
```
---
<a class="anchor" id="1"></a> Copy constructor is called when a new object is created from an existing object, as a copy of the existing object. And assignment operator is called when an already initialized object is assigned a new value from another existing object.