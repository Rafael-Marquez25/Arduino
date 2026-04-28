# Práctica 3: Uso de interrupciones para leer valores de un boton.

### Rafael Márquez e Illan García.

## Objetivo de la práctica
El objetivo de la práctica es principalmente aprender a usar un botón, primero haciendo uso de interrupciones para no tener que estar comprobando continuamente el estado del mismo. Además, se trabaja con la configuración de resistencias pull-up y pull-down, ya sea mediante Arduino o resistencias externas.
Posteriormente, se debía mitigar el problema del rebote y aplicar estas técnicas para lograr un sistema con dos botones y dos LEDs independientes.

## Resumen del trabajo realizado
En el primer apartado teníamos que mitigar el problema del rebote de la señal. Para ello, montamos el circuito sin el antirrebote por hardware y medimos los tiempos entre pulsaciones.
Luego intentamos generar señales más continuas entre pulsaciones y comprobamos que el tiempo más rápido entre pulsaciones que podíamos realizar era de 201 ms, por lo que definimos un retardo de lectura de 250 ms para evitar errores por rebote.

En el segundo apartado se nos pedía implementar dos botones y dos LEDs que funcionasen de forma independiente, de manera que al pulsar un botón se encendiera su LED asociado, y al volver a pulsarlo se apagara. Para conseguir esto, montamos el circuito e implementamos los tres ficheros correspondientes: el primero sin antirrebote ni interrupciones, el segundo sin antirrebote pero con interrupciones, y el tercero con antirrebote e interrupciones.

## Problemas encontrados y funcionalidad extra
Los problemas que encontramos en esta práctica fueron más numerosos que en las anteriores. Primero, aunque pueda parecer algo básico, durante el montaje del circuito algo no funcionaba, y descubrimos que la protoboard se divide en dos y la mitad de la fila del positivo y del negativo no estaban conectadas.
Luego tuvimos varios problemas al implementar la lógica del código, lo que nos obligó a probarlo varias veces hasta dar con una solución sólida.

Para la funcionalidad extra implementamos un sistema mediante el cual, cada vez que se pulsase el botón, el LED RGB cambiaba de color, realizando una secuencia de colores rojo-verde-azul sucesivamente. Para ello, simplemente tuvimos que modificar el código de los LEDs y la lógica de encendido.

## Video del funcionamiento.
[Video funcionamiento ejercicio 1.](https://drive.google.com/file/d/1AkuqSfplTGHpWeSdviVqvglcLr1z1ovs/view?usp=sharing)

[Video funcionamiento ejercicio 2.](https://drive.google.com/file/d/1hOtuDVsEAQ-1fIK6B08oF0pvnXfadJ5C/view?usp=drive_link)

[Video funcionamiento funcionalidad extra.](https://drive.google.com/file/d/1JRThxwqGGlZ0aP5hadufgZOUb1q-GzLN/view?usp=sharing)

## Esquematico del circuito .
Esquema del circuito ejercicio 1.
![Esquema del circuito ejercicio 1.](/img/esquematico_ejercicio_1.png)

Esquema del circuito ejercicio 2.
![Esquema del circuito ejercicio 2.](/img/esquematico_ejercicio_2.png)

Esquema del circuito funcionalidad extra.
![Esquema del circuito funcionalidad extra.](/img/esquematico_funcionalidad_extra.png)