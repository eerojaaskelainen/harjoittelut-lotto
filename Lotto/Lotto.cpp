// Lotto.cpp : Defines the entry point for the console application.
// Lottopeli: Arpoo seitsem‰n numeroa ja kolme lis‰numeroa.

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const int lottorivinNumeromaara = 7;						// Kuinka monta "ruksia" voi ruudukkoon laittaa.
	//	const int lottorivienMaara = 3;								// Kuinka monta ruudukkoa t‰ytet‰‰n.

	// Kysyt‰‰n k‰ytt‰j‰n tiedot:
	Asiakastiedot tiedot = KysyAsiakastiedot();					// Lˆytyy lottolappu.cpp -tiedostosta.

	// Kysyt‰‰n lottonumerot:
	int **lottorivit =0;										// Dynaaminen array (luodaan kuntoon k‰ytt‰j‰n m‰‰ritt‰m‰n rivim‰‰r‰n mukaisesti) kaksi ** koska tulee sis‰lt‰m‰‰n arvoina pointterit
	int kayttajanPelaamaRivimaara = 0;							// K‰ytt‰j‰lt‰ kysytt‰v‰ lottorivien lukum‰‰r‰

	cout << endl << endl << "Montako rivia haluat lotota? ";
	cin >> kayttajanPelaamaRivimaara;


	if (kayttajanPelaamaRivimaara > 0) {
		// Jos k‰ytt‰j‰ halusi lotota.

		lottorivit = new (nothrow) int*[kayttajanPelaamaRivimaara];	// Luodaan dynaaminen array perustuen k‰ytt‰j‰n haluamaan rivim‰‰r‰‰n. nothrow sen takia, ettei haluta exceptionia k‰ytett‰v‰n jos luonti ei onnistu.
		if (lottorivit == nullptr) {
			cout << "Virhe: Lottolappua ei voitu luoda..." << endl;
		}
		else {			// Dynaaminen muuttuja on luotu:
			for (int r = 0; r < kayttajanPelaamaRivimaara; r++) {		//K‰yd‰‰n lottorivit l‰pi yksitellen:
				cout << endl << endl << "Taytetaan ruudukko " << r + 1 << ":" << endl;
				lottorivit[r] = new int[lottorivinNumeromaara];			// Luodaan numerot sis‰lt‰v‰ dynaaminen array. Ei t‰hte‰ koska tulee sis‰lt‰m‰‰n arvon

				KysyLottorivi(lottorivinNumeromaara, lottorivit[r]);	// Kysyt‰‰n k‰ytt‰j‰lt‰ lottorivi. (Sijaitsee lottolappu.cpp:ss‰)
			}
		}
	}




	// Ajetaan lottokone, josta saadaan viralliset numerot:

	Lottonumerot arvotut = ArvoNumerot();		// lˆytyy lottokone.cpp -tiedostosta

	//Lajitellaan lottonumerot nousevasti:
	qsort(arvotut.numerot, perusnumeroidenMaara, sizeof(int), LajittelunVertailu);

	//Lajitellaan lis‰numerot nousevasti:
	qsort(arvotut.lisanumerot, lisanumeroidenMaara, sizeof(int), LajittelunVertailu);


	// Tulostetaan ruudulle oikea rivi lajitelluin numeroin:
	cout << endl << "------------------------------------------------------------" << endl
		<< "Kierroksella arvotut numerot ovat:\n";
	for (int i = 0; i < perusnumeroidenMaara; i++) {
		cout << arvotut.numerot[i] << ", ";
	}
	cout << "\b\b  " << endl << endl << "Ja lisanumerot:\n";
	for (int i = 0; i < lisanumeroidenMaara; i++) {
		cout << arvotut.lisanumerot[i] << ", ";
	}

	cout << "\b\b  " << endl << endl << endl << endl;					// Viimeisen numeron j‰lkeen pilkku pois


	// ------------------------- TUTKITAAN LOTTOLAPPU, oliko voittoja...
	if (kayttajanPelaamaRivimaara >0 && lottorivit != nullptr) {		//Jos k‰ytt‰j‰ pelasi lottoa ja muuttuja on kunnossa:
		TarkistaVoitot(kayttajanPelaamaRivimaara, lottorivinNumeromaara, lottorivit, arvotut);
	}

	system("pause");

	// Tuhotaan lottolappu:
	for (int a = 0; a < kayttajanPelaamaRivimaara; a++) {

		delete[] lottorivit[a];
		lottorivit[a] = 0;
	}
	
	delete[] lottorivit;
	lottorivit = 0;

	return 0;
}



int LajittelunVertailu(const void * a, const void * b)
{
		// qsort-funktion k‰sittelev‰ funktio. kun halutaan j‰rjestell‰ kokonaislukuja pienimm‰st‰ alkaen nousevaan j‰rjestykseen.

	return (*(int*)a - *(int*)b);					/*	Jos a on suurempi, tulee palautusarvoksi >0, eli qsort lajittelee a:n j‰lkeen b:n.
													*	Jos taas b on suurempi, tulee palautusarvoksi <0, jolloin qsort lajittelee b:n ensin
													*	Jos molemmat ovat yht‰suuret, tulee palautusarvoksi 0. Qsort pit‰‰ yht‰suurena.*/
}