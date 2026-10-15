#include <iostream>
#include <conio.h>

using namespace std;

#define GREEN "\033[32m"
#define DEFAULT "\033[0m"
#define BLUE "\033[36m"
#define YELLOW "\033[33m"

int AskInt(int min, int max)
{
	int answer;
	cin >> answer;
	while (answer > max || answer < min)
	{
		cout << "The value needs to be between " << min << " and " << max << " (Included). Please try again." << endl;
		cin >> answer;
	}
	return answer;
}


int main()
{
	srand(time(NULL));

	const char* wordList[] = {
	"CHAUD", "KAYAK", "SOURD", "TABLE", "ARBRE",
	"AVION", "BALLE", "BANDE", "BARBE", "BATON",
	"BIJOU", "BLANC", "BOIRE", "BORNE", "BRUIT",
	"BULLE", "CABLE", "CADRE", "CARTE", "CHAIR",
	"CHANT", "CHIEN", "CHOSE", "CIBLE", "CLAIR",
	"CLOWN", "COEUR", "COUDE", "COURS", "CRAIE",
	"CRISE", "DANSE", "DENTS", "DOIGT", "DROIT",
	"ECOLE", "ECRAN", "ELEVE", "ENFER", "ENFIN",
	"ETAGE", "FAIRE", "FERME", "FLEUR", "FLUTE",
	"FOIRE", "FORCE", "FORET", "FOULE", "FRAIS",
	"FRUIT", "FUMEE", "GARDE", "GENOU", "GLACE",
	"GOMME", "GRAND", "GRAIN", "GRAVE", "GUIDE",
	"HEROS", "HIVER", "HOTEL", "HUILE", "IMAGE",
	"JAUNE", "JEUNE", "JOUER", "JOUET", "JUSTE",
	"LAINE", "LAPIN", "LARGE", "LIBRE", "LIEUX",
	"LIGNE", "LIVRE", "LOURD", "LUTTE", "MAIRE",
	"MARDI", "MERCI", "MIXTE", "MONDE", "MOULE",
	"MUSEE", "NAGER", "NEIGE", "NOBLE", "NUAGE",
	"OCEAN", "OMBRE", "ONGLE", "ORAGE", "OUEST",
	"PAUSE", "PAIRE", "PANNE", "PARLE", "PATTE",
	"PERLE", "PETIT", "PIEDS", "PIEGE", "PLAGE",
	"PLUIE", "PLUME", "POIDS", "POINT", "POIRE",
	"PORTE", "POUCE", "POULE", "PRIME", "PUITS",
	"QUOTA", "RADIO", "RAYON", "REINE", "RIVAL",
	"ROBOT", "ROUGE", "ROUTE", "SABLE", "SALLE",
	"SALON", "SAUCE", "SAVON", "SCENE", "SERRE",
	"SIEGE", "SIGNE", "SOEUR", "SOUPE", "SPORT",
	"STADE", "SUCRE", "TABAC", "TAUPE", "TEMPS",
	"TERRE", "TIGRE", "TISSU", "TITRE", "TOILE",
	"TRAIN", "TRAIT", "TROIS", "TUYAU", "USINE",
	"VACHE", "VAGUE", "VALSE", "VENTE", "VERRE",
	"VIDEO", "VIEUX", "VILLE", "VOILE", "VOTRE",
	"VOYOU", "ZEBRE", "ALBUM", "AMOUR", "ANGLE",
	"AIGLE", "AIMER", "ARMEE", "AUTRE", "BAGUE",
	"BALAI", "BASSE", "BEIGE", "BISOU", "BOULE",
	"BRAVO", "BRUME", "CANAL", "CARRE", "CAUSE",
	"CHAMP", "COMTE", "CORDE", "COUPE", "CRABE",
	"DEBUT", "DEMON", "DIEUX", "DOUTE", "DRAME",
	"ECHEC", "FAUTE", "FICHE", "FILLE", "FILMS",
	"FINIR", "FOLIE", "FONDS", "FOSSE", "FRERE"
	};
	int wordListSize = sizeof(wordList) / sizeof(wordList[0]);
	int nbBannedWords = 0;

	int page = 0;
	while (page != -1)
	{
		//Title screen
		if (page == 0)
		{
			system("cls");
			cout << " Bienvenue sur le Wordle fr! Voulez vous jouer ? ( 1 : oui | 0 : non ) " << endl;
			if (AskInt(0, 1) == 1)
			{
				page = 1;
			}

			else
			{
				page = -1;
			}
		}

		else if (page == 1)
		{
			int chaseWordIndex = rand() % (wordListSize - nbBannedWords) + nbBannedWords;
			const char* chaseWord = wordList[chaseWordIndex];
			for (int i = chaseWordIndex - 1; i > -1; i--)
			{
				wordList[i + 1] = wordList[i];
			}

			wordList[0] = chaseWord;
			cout << chaseWord << endl;
			nbBannedWords++;
			
			int selecIndex = 0;
			char grid[6][6] = { "_____", "_____", "_____", "_____", "_____", "_____" };
			int nbAttemps = 0;
			int win = 0;
			system("cls");
			while (win == 0)
			{
				system("cls");
				for (int i = 0; i < nbAttemps; i++)
				{
					bool usedLetters[] = { false, false, false, false, false };
					const char* colors[] = { DEFAULT, DEFAULT, DEFAULT, DEFAULT, DEFAULT, };
					int score = 0;
					for (int j = 0; j < 5; j++)
					{
						if (grid[i][j] == chaseWord[j])
						{
							colors[j] = GREEN;
							score++;
						}
						else
						{
							bool match = false;
							int k = 0;
							while (!(match) && k < 5)
							{
								if (chaseWord[k] == grid[i][j] && !(usedLetters[k]) && chaseWord[k] != grid[i][k])
								{
									usedLetters[k] = true;
									match = true;
									colors[j] = YELLOW;
								}
								k++;
							}
						}
						cout << colors[j];
						cout << grid[i][j] << " ";
					}
					if (score == 5)
						win = 1;
					else if (nbAttemps == 6)
						win = -1;
					cout << endl;
				}
				if (win == 0)
				{
					for (int i = 0; i < 5; i++)
					{
						(selecIndex == i) ? cout << BLUE : cout << DEFAULT;
						cout << grid[nbAttemps][i] << " ";
					}
					cout << DEFAULT;
					cout << endl;
				}

				for (int i = nbAttemps + 1; i < 6; i++)
				{
					cout << "_ _ _ _ _" << endl;
				}
				if (win == 0)
				{
					int input = _getch();
					if (97 <= input && input <= 122)
					{
						input -= 32;
					}

					if (65 <= input && input <= 90)
					{
						grid[nbAttemps][selecIndex] = (char)input;
						selecIndex++;
					}

					else if (input == 8 || input == 95 || input == 32)
					{
						grid[nbAttemps][selecIndex] = (char)95;

						if (input == 8)
							selecIndex--;

						else
							selecIndex++;
					}

					if (input == 0 || input == 224)
					{
						input = _getch();

						switch (input)
						{
						case 75: selecIndex--; break;
						case 77: selecIndex++; break;
						case 83: grid[nbAttemps][selecIndex] = (char)95; break;
						}

					}

					if (input == 13)
					{
						bool ready = true;
						for (int i = 0; i < 5; i++)
						{
							if (grid[nbAttemps][i] == (char)95)
								ready = false;
						}

						if (ready)
						{
							nbAttemps++;
							selecIndex = 0;
						}
					}

					if (selecIndex < 0)
						selecIndex = 0;

					if (selecIndex > 4)
						selecIndex = 4;
				}
			}
			cout << DEFAULT;
			cout << "Le mot etait : " << chaseWord << endl;
			(win == 1) ? cout << "Bravo !" : cout << "Dommage !";
			cout << endl;
			cout << "Rejouer ? ( 1 : oui | 2 : non )" << endl;
			int answer = AskInt(1, 2);
			if (answer == 2)
				page = -1;
		}
	}
	
	return 0;
}