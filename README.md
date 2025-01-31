# Control de Motores DC con Arduino

Este proyecto implementa un sistema de control para dos motores DC usando Arduino, con indicadores LED para mostrar la dirección de movimiento de cada motor.

## Diseño en Proteus
El proyecto incluye un archivo de simulación en Proteus que contiene:
- Implementación del circuito completo
- Conexiones de los motores DC
- LEDs indicadores
- Arduino UNO
- Puente H para el control de los motores

Para utilizar la simulación:
1. Abrir el archivo `.pdsprj` en Proteus
2. Verificar que se tenga instalada la librería de Arduino en Proteus
3. Cargar el código `.hex` en el Arduino virtual
4. Ejecutar la simulación

## Configuración de Pines

### Motor 1
- **ENA (Pin 11)**: Control PWM de velocidad
- **IN1 (Pin 13)**: Control de dirección
- **IN2 (Pin 12)**: Control de dirección
- **LED1 (Pin 10)**: Indicador de movimiento hacia adelante
- **LED2 (Pin 9)**: Indicador de movimiento hacia atrás

### Motor 2
- **ENB (Pin 6)**: Control PWM de velocidad
- **IN3 (Pin 8)**: Control de dirección
- **IN4 (Pin 7)**: Control de dirección
- **LED3 (Pin 5)**: Indicador de movimiento hacia adelante
- **LED4 (Pin 4)**: Indicador de movimiento hacia atrás

## Parámetros de Tiempo y Velocidad

### Tiempos
- Movimiento hacia adelante: 2000ms (2 segundos)
- Tiempo en reposo: 3000ms (3 segundos)
- Movimiento hacia atrás: 2000ms (2 segundos)

### Velocidades
- Velocidad máxima (100%): 255 (PWM)
- Velocidad al 75%: 191 (PWM)

## Funcionamiento

El programa ejecuta una secuencia cíclica que consiste en:

1. **Movimiento hacia adelante**
   - Ambos motores al 100% de velocidad
   - Duración: 2 segundos
   - LEDs frontales encendidos

2. **Reposo**
   - Motores detenidos
   - Duración: 3 segundos
   - Todos los LEDs apagados

3. **Movimiento hacia atrás**
   - Ambos motores al 75% de velocidad
   - Duración: 2 segundos
   - LEDs traseros encendidos

4. **Reposo**
   - Motores detenidos
   - Duración: 3 segundos
   - Todos los LEDs apagados

## Funciones Principales

### `void setup()`
Configura todos los pines como salidas al inicio del programa.

### `void adelante()`
- Configura ambos motores para movimiento hacia adelante
- Establece velocidad al 100%
- Enciende LEDs frontales

### `void reposo()`
- Detiene ambos motores
- Apaga todos los LEDs

### `void atras()`
- Configura ambos motores para movimiento hacia atrás
- Establece velocidad al 75%
- Enciende LEDs traseros

### `void loop()`
Ejecuta la secuencia principal de manera continua:
1. Adelante → Reposo → Atrás → Reposo
2. Aplica los tiempos de espera correspondientes entre cada estado

## Licencia
Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

## Autor
[Pedro Carranza](https://github.com/draexx)
