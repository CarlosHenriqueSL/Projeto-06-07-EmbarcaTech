# Unidade 4 - Atividade 1: Semáforo com Temporizador Periódico

Implementação de um semáforo utilizando o Raspberry Pi Pico W, com temporização de 3 segundos entre as mudanças de estado.

---

## 🚦 Descrição
Este projeto simula o funcionamento de um semáforo utilizando três LEDs (vermelho, amarelo e verde) e um temporizador periódico. A sequência de operação é:
1. **Vermelho ligado** (3 segundos)
2. **Amarelo ligado** (3 segundos)
3. **Verde ligado** (3 segundos)

O ciclo se repete indefinidamente, enquanto o programa imprime mensagens de status pela porta serial a cada segundo.

---

## 📋 Funcionalidades
| Função | Implementação |
|-----------|---------------|
| **Início no vermelho** | Configuração inicial no estado vermelho |
| **Temporização de 3s** | Uso de `add_repeating_timer_ms(3000)` |
| **Mudança no callback** | Lógica implementada em `repeating_timer_callback()` |
| **Logs por serial** | Mensagens impressas a cada 1 segundo no loop principal |
| **Simulação no BitDogLab** | Compatível com GPIOs 11, 12 e 13 |

---

## 🛠 Componentes Necessários
- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo, verde)
- 3 Resistores de 330 Ω
- **Ferramenta de Simulação:** Simulador Wokwi

---


