# 🎮 Monitoramento de Joystick com RP2040 e Display OLED

Este projeto foi desenvolvido como parte da atividade prática da disciplina **ELET0021 — Microcontroladores e Microprocessadores** da UNIVASF. Utilizando o microcontrolador **Raspberry Pi Pico W**, o sistema realiza a leitura do sinal analógico do eixo X de um joystick e exibe os valores de tensão em um display OLED via comunicação I2C.

---

## 🧰 Componentes Utilizados

- **Microcontrolador:** Raspberry Pi Pico W   
- **Joystick analógico:** Plugin 13x13mm Multi-Dir ROHS (conectado a GPIO27 e GPIO26)  
- **Display OLED:** 0,96" 128x64 pixels SSD1306 (conectado via I2C - GPIO14 SDA, GPIO15 SCL)  
- **Ambiente de desenvolvimento:** VS Code + Pico SDK + Wokwi  
- **Linguagem de programação:** C

---

## ⚙️ Funcionalidades Implementadas

- **Leitura Analógica do Joystick:**
  - Captura contínua da tensão do eixo X via ADC.
  - Conversão do valor bruto (0–4095) para tensão real (0.00V a 3.30V).
  - Amostragem a cada 500 ms.

- **Exibição no Display OLED:**
  - Inicialização e configuração do display SSD1306 via I2C.
  - Apresentação da tensão centralizada na tela.
  - Comunicação via barramento I2C utilizando os pinos GPIO14 (SDA) e GPIO15 (SCL).
  - Valor de tensão convertido é formatado com duas casas decimais

- **Organização do Projeto:**
  - Estrutura modular com bibliotecas separadas.
  - Repositório versionado no GitHub.
  - Arquivo `README.md` com instruções e documentação.
  - Vídeo explicativo com demonstração dos resultados.

---

## 👥 Organização da Equipe

- **Líder de Projeto:** [RYAN FARIAS] - responsável pelo gerenciamento do repositório, estrutura do código.
- **Desenvolvedor 1:** [JOÃO VICTOR GUIMARÃES] — responsável pela configuração do display.
- **Desenvolvedor 2:** [JOÃO VICTOR TEIXEIRA] — responsável por obter o valor do sinal no eixo x do joystick e integrar ao display.

---

## 📹 Vídeo de funcionamento

🔗 https://www.canva.com/design/DAGteoaReos/04EDM1Ie7Wre6VKfd4QBYw/edit?utm_content=DAGteoaReos&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton

---

## 📄 Licença

Este projeto é destinado exclusivamente para fins acadêmicos na disciplina **ELET0021 — Microcontroladores e Microprocessadores** da UNIVASF.

---
