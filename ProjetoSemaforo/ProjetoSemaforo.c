#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

void iniciar(){

    gpio_init(LED_PIN_RED);
    gpio_init(LED_PIN_YELLOW);
    gpio_init(LED_PIN_GREEN);

    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    gpio_put(LED_PIN_RED, 1);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN, 0);
    
}

bool repeating_timer_callback(struct repeating_timer *t) {
    static int estado_atual = 0;

    // Desliga o LED atual
    switch(estado_atual) {
        case 0:
            gpio_put(LED_PIN_RED, 0);
            break;
        case 1:
            gpio_put(LED_PIN_YELLOW, 0);
            break;
        case 2:
            gpio_put(LED_PIN_GREEN, 0);
            break;
    }

    // Avança para o próximo estado
    estado_atual = (estado_atual + 1) % 3;

    // Liga o próximo LED
    switch(estado_atual) {
        case 0:
            gpio_put(LED_PIN_RED, 1);
            break;
        case 1:
            gpio_put(LED_PIN_YELLOW, 1);
            break;
        case 2:
            gpio_put(LED_PIN_GREEN, 1);
            break;
    }

    return true;
}

int main()
{
    stdio_init_all();

    iniciar();

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while(true){
        static int segundos = 1;
        sleep_ms(1000);
        if (segundos == 1){
            printf("1 segundo se passou...\n");
        } else {
            printf("%d segundos se passaram..\n", segundos);
        }
        segundos++;
    }

}
