// Inclusão das bibliotecas necessárias
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "lib/ssd1306.h"
#include "lib/font.h"

// Definições dos pinos e periféricos
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define DISPLAY_ADDR 0x3C
#define VRX_PIN 27 // Eixo X do joystick (ADC1)

ssd1306_t display; // Estrutura de configuração do display

// Inicialização do display OLED via I2C
void setup_display() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init(&display, WIDTH, HEIGHT, false, DISPLAY_ADDR, I2C_PORT);
    ssd1306_config(&display);
    ssd1306_fill(&display, false);
    ssd1306_send_data(&display);
}

// Função principal
int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(VRX_PIN);
    adc_select_input(1); // Canal ADC1 para o eixo X

    setup_display(); // Inicializa o display OLED

    char buffer[32]; // Buffer para armazenar a string da tensão

    while (true) {
        uint16_t raw = adc_read(); // Leitura bruta do ADC (0–4095)
        float voltage = raw * 3.3f / 4095; // Conversão para tensão (0–3.3V)

        snprintf(buffer, sizeof(buffer), "%.2f V", voltage); // Formata a tensão

        // Centraliza o texto no display
        int char_width = 8;
        int str_len = strlen(buffer);
        int total_width = str_len * char_width;
        int x = (128 - total_width) / 2;
        int y = (64 - 8) / 2;

        ssd1306_fill(&display, false); // Limpa a tela
        ssd1306_draw_string(&display, buffer, x, y); // Desenha a tensão
        ssd1306_send_data(&display); // Atualiza o display

        sleep_ms(500); // Tempo de amostragem: 500 ms
    }
}
