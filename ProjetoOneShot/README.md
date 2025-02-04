# Unidade 4 - Atividade 2: Temporizador One Shot com LEDs e Botão

Este projeto implementa um sistema de temporização one-shot para controle de três LEDs (azul, vermelho e verde) usando um botão pushbutton.

## 📋 Componentes Necessários
- Raspberry Pi Pico W
- 3 LEDs (azul, vermelho, verde)
- 3 Resistores de 330Ω
- Botão pushbutton

## 🛠 Funcionalidades
- **Acionamento por botão**: Inicia a sequência de LEDs ao pressionar o botão.
- **Temporização one-shot**: Desliga os LEDs sequencialmente a cada 3 segundos.
- **Debounce por software**: Implementa uma atenuação de 50ms para o botão.
- **Bloqueio de interrupção**: Impede novos acionamentos durante a sequência.

## 🔌 Circuito
| Componente  | GPIO do Pico W |
|-------------|----------------|
| LED Azul    | GPIO 11        |
| LED Vermelho| GPIO 12        |
| LED Verde   | GPIO 13        |
| Botão       | GPIO 5         |

## ⚙️ Lógica de Operação
1. **Estado Inicial**: Todos os LEDs desligados.
2. **Pressionar Botão**:
   - Liga todos os LEDs (nível alto)
   - Inicia temporizador de 3s
3. **Sequência de Desligamento**:
   - 3s: Desliga LED Azul
   - 6s: Desliga LED Vermelho
   - 9s: Desliga LED Verde
   - 12s: Sistema liberado para novo acionamento
