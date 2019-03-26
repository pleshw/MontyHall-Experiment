#include <iostream>
#include "Randomizer/Randomizer.h"

using std::endl;

using Natural = unsigned int;

int main( void )
{

	std::cout << endl;

	std::cout << endl << "Monty-hall experiment.";

	// DEFINIÇÃO DE VARIAVEIS.

	// Contabilizam o numero de vitorias em cada caso.
	unsigned long numeroDeVitoriasSemTroca{0}, numeroDeVitoriasComTroca{0};

	// Define o numero de testes para cada caso.
	unsigned long numeroDeTestes {0};

	// Cria um gerador de numeros aleatórios que vai de 1 a 3.
	Randomizer gerador (1, 3);

	// Porta que vai ser escolhida aleatoriamente para conter o premio.
	long portaVencedora;

	// Porta que vai ser selecionada pelos jogadores.
	long portaEscolhidaPeloJogador;

	// Porta que sera eliminada pelo apresentador.
	long portaEliminada;

	// FIM DA DEFINIÇÃO DE VARIAVEIS.


	numeroDeTestes = 10000;

	for( unsigned long i = 0; i < numeroDeTestes; i++ )
	{

		std::cout << endl << endl << endl << endl << endl << "COMEÇA UMA NOVA PARTIDA!";
		

		// TO-DO: Escolher uma porta vencedora.
		portaVencedora = gerador.GetRandomInt();

		// TO-DO: O jogador escolhe uma porta.
		portaEscolhidaPeloJogador = gerador.GetRandomInt();
		std::cout << endl << endl 
			  << "O participante escolhe a porta [" << portaEscolhidaPeloJogador << "].";

		// TO-DO: Escolher uma porta aleatória que não é vencedora.
		portaEliminada = gerador.GetRandomIntWithTwoExceptions( portaVencedora, portaEscolhidaPeloJogador );

		std::cout << endl << endl
				  << "O apresentador acaba de eliminar a porta *" << portaEliminada << "*" << endl
				  << "Mas o participante opta por permanecer com a porta que ele escolheu.";


		// TO-DO: Se o jogador escolheu a porta certa ele vence.
		if( portaEscolhidaPeloJogador == portaVencedora )
		{
			std::cout << endl << endl 
					  << "A porta vencedora era a porta [" << portaVencedora << "]." <<  endl
					  << "O jogador escolheu a porta " << ">>[" << portaEscolhidaPeloJogador << "]<< e ganhou." << endl
					  << "PARABENS!";

			numeroDeVitoriasSemTroca++;
		}
		else 
			std::cout << endl << endl 
					  << "O jogador escolheu a porta [" << portaEscolhidaPeloJogador << "] e infelizmente perdeu." << endl
					  << "O premio estava na porta " << portaVencedora << ".";

	}// for




//====================================================================================================================================

	for( unsigned long i = 0; i < numeroDeTestes; i++ )
	{
		std::cout << endl << endl << endl << endl << endl << "COMEÇA UMA NOVA PARTIDA!";

		// TO-DO: Escolher uma porta vencedora.
		portaVencedora = gerador.GetRandomInt();

		// TO-DO: O jogador escolhe uma porta.
		portaEscolhidaPeloJogador = gerador.GetRandomInt();
		std::cout << endl << endl 
			  << "O participante escolhe a porta [" << portaEscolhidaPeloJogador << "].";

		// TO-DO: Escolher uma porta aleatória que não é vencedora.
		portaEliminada = gerador.GetRandomIntWithTwoExceptions( portaVencedora, portaEscolhidaPeloJogador );
		std::cout << endl << endl
				  << "O apresentador acaba de eliminar a porta *" << portaEliminada << "*";

		// TO-DO: O jogador troca a porta escolhida.
		portaEscolhidaPeloJogador = gerador.GetRandomIntWithTwoExceptions( portaEscolhidaPeloJogador, portaEliminada );

		std::cout << endl << endl
			  << "Mas o jogador decide trocar de porta!" << endl 
			  << "Ele escolhe a porta [" << portaEscolhidaPeloJogador << "].";


		// TO-DO: Se o jogador escolheu a porta certa ele vence.
		if( portaEscolhidaPeloJogador == portaVencedora )
		{
			std::cout << endl << endl 
					  << "A porta vencedora era a porta [" << portaVencedora << "]." <<  endl
					  << "O jogador escolheu a porta " << ">>[" << portaEscolhidaPeloJogador << "]<< e ganhou." << endl
					  << "PARABENS!";
			numeroDeVitoriasComTroca++;
		}
		else 
			std::cout << endl << endl 
					  << "O jogador escolheu a porta [" << portaEscolhidaPeloJogador << "] e infelizmente perdeu." << endl
					  << "O premio estava na porta " << portaVencedora << ".";

	}// for



	std::cout << endl << endl << endl << endl;

	std::cout << endl << "FIM DO PROGRAMA." << endl << endl;

	std::cout << endl << "Resultado para " << numeroDeTestes << " numero de testes em cada evento.";

	std::cout << endl << endl << endl << "Numero de participantes que ganharam sem a troca: " << numeroDeVitoriasSemTroca << endl
					  << "Numero de participantes que ganharam com a troca: " << numeroDeVitoriasComTroca
					  << endl << endl;

	return 1;
}