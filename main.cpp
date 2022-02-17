#include <iostream>
#include <unistd.h>
#include <time.h>
#include <locale.h>


using namespace std;

int main() {
    int menuOption, dificulty = 1, returnMenuOrChangedDificulty, returnToMenu, closeTheGame;
    int startGame, prosseguirNoJogo;

    /* Cria��o da Matriz Principal */

	int operationMatriz;
	int rowGame, colGame, value;
	char table;
	int matrizGame[9][9];
	int matriz[9][9] = { {4,9,5,2,8,7,3,6,1},
						 {7,2,8,6,1,3,4,9,5},
						 {3,6,1,9,5,4,7,2,8},
						 {6,5,3,8,4,9,2,1,7},
						 {9,8,4,1,7,2,6,5,3},
						 {2,1,7,5,3,6,9,8,4},
						 {1,3,2,4,6,5,8,7,9},
						 {5,4,6,7,9,8,1,3,2},
						 {8,7,9,3,2,1,5,4,6}
	};


    do{
        system("tput reset");
        do {
            setlocale(LC_ALL, "Portuguese");
            std::cout << "********************************************" << std::endl;
            std::cout << "*******************SUDOKU*******************" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "Digite >1< ---Para iniciar o jogo---" << std::endl;
            std::cout << "Digite >2< ---Para alterar a dificuldade---" << std::endl;
            std::cout << "Digite >3< ---Para aprender a jogar---" << std::endl;
            std::cout << "Digite >4< ---Para ler sobre os desenvolvedores---" << std::endl;
            std::cout << "Digite >5< ---Para sair do jogo---" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "********************************************" << std::endl;
            std::cout << "Digite a sua op��o abaixo:" << std::endl;
            std::cin >> menuOption;
            system("tput reset");

            srand(time(0));
	        int op = rand() % 5;

            switch (op) {

        case 1: {
            for (int row = 0; row <= 8; row++) {
                for (int col = 0; col <= 8; col++) {
                    matrizGame[row][col] = matriz[row][col];
                }
            }

            table = 'A';

            break;
        }

        case 2: {
            for (int row = 0; row < 9; row++) {
                for (int col = 0; col < 9; col++) {
                    matrizGame[col][row] = matriz[col][row];
                }
            }

            table = 'B';

            break;
        }

        case 3: {
            for (int row = 8; row >= 0; row--) {
                for (int col = 0; col <= 8; col++) {
                    matrizGame[row][col] = matriz[row][col];
                }
            }

            table = 'C';

            break;
        }

        case 4: {
            for (int row = 0; row <= 8; row++) {
                for (int col = 8; col >= 0; col--) {
                    matrizGame[row][col] = matriz[row][col];
                }
            }

            table = 'D';

            break;
        }

        default:
            break;
        }





            switch (menuOption) {
                case 1: //!Start game


                //Dificuldade F�cil
                    if(dificulty == 1){

                    //Espa�o para configurar as dificuldades (F�cil)

                        do{
                        std::cout << "--------------------------------------------------------------------" << std::endl;
                        std::cout << " Vamos come�ar o jogo" << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << " Dificuldade de n�vel f�cil (1) Selecionada " << std::endl;
                        std::cout << "50% dos valores da matriz resposta foram adicionados a tabela." << std::endl;
                        std::cout << " Lembrando que voc� pode atualiza-la no menu inicial." << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << "Preencha a tabela com n�meros de 1 a 9." << std::endl;
                        std::cout << "Sem que haja quaisquer repeti��es de n�meros na mesma linha ou grade" << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << "--------------------------------------------------------------------" << std::endl;
                        std::cout << " Digite '1' abaixo para dar inicio ao jogo:" << std::endl;
                        std::cin >> startGame;
                        system("tput reset");


                        for (int i = 0; i < 41; i++) {
                            int firstAleatory = rand() % 9;
                            int secondAleatory = rand() % 9;

                            matrizGame[firstAleatory][secondAleatory] = 0;
		                }

                        }while(startGame != 1);

                        bool loop = true;

                    do {
                        if (loop) {
                        std::cout << "\n--------- Sudoku ---------\n";

                        std::cout << "\n1  2  3  4  5  6  7  8  9\n";

                        std::cout << "\n--------------------------\n";

                        std::cout << "\nColoque valores no lugar do 0\n\n";

                        std::cout << "\n";
                        std::cout << "\n";
                        std::cout << "\n";



                        if (table == 'A') {
                            do {

                                for (int row = 0; row <= 8; row++) {
                                    for (int col = 0; col <= 8; col++) {
                                        std::cout << "  " << matrizGame[row][col];
                                    }
                                    std::cout << "\n";
                                }

                                std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                                std::cin >> rowGame >> colGame >> value;

                                rowGame--;
                                colGame--;

                                bool error1 = false;
                                int verify;

                                        if (matrizGame[(rowGame)][(colGame)] != 0) {

                                            std::cout << "\n *** Posicao ja preenchida *** \n";
                                            std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                            std::cin >> verify;

                                            if (verify == 1) {
                                                matrizGame[rowGame][colGame] = value;

                                                for (int i = 0; i <= 8; i++) {
                                                    if (matrizGame[i][colGame] == value) {
                                                        error1 = true;
                                                        break;
                                                    }
                                                }

                                                for (int j = 0; j <= 8; j++) {
                                                    if (matrizGame[rowGame][j] == value) {
                                                        error1 = true;
                                                    }
                                                }

                                                if (error1) {
                                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                                }
                                                else {
                                                    matrizGame[rowGame][colGame] = value;
                                                }
                                            }

                                        }
                                        else {
                                            for (int i = 0; i <= 8; i++) {
                                                if (matrizGame[i][colGame] == value) {
                                                    error1 = true;
                                                    break;
                                                }
                                            }

                                            for (int j = 0; j <= 8; j++) {
                                                if (matrizGame[rowGame][j] == value) {
                                                    error1 = true;
                                                }
                                            }

                                            if (error1) {
                                                std::cout << "\nvalor ja esta na linha ou coluna\n";
                                            }
                                            else {
                                                matrizGame[rowGame][colGame] = value;
                                            }

                                        }


                            } while (rowGame < 1 || rowGame > 9 || colGame < 1 || colGame > 9 || value < 1 || value > 9);

                        }
                        else if (table == 'B') {

                            for (int row = 0; row < 9; row++) {
                                for (int col = 0; col < 9; col++) {
                                    std::cout << "  " << matrizGame[col][row];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posicao ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }
                        else if (table == 'C') {

                            for (int row = 8; row >= 0; row--) {
                                for (int col = 0; col <= 8; col++) {
                                    std::cout << "  " << matrizGame[row][col];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posi��o ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }
                        else {
                            for (int row = 0; row <= 8; row++) {
                                for (int col = 8; col >= 0; col--) {
                                    std::cout << "  " << matrizGame[row][col];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posicao ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }

                        loop = false;
                    }

                } while (matrizGame[8][8] != matriz[8][8]);

                std::cout << "Parab�ns, voc� ganhou a partida";

                    //Dificuldade M�dia
                    }else if(dificulty == 2){

                     //Espa�o para configurar as dificuldades(M�dio)

                        do{
                            std::cout << "-------------------------------------------------------------------" << std::endl;
                            std::cout << " Vamos come�ar o jogo" << std::endl;
                             std::cout <<" "<< std::endl;
                            std::cout << " Dificuldade de n�vel M�dio (2) Selecionada ----(Padr�o)----" << std::endl;
                            std::cout << " 40% dos valores da matriz resposta foram adicionados a tabela." << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "Preencha a tabela com n�meros de 1 a 9." << std::endl;
                            std::cout << "Sem que haja quaisquer repeti��es de n�meros na mesma linha ou grade" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "-------------------------------------------------------------------" << std::endl;
                            std::cout << "Digite '1' abaixo para dar inicio ao jogo:" << std::endl;
                            std::cin >> startGame;
                            system("tput reset");


                            for (int i = 0; i < 48; i++) {
                                int firstAleatory = rand() % 9;
                                int secondAleatory = rand() % 9;

                                matrizGame[firstAleatory][secondAleatory] = 0;
                            }

                        }while(startGame != 1);

                        bool loop = true;

                    do {
                        if (loop) {
                        std::cout << "\n--------- Sudoku ---------\n";

                        std::cout << "\n1  2  3  4  5  6  7  8  9\n";

                        std::cout << "\n--------------------------\n";

                        std::cout << "\nColoque valores no lugar do 0\n\n";

                        std::cout << "\n";
                        std::cout << "\n";
                        std::cout << "\n";



                        if (table == 'A') {
                            do {

                                for (int row = 0; row <= 8; row++) {
                                    for (int col = 0; col <= 8; col++) {
                                        std::cout << "  " << matrizGame[row][col];
                                    }
                                    std::cout << "\n";
                                }

                                std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                                std::cin >> rowGame >> colGame >> value;

                                rowGame--;
                                colGame--;

                                bool error1 = false;
                                int verify;

                                        if (matrizGame[(rowGame)][(colGame)] != 0) {

                                            std::cout << "\n *** Posicao ja preenchida *** \n";
                                            std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                            std::cin >> verify;

                                            if (verify == 1) {
                                                matrizGame[rowGame][colGame] = value;

                                                for (int i = 0; i <= 8; i++) {
                                                    if (matrizGame[i][colGame] == value) {
                                                        error1 = true;
                                                        break;
                                                    }
                                                }

                                                for (int j = 0; j <= 8; j++) {
                                                    if (matrizGame[rowGame][j] == value) {
                                                        error1 = true;
                                                    }
                                                }

                                                if (error1) {
                                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                                }
                                                else {
                                                    matrizGame[rowGame][colGame] = value;
                                                }
                                            }

                                        }
                                        else {
                                            for (int i = 0; i <= 8; i++) {
                                                if (matrizGame[i][colGame] == value) {
                                                    error1 = true;
                                                    break;
                                                }
                                            }

                                            for (int j = 0; j <= 8; j++) {
                                                if (matrizGame[rowGame][j] == value) {
                                                    error1 = true;
                                                }
                                            }

                                            if (error1) {
                                                std::cout << "\nvalor ja esta na linha ou coluna\n";
                                            }
                                            else {
                                                matrizGame[rowGame][colGame] = value;
                                            }

                                        }


                            } while (rowGame < 1 || rowGame > 9 || colGame < 1 || colGame > 9 || value < 1 || value > 9);

                        }
                        else if (table == 'B') {

                            for (int row = 0; row < 9; row++) {
                                for (int col = 0; col < 9; col++) {
                                    std::cout << "  " << matrizGame[col][row];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posicao ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }
                        else if (table == 'C') {

                            for (int row = 8; row >= 0; row--) {
                                for (int col = 0; col <= 8; col++) {
                                    std::cout << "  " << matrizGame[row][col];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posi��o ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }
                        else {
                            for (int row = 0; row <= 8; row++) {
                                for (int col = 8; col >= 0; col--) {
                                    std::cout << "  " << matrizGame[row][col];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posicao ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }

                        loop = false;
                    }

                } while (matrizGame[8][8] != matriz[8][8]);

                std::cout << "Parab�ns, voc� ganhou a partida";



                    //Dificuldade Dif�cil
                    } else {


                     //Espa�o para configurar as dificuldades (Dif�cil)

                        do{
                            std::cout << "-------------------------------------------------------------------" << std::endl;
                            std::cout << " Vamos come�ar o jogo" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << " Dificuldade de n�vel Dif�cil (3) Selecionada " << std::endl;
                            std::cout << " 35% dos valores da matriz resposta foram adicionados a tabela." << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "Preencha a tabela com n�meros de 1 a 9." << std::endl;
                            std::cout << "Sem que haja quaisquer repeti��es de n�meros na mesma linha ou grade" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "-------------------------------------------------------------------" << std::endl;
                            std::cout << "Digite '1' abaixo para dar inicio ao jogo:" << std::endl;
                            std::cin >> startGame;
                            system("tput reset");


                            for (int i = 0; i < 52; i++) {
                                int firstAleatory = rand() % 9;
                                int secondAleatory = rand() % 9;

                                matrizGame[firstAleatory][secondAleatory] = 0;
                            }
                        }while(startGame != 1);

                        bool loop = true;

                    do {
                        if (loop) {
                        std::cout << "\n--------- Sudoku ---------\n";

                        std::cout << "\n1  2  3  4  5  6  7  8  9\n";

                        std::cout << "\n--------------------------\n";

                        std::cout << "\nColoque valores no lugar do 0\n\n";

                        std::cout << "\n";
                        std::cout << "\n";
                        std::cout << "\n";



                        if (table == 'A') {
                            do {

                                for (int row = 0; row <= 8; row++) {
                                    for (int col = 0; col <= 8; col++) {
                                        std::cout << "  " << matrizGame[row][col];
                                    }
                                    std::cout << "\n";
                                }

                                std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                                std::cin >> rowGame >> colGame >> value;

                                rowGame--;
                                colGame--;

                                bool error1 = false;
                                int verify;

                                        if (matrizGame[(rowGame)][(colGame)] != 0) {

                                            std::cout << "\n *** Posicao ja preenchida *** \n";
                                            std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                            std::cin >> verify;

                                            if (verify == 1) {
                                                matrizGame[rowGame][colGame] = value;

                                                for (int i = 0; i <= 8; i++) {
                                                    if (matrizGame[i][colGame] == value) {
                                                        error1 = true;
                                                        break;
                                                    }
                                                }

                                                for (int j = 0; j <= 8; j++) {
                                                    if (matrizGame[rowGame][j] == value) {
                                                        error1 = true;
                                                    }
                                                }

                                                if (error1) {
                                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                                }
                                                else {
                                                    matrizGame[rowGame][colGame] = value;
                                                }
                                            }

                                        }
                                        else {
                                            for (int i = 0; i <= 8; i++) {
                                                if (matrizGame[i][colGame] == value) {
                                                    error1 = true;
                                                    break;
                                                }
                                            }

                                            for (int j = 0; j <= 8; j++) {
                                                if (matrizGame[rowGame][j] == value) {
                                                    error1 = true;
                                                }
                                            }

                                            if (error1) {
                                                std::cout << "\nvalor ja esta na linha ou coluna\n";
                                            }
                                            else {
                                                matrizGame[rowGame][colGame] = value;
                                            }

                                        }


                            } while (rowGame < 1 || rowGame > 9 || colGame < 1 || colGame > 9 || value < 1 || value > 9);

                        }
                        else if (table == 'B') {

                            for (int row = 0; row < 9; row++) {
                                for (int col = 0; col < 9; col++) {
                                    std::cout << "  " << matrizGame[col][row];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posicao ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }
                        else if (table == 'C') {

                            for (int row = 8; row >= 0; row--) {
                                for (int col = 0; col <= 8; col++) {
                                    std::cout << "  " << matrizGame[row][col];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posi��o ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }
                        else {
                            for (int row = 0; row <= 8; row++) {
                                for (int col = 8; col >= 0; col--) {
                                    std::cout << "  " << matrizGame[row][col];
                                }
                                std::cout << "\n";
                            }

                            std::cout << "Insira Linha, Coluna e Valor desejado de 1 a 9:\n";
                            std::cin >> rowGame >> colGame >> value;

                            rowGame--;
                            colGame--;

                            bool error1 = false;
                            int verify;

                            if (matrizGame[(rowGame)][(colGame)] != 0) {

                                std::cout << "\n *** Posicao ja preenchida *** \n";
                                std::cout << "\ndigite 1 para inserir e 0 para sair\n";
                                std::cin >> verify;

                                if (verify == 1) {
                                    matrizGame[rowGame][colGame] = value;

                                    for (int i = 0; i <= 8; i++) {
                                        if (matrizGame[i][colGame] == value) {
                                            error1 = true;
                                            break;
                                        }
                                    }

                                    for (int j = 0; j <= 8; j++) {
                                        if (matrizGame[rowGame][j] == value) {
                                            error1 = true;
                                        }
                                    }

                                    if (error1) {
                                        std::cout << "\nvalor ja esta na linha ou coluna\n";
                                    }
                                    else {
                                        matrizGame[rowGame][colGame] = value;
                                    }
                                }

                            }
                            else {
                                for (int i = 0; i <= 8; i++) {
                                    if (matrizGame[i][colGame] == value) {
                                        error1 = true;
                                        break;
                                    }
                                }

                                for (int j = 0; j <= 8; j++) {
                                    if (matrizGame[rowGame][j] == value) {
                                        error1 = true;
                                    }
                                }

                                if (error1) {
                                    std::cout << "\nvalor ja esta na linha ou coluna\n";
                                }
                                else {
                                    matrizGame[rowGame][colGame] = value;
                                }

                            }

                        }

                        loop = false;
                    }

                } while (matrizGame[8][8] != matriz[8][8]);

                std::cout << "Parab�ns, voc� ganhou a partida";


                    }

                    usleep(2000);
                    break;





                case 2: //!Selecionar a dificuldade
                    do {
                        std::cout << "--------------------------------------------------------------" << std::endl;
                        std::cout << "Selecione a dificuldade:" << std::endl;
                        std::cout << "--------------------------------------------------------------" << std::endl;
                         std::cout <<" "<< std::endl;
                        std::cout << "Digite >1< para selecionar a dificuldade n�vel: F�cil " << std::endl;
                        std::cout << "Exibe 50% dos valores da matriz resposta ao iniciar o jogo." << std::endl;
                         std::cout <<" "<< std::endl;
                        std::cout << "--------------------------------------------------------------" << std::endl;
                         std::cout <<" "<< std::endl;
                        std::cout << "Digite >2< para selecionar a dificuldade n�vel: M�dio (Padr�o)" << std::endl;
                        std::cout << "Exibe 40% dos valores da matriz resposta ao iniciar o jogo. " << std::endl;
                         std::cout <<" "<< std::endl;
                        std::cout << "--------------------------------------------------------------" << std::endl;
                         std::cout <<" "<< std::endl;
                        std::cout << "Digite >3< para selecionar a dificuldade n�vel: D�ficil" << std::endl;
                        std::cout << "Exibe 35% dos valores da matriz resposta ao iniciar o jogo." << std::endl;
                         std::cout <<" "<< std::endl;
                          std::cout <<" "<< std::endl;
                        std::cout << "--------------------------------------------------------------" << std::endl;
                        std::cout << "Preencha a tabela com n�meros de 1 a 9." << std::endl;
                        std::cout << "Sem que haja quaisquer repeti��es de n�meros na mesma linha ou grade" << std::endl;
                         std::cout <<" "<< std::endl;
                        std::cout << "--------------------------------------------------------------" << std::endl;
                        std::cout << "Digite abaixo o n�vel de dificuldade escolhido: " << std::endl;
                        std::cin >> dificulty;
                        system("tput reset");
                        if(dificulty == 1){
                            std::cout <<" "<< std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "**************************************" << std::endl;
                            std::cout << "Dificuldade n�vel >>F�CIL<< selecionada." << std::endl;
                            std::cout << "**************************************" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "Digite '1' para voltar ao menu" << std::endl;
                            std::cout << "Digite '2' para trocar dificuldade" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "--------------------------------------" << std::endl;
                            std::cout << "Digite abaixo a op��o escolhida:" << std::endl;
                            std::cin >> returnMenuOrChangedDificulty;
                            system("tput reset");
                            if(returnMenuOrChangedDificulty == 1){
                                break;
                                system("tput reset");
                            }
                        } else if (dificulty == 2){
                            std::cout <<" "<< std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "**************************************" << std::endl;
                            std::cout << "Dificuldade n�vel >>M�DIO<< selecionada." << std::endl;
                            std::cout << "**************************************" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "Digite '1' para voltar ao menu" << std::endl;
                            std::cout << "Digite '2' para trocar dificuldade" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "--------------------------------------" << std::endl;
                            std::cout << "Digite abaixo a op��o escolhida:" << std::endl;
                            std::cin >> returnMenuOrChangedDificulty;
                            system("tput reset");
                            if(returnMenuOrChangedDificulty == 1){
                                break;
                                system("tput reset");
                            }
                        }else if (dificulty == 3){
                            std::cout <<" "<< std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "***************************************" << std::endl;
                            std::cout << "Dificuldade n�vel >>D�FICIL<< selecionada" <<std::endl;
                            std::cout << "***************************************" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "Digite '1' para voltar ao menu" << std::endl;
                            std::cout << "Digite '2' para trocar dificuldade" << std::endl;
                            std::cout <<" "<< std::endl;
                            std::cout << "---------------------------------------" << std::endl;
                            std::cout << "Digite abaixo a op��o escolhida:" << std::endl;
                            std::cin >> returnMenuOrChangedDificulty;
                            system("tput reset");
                            if(returnMenuOrChangedDificulty == 1){
                                break;
                                system("tput reset");
                            }
                        }
                    }while (returnMenuOrChangedDificulty == 2);
                    usleep(2000);
                    break;





                case 3: //!Informa��es do jogo
                    do{
                       std::cout <<" "<< std::endl;
                        std::cout << "******************************************************************************************************************************************************" << std::endl;
                        std::cout << " - A ideia principal do jogo � que o jogador preencha a tabela com n�meros de 1 a 9, sem que haja quaisquer repeti��es de n�meros na mesma linha ou grade." << std::endl;
                        std::cout << "******************************************************************************************************************************************************" << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << "-----Informa��es sobre a dificuldade:-----" << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << "Dificuldade (1) -> F�cil: exibe 50% dos valores da matriz resposta ao iniciar o jogo." << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << "Dificuldade (2) -> M�dia: exibe 40% dos valores da matriz resposta ao iniciar o jogo." << std::endl << " !!! Essa � a dificuldade padr�o, ou seja, se n�o for alterada, � nessa dificuldade que o jogo ir� rodar !!!." << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << "Dificuldade (3) -> Dif�cil: exibe 35% dos valores da matriz resposta ao iniciar o jogo." << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout <<" "<< std::endl;
                       std::cout << "******************************************************************************************************************************************************" << std::endl;
                        std::cout << "Digite abaixo '1' para voltar ao menu:" << std::endl;
                        std::cin >> returnToMenu;
                        system("tput reset");
                    } while (returnToMenu != 1);
                    usleep(2000);
                    break;





                case 4: //!Informa��es do grupo
                    do{
                            std::cout <<" "<< std::endl;
                        std::cout << "**********************************************************************************************************" << std::endl;
                        std::cout <<" "<< std::endl;
                        std::cout << "Aluno 01 - Bernardo Magueta Kowalsky - 02/2001 - Per�odo: 1� - Curso: Ci�ncia da Computa��o" << std::endl;
                        std::cout << "Aluno 02 - Jo�o Pedro Prud�ncio - 01/2003 - Per�odo: 1� - Curso: Ci�ncia da Computa��o" << std::endl;
                        std::cout << "Aluno 03 - Juan Marcos Paiter - 01/2001 -  Per�odo: 1� - Curso: Ci�ncia da Computa��o" << std::endl;
                        std::cout << std::endl;
                        std::cout << "Professor Thiago Felski Pereira" << std::endl;
                        std::cout << "Disciplina: Algoritmos e Programa��o" << std::endl;
                    std::cout <<" "<< std::endl;
                        std::cout << "**********************************************************************************************************" << std::endl;
                        std::cout << "Digite abaixo '1' para voltar ao menu:" << std::endl;
                        std::cin >> returnToMenu;
                        system("tput reset");
                    }while(returnToMenu != 1);{
                        break;
                    }
                    usleep(2000);
                    break;





                case 5: //! Case para retornar uma mensagem em branco quando selecionar a op��o 5
                    std::cout << " ";
                    break;

                default:
                    std::cout << "*****************************" << std::endl;
                    std::cout << "!!!! Op��o n�o encontrada !!!" << std::endl;
                    std::cout << "Digite '1'para voltar ao menu" << std::endl;
                    std::cout << "*****************************" << std::endl;
                    std::cin >> returnToMenu;
                    if(returnToMenu == 1){
                        std::cin.get();
                        system("tput reset");
                    }
            }
        } while (menuOption != 5);





        //! Fechar o jogo
        do{
            std::cout << " " << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "******** O jogo foi encerrado ********" << std::endl;
            std::cout << "********* Obrigado por jogar *********" << std::endl;
            std::cout << "**************************************" << std::endl;
            std::cout << "Digite '1' para fechar o jogo" << std::endl;
            std::cout << "Digite '2' para reabrir o menu do jogo" << std::endl;
            std::cout << "--------------------------------------" << std::endl;
            std::cin >> closeTheGame;
            if(closeTheGame == 1){
                break;
            }
            system("tput reset");
        }while(closeTheGame != 1 && closeTheGame != 2);
        system("tput reset");
    }while(closeTheGame == 2);

    return 0;
}
