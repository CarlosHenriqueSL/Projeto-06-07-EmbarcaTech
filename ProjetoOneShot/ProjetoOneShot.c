#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN_BLUE 11
#define LED_PIN_RED 12
#define LED_PIN_GREEN 13
#define BUTTON_PIN 5

bool all_led_active = false; // Indica se todos os LEDs estão ligados
int led_state = 0;           // Controla o estado atual dos LEDs (0: todos ligados, 1: azul desligado, 2: azul e vermelho desligados, 3: todos desligados)

// Função para inicializar os LEDs e o botão
void iniciar() {
    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_BLUE);
    gpio_init(LED_PIN_GREEN);

    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}

// Callback do alarme para desligar os LEDs sequencialmente
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    switch (led_state) {
        case 0:
            gpio_put(LED_PIN_BLUE, 0); // Desliga o LED azul
            led_state = 1;
            break;
        case 1:
            gpio_put(LED_PIN_RED, 0); // Desliga o LED vermelho
            led_state = 2;
            break;
        case 2:
            gpio_put(LED_PIN_GREEN, 0); // Desliga o LED verde
            led_state = 3;
            all_led_active = false; // Todos os LEDs estão desligados
            break;
    }

    // Se ainda há LEDs para desligar, programa o próximo alarme
    if (led_state < 3) {
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }

    return 0; // Retorna 0 para indicar que o alarme não deve se repetir
}

int main() {
    stdio_init_all();
    iniciar();

    while (true) {
        // Verifica se o botão foi pressionado e se os LEDs não estão ativos
        if (gpio_get(BUTTON_PIN) == 0 && !all_led_active) {
            sleep_ms(50); // Debounce do botão
            if (gpio_get(BUTTON_PIN) == 0) {
                // Liga todos os LEDs
                gpio_put(LED_PIN_BLUE, 1);
                gpio_put(LED_PIN_RED, 1);
                gpio_put(LED_PIN_GREEN, 1);

                all_led_active = true; // Indica que os LEDs estão ativos
                led_state = 0;         // Reinicia o estado dos LEDs

                // Programa o primeiro alarme para desligar um LED após 3 segundos
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }
        sleep_ms(10);
    }
}