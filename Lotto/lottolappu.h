#ifndef LOTTOLAPPU
#define LOTTOLAPPU 1

#include <string>

struct Asiakastiedot  {
	std::string etunimi;
	std::string sukunimi;
	std::string lahiosoite;
	std::string postinumero;
	std::string postitoimipaikka;
	std::string puhelinnumero;
};

Asiakastiedot KysyAsiakastiedot();

void KysyLottorivi(int ruksimaara, int *rivi);
void TarkistaVoitot(int ruudukoidenMaara, int rivienMaara, int **lappu, Lottonumerot virallinenTulos);
#endif