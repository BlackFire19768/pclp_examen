#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NumarTelefon
{
	char prefix[6];
	char numar[7];
} NumarTelefon;

typedef struct Persoana
{
	char nume[20];
	char prenume[20];
	NumarTelefon telefon;
} Persoana;


void CitireNrTelefon(NumarTelefon* numar)
{
	printf("Introduceti prefixul unui numar de telefon:\n");
	scanf("%s", numar->prefix);

	printf("Introduceti cifrele unui numar de telefon:\n");
	scanf("%s", numar->numar);

	for (int i = 0; i < 6; i++)
	{
		if (!('0' <= numar->prefix[i] && numar->prefix[i] <= '9'))
		{
			// cazul in care nu e bine
		}
	}
}

void AfisareNrTelefon(const NumarTelefon* numar)
{
	printf("%s%s", numar->prefix, numar->numar);
}

int ComparereNrTelefon(NumarTelefon* numar1, NumarTelefon* numar2)
{
	return strcmp(numar1->numar, numar2->numar);
}

void CitirePersoana(Persoana* persoana)
{
	printf("Introduceti numele unei persoane:\n");
	scanf("%s", persoana->nume);

	printf("Introduceti prenumele unei persoane:\n");
	scanf("%s", persoana->prenume);

	CitireNrTelefon(&persoana->telefon);
}

void AfisarePersoana(const Persoana* persoana)
{
	printf("%s %s", persoana->nume, persoana->prenume);

	AfisareNrTelefon(&persoana->telefon);
}

int ComparerePersoana(const void* a, const void* b)
{
	// inlocuieste Persoana cu tipul din sizeof() de la qsort
	Persoana* pers_a = (Persoana*)a;
	Persoana* pers_b = (Persoana*)b;

	int comp_nume = strcmp(pers_a->nume, pers_b->nume);
	if (comp_nume != 0)
		return comp_nume;

	int comp_prenume = strcmp(pers_a->prenume, pers_b->prenume);
	return comp_prenume;
}

int main()
{
	int numar_persoane = 0;
	printf("Introduceti numarul de persoane.\n");
	scanf("%d", &numar_persoane);

	Persoana* persoane = (Persoana*)malloc(sizeof(Persoana) * numar_persoane);

	for (int i = 0; i < numar_persoane; i++)
	{
		CitirePersoana(&persoane[i]);

		for (int j = 0; j < i; j++)
		{
			int comp_result = ComparereNrTelefon(&persoane[i].telefon, &persoane[j].telefon);
			if (comp_result == 0)
			{
				printf("Nu sunt permise numere de telefon identice!\n");
				CitirePersoana(&persoane[i]);
			}
		}
	}

	for (int i = 0; i < numar_persoane; i++)
	{
		for (int j = 0; j < numar_persoane; j++)
		{
			if (i == j)
				continue;

			int comp_nume = strcmp(persoane[i].nume, persoane[j].nume);
			int comp_prenume = strcmp(persoane[i].prenume, persoane[j].prenume);

			if (comp_nume == 0 && comp_prenume == 0);
			{
				AfisarePersoana(&persoane[i]);
				AfisarePersoana(&persoane[j]);
			}
		}
	}

	for (int i = 0; i < numar_persoane; i++)
	{
		for (int j = 0; j < numar_persoane; j++)
		{
			if (i == j)
				continue;

			int comp_prefix = strcmp(persoane[i].telefon.prefix, persoane[j].telefon.prefix);

			if (comp_prefix == 0)
			{
				AfisareNrTelefon(&persoane[i].telefon);
				AfisareNrTelefon(&persoane[j].telefon);
			}
		}
	}

	// inclus in <stdlib.h>
	// parametrul 1: pointer la inceputul arrayului
	// pararetrul 2: numarul de elemente in array
	// parametrul 3: marimea in bytes a tipului arrayului, ex int pentru int array[20]
	// parametrul 4: numele functiei de comparatie
	qsort(persoane, numar_persoane, sizeof(Persoana), ComparerePersoana);
	for (int i = 0; i < numar_persoane; i++)
	{
		AfisarePersoana(&persoane[i]);
	}

	free(persoane);
	getchar();
	return 0;
}