# Practica 1
# Introducción al Arduino y al mecanismo PWM para modular una señal digital (LED)
### Elaborado por Rafael Márquez e Illán García

## Objetivo de la practica.
El objetivo de esta práctica es iniciarnos en el uso de la placa Arduino y comprender la modulación por ancho de pulso (PWM) para controlar dispositivos electrónicos, en este caso un LED. A través del montaje del circuito y su programación en el entorno de Arduino, buscamos familiarizarnos con la estructura y funcionamiento de la placa, practicar el uso de funciones básicas como `setup()`, `loop()`, `digitalWrite()` y `analogWrite()`, y aprender a realizar conexiones correctas que protejan los componentes. Esto nos permite dar un primer paso en la integración entre software y hardware, sentando las bases para el desarrollo de proyectos más complejos.

## Resumen del trabajo realizado.
En primer lugar, configuramos el IDE de Arduino e identificamos los distintos pines y componentes de la placa. Posteriormente, montamos un circuito sencillo formado por un LED y una resistencia, teniendo en cuenta la polaridad del diodo y la correcta conexión a tierra. A nivel de programación, comenzamos controlando el encendido y apagado del LED con la función `digitalWrite()`, y más adelante implementamos la técnica de modulación por ancho de pulso (PWM) mediante la función `analogWrite()`, lo que nos permitió variar la intensidad de la luz. Finalmente, modificamos el programa para conseguir un efecto de desvanecimiento gradual, incrementando y disminuyendo el brillo del LED de manera continua, lo que nos permitió comprender mejor la relación entre el hardware y el software en el control de dispositivos electrónicos.

## Particularidades: Problemas encontrados y funcionalidad extra.
Durante la realización de la práctica nos encontramos con algunos problemas iniciales. En el montaje del circuito tuvimos que revisar varias veces la polaridad del LED y el valor de la resistencia. A nivel de programación, al principio surgieron errores por no declarar correctamente las variables constantes para los pines o por olvidar incluir la función `pinMode()` en el `setup()`, lo que impedía que el programa funcionara como esperábamos.

Como funcionalidad extra, ampliamos el ejercicio inicial de un único LED y desarrollamos un programa para controlar de forma escalonada cuatro LEDs conectados a los pines 9, 10, 11 y 12. Mediante bucles for y el uso de la función `analogWrite()`, conseguimos que los LEDs se encendieran y apagaran progresivamente con diferentes intensidades, generando un efecto visual.

## Video del funcionamiento del ejercicio.
[Enlace del video del ejercico (Google Drive)](https://drive.google.com/file/d/1TWaRmYdOd84UlLFJtN3LzW5YMZeP5Syr/view?usp=drive_link)

[Enlace del video de la funcionalidad extra (Google Drive)](https://drive.google.com/file/d/1vBfNnMyCpqYvT5SrDl0-2NaPHZGGB0fc/view?usp=drive_link)

## Esquema de los circuitos.
### Esquema Ejercicio.
![Esquema Ejercicio](/img/ejercicio.png)

### Esquema Funcionalidad Extra.
![Esquema Funcionalidad Extra](/img/funcionalidadExtra.png)
**Nota**: En el esquema hay 4 leds rojos a pesar de que  en la realidad son 2 rojos y 2 amarillos, esto se debe a que en el Fritzing no encontre los leds amarillos