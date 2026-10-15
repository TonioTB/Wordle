#include <iostream>

using namespace std;

#define GREEN "\033[32m"
#define DEFAULT "\033[0m"






int main()
{
	srand(time(NULL));
	const char* wordList[] = { "CHAUD", "KAYAK", "SOURD", "TABLE" };
	int wordListSize = sizeof(wordList) / sizeof(wordList[0]);
	int nbBannedWords = 0;

	
	int chaseWordIndex = rand() % (wordListSize - nbBannedWords) + nbBannedWords;
	const char* chaseWord = wordList[chaseWordIndex];
	for (int i = chaseWordIndex - 1; i > -1; i--)
	{
		wordList[i + 1] = wordList[i];
	}

	wordList[0] = chaseWord;
	cout << chaseWord << endl;
	nbBannedWords++;
	

	char guess[] = "XXXXX";

	while (guess[0] != chaseWord[0])
	{
		cin >> guess;
	}
	


	

	return 0;
}