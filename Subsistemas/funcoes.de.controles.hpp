#ifndef FUNCOES_DE_CONTROLES_HPP_INCLUDED
#define FUNCOES_DE_CONTROLES_HPP_INCLUDED

/**
* @brief Limpa a tela do console.
* @details Usa o comando 'cls' para Windows e 'clear' para sistema baseados em Unix/Linux.
*/
void limparTela();
/**
* @brief Pausa a execução do programa pelo numero de segundos especificado.
* @param segundos O tempo de pausa em segundos.
* @details Usa a funcao sleep() (milissegundos) para Windows e sleep() (segundos) para outros sistemas.
*/
void esperar(int segundos);

#endif // FUNCOES_DE_CONTROLES_HPP_INCLUDED
