#ifndef LOTTOKONE
#define LOTTOKONE 1



struct Lottonumerot {						// Arvotut lottonumerot sis�lt�v� struct-muuttuja
	int numerot[perusnumeroidenMaara];		// Perusnumerot
	int lisanumerot[lisanumeroidenMaara];	// Lis�numerot
};

Lottonumerot ArvoNumerot();
int PoimiPallo();
#endif