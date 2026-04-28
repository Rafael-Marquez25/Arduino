# Práctica 9: Manejo de servo con retroalimentación posicional

### Rafael Márquez e Illan García

## Objetivo de la práctica
El objetivo de esta práctica es aprender a controlar un servo continuo con retroalimentación posicional, utilizando Arduino.

Se busca:
- Calibrar el servo para controlar el sentido y la velocidad de giro.
- Establecer una relación proporcional entre un comando de velocidad y el ancho de pulso PWM.
- Obtener una estimación aproximada de la posición angular.

## Resumen del trabajo realizado
La práctica se dividió en tres partes principales, correspondientes a los ejercicios propuestos.

En primer lugar, se realizó la calibración del servo, enviando distintos valores de ancho de pulso en microsegundos mediante el monitor serie. Esto permitió identificar la zona muerta del servo y los valores mínimos a partir de los cuales el motor comienza a girar en cada sentido. Se determinó que el servo permanece detenido en torno a los 1500 µs, comenzando a girar en sentido horario por debajo de 1453 µs y en sentido antihorario a partir de 1526 µs.

En la segunda parte, se implementó un sistema de control de velocidad en el que el usuario introduce un comando entre −100 y 100. Dicho comando se transforma mediante una relación lineal en un valor de ancho de pulso PWM, superando la zona muerta y manteniendo una proporcionalidad entre el valor introducido y la velocidad del servo. El signo del comando determina el sentido del giro.

Por último, se abordó la lectura de la posición angular del servo utilizando el pin de feedback. Para ello, se midió el ciclo de trabajo de la señal mediante la función pulseIn(). A partir del duty cycle obtenido, se calculó el ángulo del servo siguiendo los valores proporcionados por el fabricante. Se estimó la variación angular comparando la posición inicial y final tras aplicar una velocidad durante un tiempo fijo, obteniendo así una medición aproximada del desplazamiento angular.

## Problemas encontrados y funcionalidad extra
Durante la realización de la práctica, el principal reto fue el calibrado preciso del servo, ya que los valores de la zona muerta y de giro mínimo varían ligeramente entre dispositivos. Fue necesario realizar múltiples pruebas para ajustar correctamente las constantes de conversión entre comando y ancho de pulso.

## Video funcionamiento del ejercicio
[Video funcionamiento del ejercicio 1](https://drive.google.com/file/d/1VuwefIevAZEgoEJ0MIYmayXaK6RKq6jl/view?usp=sharing)

[Video funcionamiento del ejercicio 1 (segundo video)](https://drive.google.com/file/d/1MJDyic2-llvaDx2LOD21EHllfLEaliAA/view?usp=sharing)

[Video funcionamiento del ejercicio 2](https://drive.google.com/file/d/19GntXcgFhbX8-TEO3NQs2U07Qi1kJYGI/view?usp=sharing)

[Video funcionamiento del ejercicio 3](https://drive.google.com/file/d/1LGHILcU6exsSs1UemPEXc3dTTCl73PYM/view?usp=sharing)

## Esquemático del circuito
Esquema del circuito del ejercicio 1 y 2.  
![Esquema del circuito ejercicio 1 y 2.](/img/esquematico_ejercicio_1_2.png)

Esquema del circuito del ejercicio 3.  
![Esquema del circuito ejercicio 3.](/img/esquematico_ejercicio3.png)
Nota: en Fritzing no habia un sevor con feedback asi que se representa con el cable azul del esquematico aunque el servo no tenga ese pin.
