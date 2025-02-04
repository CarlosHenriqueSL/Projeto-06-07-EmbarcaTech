# Unidade 4 - Atividade 1: Semáforo com Temporizador Periódico

Implementação de um semáforo utilizando o Raspberry Pi Pico W, com temporização de 3 segundos entre as mudanças de estado.

---

## Aluno: 
- **Carlos Henrique Silva Lopes**

## Descrição do projeto
Este projeto simula o funcionamento de um semáforo utilizando três LEDs (vermelho, amarelo e verde) e um temporizador periódico. A sequência de operação é:
1. **Vermelho ligado** (3 segundos)
2. **Amarelo ligado** (3 segundos)
3. **Verde ligado** (3 segundos)

O ciclo se repete indefinidamente, enquanto o programa imprime mensagens de status pela porta serial a cada segundo.

---

## Funcionalidades
| Função | Implementação |
|-----------|---------------|
| **Início no vermelho** | Configuração inicial no estado vermelho |
| **Temporização de 3s** | Uso de `add_repeating_timer_ms(3000)` |
| **Mudança no callback** | Lógica implementada em `repeating_timer_callback()` |
| **Logs por serial** | Mensagens impressas a cada 1 segundo no loop principal |
| **Simulação na placa** | Compatível com GPIOs 11, 12 e 13 |

---

## Componentes Necessários
- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo, verde)
- 3 Resistores de 330 Ω
- **Ferramenta de Simulação:** Simulador Wokwi

---

## Configuração do Projeto

1. Clone este repositório para sua máquina:

   ```
   https://github.com/CarlosHenriqueSL/Projeto-06-07-EmbarcaTech.git
   cd Projeto-06-07-EmbarcaTech
   cd ProjetoSemaforo
   
   ```

2. Certifique-se de que o **Pico SDK** está configurado no VS Code.

3. Abra o projeto no **VS Code** e configure os arquivos `CMakeLists.txt` adequados para compilar o código.

4. Execute o projeto no simulador **Wokwi** ou faça o upload para o hardware físico do Raspberry Pi Pico W.


### Principais Arquivos
- **`ProjetoSemaforo.c:`** Contém a lógica principal para fazer os LED's acenderem e desligarem no tempo correto.
- **`diagram.json:`** Configuração física do projeto no simulador Wokwi.
- **`README.md:`** Documentação detalhada do projeto.


## Testes e Validação

1. O LED vermelho deve estar aceso no início da simulação.
  
2. A cada 3 segundos, um dos LEDs apagará e outro irá acender, na ordem: Vermelho > Amarelo > Verde.

3. É importante notar que, o código foi feito para ser testado, principalmente, no simulador Wokwi. Os pinos estão conectados da seguinte forma: Vermelho (11), Amarelo (12) e Verde (13), o que na placa, corresponde respectivamente à Verde (11), Azul (12) e Vermelho (13). 

