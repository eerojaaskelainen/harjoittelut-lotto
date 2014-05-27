//Lottolappu
// Sis‰lt‰‰ k‰ytt‰j‰lt‰ kyselt‰vien lottorivien kyselyn, sek‰ tarkistukset.

#include "stdafx.h"
#include "lottolappu.h"

Asiakastiedot KysyAsiakastiedot() {
	// Funktio kysyy asiakkaalta h‰nen tietonsa, ja palauttaa ne.

	Asiakastiedot tiedot;					// T‰h‰n ker‰t‰‰n tiedot, ja palautetaan:
	tiedot.etunimi = "";
	tiedot.sukunimi = "";
	tiedot.lahiosoite = "";
	tiedot.postinumero = "";
	tiedot.postitoimipaikka = "";
	tiedot.puhelinnumero = "";

	cout << "Etunimi: ";
	getline(cin, tiedot.etunimi);

	cout << "\nSukunimi: ";
	getline(cin, tiedot.sukunimi);

	cout << "\nLahiosoite: ";
	getline(cin, tiedot.lahiosoite);

	cout << "\nPostinumero: ";
	getline(cin, tiedot.postinumero);

	cout << "\nPostitoimipaikka: ";
	getline(cin, tiedot.postitoimipaikka);

	cout << "\nPuhelinnumero: ";
	getline(cin, tiedot.puhelinnumero);



	return tiedot;
}

void KysyLottorivi(int ruksimaara, int *rivi) {
	// Kysyy lottorivin k‰ytt‰j‰lt‰. Argumenttina tuodaan pointteri joka t‰ytet‰‰n k‰ytt‰j‰n antamilla numeroilla.
	// 
	int syoteNum = 0;							// K‰ytt‰j‰n antama luku
	bool syoteKelpaa = true;					//Lippu, joka muutetaan jos k‰ytt‰j‰ antaa ep‰kelvollisen numeron.

	for (int i = 0; i < ruksimaara;) {
		
		syoteKelpaa = true;						// Nollataan lippu joka kierroksen alussa

		cout << "\tAnna " << i+1 << ":s numero: ";
		cin >> syoteNum;
		
		if (syoteNum > 0 && syoteNum <= suurinNumero) {
			// Syˆtetty numero on annettujen ‰‰riarvojen sis‰ll‰. Teemme lis‰testaukset:
			for (int syote = 0; syote < i; syote++) {
				// Syˆtetty numero on jo kyseisell‰ lottorivill‰!
				if (*(rivi + syote) == syoteNum) {
					cout << "Samassa ruudukossa on jo numero " << syoteNum << ". Anna toinen numero..." << endl;
					syoteKelpaa = false;
					break;
				}	
			}
		}
		else {
			// Syˆte ei ollut annettujen ‰‰riarvojen sis‰ll‰. Ei kelpaa.
			cout << "Antamasi numero ei sovi ruudukkoon. Anna numero valilta 1-" << suurinNumero << "." << endl;
			syoteKelpaa = false;
		}

		// Katsotaan, miss‰ asennossa lippu on. Oliko syˆte kunnossa? Voidaanko jatkaa seuraavaan numeroon/ruudukkoon?
		if (syoteKelpaa == true) {
			*(rivi + i) = syoteNum;
			i++;
		}
		
	}
	
}

void TarkistaVoitot(int ruudukoidenMaara, int numeroMaara, int **lappu, Lottonumerot virallinenTulos) {
	// Funktio tarkistaa osumat k‰ytt‰j‰n m‰‰rittelemist‰ lottoriveist‰:
	// ruudukoidenMaara		: k‰ytt‰j‰n antamien ruudukoiden (lottorivien) lukum‰‰r‰
	// numeroMaara			: Montako ruksia ruudukossa on
	// lappu				: K‰ytt‰j‰n antamat ruudukot, niiden viittaukset
	// virallinenTulos		: Ohjelman arpoma virallinen lottorivi, johon verrataan.


	bool tarkistaLisanumerot = false;					// Lippu, joka asetetaan p‰‰lle jos osumia on sen verran, ett‰ lis‰numerotkin otetaan mukaan
	int osumat = 0;										// Lottorivin osumien laskuri
	int lisaosumat = 0;									// Lottorivin lis‰osumien laskuri
	
	cout << "Tarkistetaan lottokuponkisi:" << endl << endl;

	for (int r = 0; r < ruudukoidenMaara; r++) {
			osumat = 0;
			lisaosumat = 0;
			tarkistaLisanumerot = false;

		//Tarkistetaan osumien m‰‰r‰:
			for (int x = 0; x < numeroMaara; x++) {

			for (int i = 0; i < perusnumeroidenMaara; i++) {
				if (virallinenTulos.numerot[i] == lappu[r][x]) {
					osumat++;
				}
			}
		}

		// Tutkitaan osumista, tarvitaanko lis‰numeroiden tarkistusta:
		switch (osumat) {
				case 3:
				case 4:
				case 5:
				case 6:
					tarkistaLisanumerot = true;
		}

		if (tarkistaLisanumerot == true) {
			// Osumia oli sen verran sopivasti, jotta lis‰numerot tulevat k‰yttˆˆn:
		
			for (int x = 0; x < numeroMaara; x++) {

				for (int lisanum = 0; lisanum < lisanumeroidenMaara; lisanum++){
					if (virallinenTulos.lisanumerot[lisanum] == lappu[r][x]){
						lisaosumat++;
					}
				}
			}
		}

		// Rivi tarkistettu, nyt k‰yd‰‰n l‰pi osumat, ja tulostetaan k‰ytt‰j‰lle:
		switch (osumat) {
		case 3:
			if (lisaosumat == 1) {
				cout << "Ruudukossa " << r+1 << " oli 3 + 1 oikein!" << endl;
			}
			else if (lisaosumat >= 2) {
				cout << "Ruudukossa " << r + 1 << " oli 3 + 2 oikein!" << endl;
			}
			break;
		case 4:
			if (lisaosumat == 0) {
				cout << "Ruudukossa " << r + 1 << " oli 4 oikein!" << endl;
			}
			else if (lisaosumat == 1) {
				cout << "Ruudukossa " << r + 1 << " oli 4 + 1 oikein!" << endl;
			}
			else if (lisaosumat == 2) {
				cout << "Ruudukossa " << r + 1 << " oli 4 + 2 oikein!" << endl;
			}
			break;
		case 5:
			if (lisaosumat == 0) {
				cout << "Ruudukossa " << r + 1 << " oli 5 oikein!" << endl;
			}
			else if (lisaosumat == 1) {
				cout << "Ruudukossa " << r + 1 << " oli 5 + 1 oikein!" << endl;
			}
			else if (lisaosumat == 2) {
				cout << "Ruudukossa " << r + 1 << " oli 5 + 2 oikein!" << endl;
			}
			break;
		case 6:
			if (lisaosumat == 0) {
				cout << "Ruudukossa " << r + 1 << " oli 6 oikein!" << endl;
			}
			else if (lisaosumat == 1) {
				cout << "Ruudukossa " << r + 1 << " oli 6 + 1 oikein!" << endl;
			}
			break;
		case 7:
			cout << "Ruudukossa " << r + 1 << " on PƒƒVOITTO! 7 oikein!" << endl;
			break;
		default:
			cout << "Ruudukossa " << r + 1 << " ei voittoa." << endl;
		}

		cout << endl;
	}
}

