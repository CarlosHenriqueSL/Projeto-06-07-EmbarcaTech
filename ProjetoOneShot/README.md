# Unidade 4 - Atividade 2: Temporizador One Shot com LEDs e Botão

Este projeto implementa um sistema de temporização one-shot para controle de três LEDs (azul, vermelho e verde) usando um botão pushbutton.

---

## Aluno: 
- **Carlos Henrique Silva Lopes**


## Descrição do projeto
Esse projeto aciona três LEDs no acionamento do botão configurado. A cada três segundos, os LEDs se apagam em uma ordem estabelecida anteriormente, até que o sistema volte ao estado inicial. Além disso, o sistema não faz novas leituras até que todos os LEDs estejam apagados novamente.


## Funcionalidades
- **Acionamento por botão**: Inicia a sequência de LEDs ao pressionar o botão.
- **Temporização one-shot**: Desliga os LEDs sequencialmente a cada 3 segundos.
- **Debounce por software**: Implementa uma atenuação de 50ms para o botão.
- **Bloqueio de interrupção**: Impede novos acionamentos durante a sequência.

## Circuito
| Componente  | GPIO do Pico W |
|-------------|----------------|
| LED Azul    | GPIO 11        |
| LED Vermelho| GPIO 12        |
| LED Verde   | GPIO 13        |
| Botão       | GPIO 5         |


## Componentes Necessários
- Raspberry Pi Pico W
- 3 LEDs (azul, vermelho, verde)
- 3 Resistores de 330Ω
- Botão pushbutton

## Configuração do Projeto

1. Clone este repositório para sua máquina:

   ```
   https://github.com/CarlosHenriqueSL/Projeto-06-07-EmbarcaTech.git
   cd Projeto-06-07-EmbarcaTech
   cd ProjetoOneShot
   
   ```

2. Certifique-se de que o **Pico SDK** está configurado no VS Code.

3. Abra o projeto no **VS Code** e configure os arquivos `CMakeLists.txt` adequados para compilar o código.

4. Execute o projeto no simulador **Wokwi** ou faça o upload para o hardware físico do Raspberry Pi Pico W.

### Principais Arquivos
- **`ProjetoOneShot.c:`** Contém a lógica principal para fazer a leitura do botão, o acionamento e o desligamento dos LEDs.
- **`diagram.json:`** Configuração física do projeto no simulador Wokwi.
- **`README.md:`** Documentação detalhada do projeto.


## Testes e Validação

1. Os LEDs devem estar todos desligados quando o sistema inicia.
  
2. Ao acionar o botão, todos os LEDs acendem, e devem desligar na seguinte ordem: Verde > Azul > Vermelho.

3. O sistema não deve aceitar novas leituras até que todos os LEDs estejam desligados novamente. 
