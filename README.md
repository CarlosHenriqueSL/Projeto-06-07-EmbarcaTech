# Projeto 06-07 - EmbarcaTech

Este repositório reúne dois projetos desenvolvidos na Unidade 4, ambos utilizando o Raspberry Pi Pico W com o Pico SDK. Os projetos demonstram o uso de temporizadores para controle de LEDs e a implementação de lógicas embarcadas com interação via botões e sequências periódicas.

## Aluno
- Carlos Henrique Silva Lopes

---

## Visão Geral

Este repositório contém duas implementações distintas:

1. **Semáforo com Temporizador Periódico:**  
   Simula o funcionamento de um semáforo com três LEDs (vermelho, amarelo e verde) onde cada estado permanece ativo por 3 segundos. O programa também exibe logs de status pela porta serial a cada segundo.

2. **Temporizador One Shot com LEDs e Botão:**  
   Implementa um sistema de temporização one-shot que aciona três LEDs (azul, vermelho e verde) por meio de um botão pushbutton. Após a ativação, os LEDs se apagam sequencialmente a cada 3 segundos, e o sistema só aceita um novo acionamento quando todos os LEDs estão apagados.

---

## Projetos Incluídos

### Unidade 4 - Atividade 1: Semáforo com Temporizador Periódico

**Descrição do Projeto:**  
Este projeto simula um semáforo utilizando três LEDs e um temporizador periódico. A sequência de operação é:
1. **Vermelho ligado** (3 segundos)
2. **Amarelo ligado** (3 segundos)
3. **Verde ligado** (3 segundos)  

O ciclo se repete indefinidamente, com mensagens de status impressas na porta serial a cada segundo.

**Funcionalidades:**
- Início no estado vermelho.
- Temporização de 3 segundos entre as mudanças de estado (usando `add_repeating_timer_ms(3000)`).
- Lógica de mudança de estado implementada via callback `repeating_timer_callback()`.
- Logs de status pela porta serial.

**Componentes e Pinos (Simulação Wokwi):**
| Componente   | GPIO do Pico W |
|--------------|----------------|
| LED Vermelho | GPIO 11        |
| LED Amarelo  | GPIO 12        |
| LED Verde    | GPIO 13        |

**Principais Arquivos:**
- `ProjetoSemaforo.c` – Lógica principal do semáforo.
- `diagram.json` – Configuração física do projeto no simulador Wokwi.
- `README.md` – Documentação detalhada deste projeto.

---

### Unidade 4 - Atividade 2: Temporizador One Shot com LEDs e Botão

**Descrição do Projeto:**  
Este projeto utiliza um sistema de temporização one-shot para controlar três LEDs por meio de um botão pushbutton. Ao pressionar o botão, todos os LEDs acendem e, a cada 3 segundos, eles se apagam em uma ordem predefinida (Ordem de desligamento: Verde > Azul > Vermelho). Durante a sequência, novos acionamentos são bloqueados até que todos os LEDs estejam apagados.

**Funcionalidades:**
- Acionamento dos LEDs pelo botão.
- Desligamento sequencial dos LEDs a cada 3 segundos (temporização one-shot).
- Debounce por software (50ms).
- Bloqueio de novas leituras até o término da sequência.

**Componentes e Pinos (Simulação Wokwi):**
| Componente   | GPIO do Pico W |
|--------------|----------------|
| LED Azul     | GPIO 11        |
| LED Vermelho | GPIO 12        |
| LED Verde    | GPIO 13        |
| Botão        | GPIO 5         |

**Principais Arquivos:**
- `ProjetoOneShot.c` – Lógica principal do temporizador one-shot.
- `diagram.json` – Configuração física do projeto no simulador Wokwi.
- `README.md` – Documentação detalhada deste projeto.

---

## Componentes Necessários (para ambos os projetos)

- **Hardware:**
  - Raspberry Pi Pico W
  - 3 LEDs (os dois projetos utilizam três LEDs)
  - 3 Resistores de 330 Ω
  - Botão pushbutton (apenas no projeto One Shot)

- **Ferramenta de Simulação:**
  VsCode
  Simulador Wokwi (opcional para testes virtuais).

---

## Configuração do Ambiente

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/CarlosHenriqueSL/Projeto-06-07-EmbarcaTech.git
   cd Projeto-06-07-EmbarcaTech
   Configuração do Pico SDK:

2. **Configuração do Pico SDK:**
  Certifique-se de que o Pico SDK está configurado e instalado no VS Code ou em seu ambiente de desenvolvimento.
Verifique os arquivos CMakeLists.txt em cada pasta de projeto e ajuste-os se necessário para sua configuração.
Abrindo os Projetos:

3. **Abrindo os projetos:**
  Para o semáforo, navegue até a pasta ProjetoSemaforo:
  cd ProjetoSemaforo

  Para o temporizador one-shot, navegue até a pasta ProjetoOneShot:
  cd ProjetoOneShot

