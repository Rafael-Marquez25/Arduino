# Práctica 4 Construccion de un encoder usando un sensor optico.

### Rafael Márquez e Illan Garcia

## Objetivo de la practica.
El objetivo de la práctica es construir un encoder óptico que permita medir la velocidad angular. Para ello, se utiliza un optointerruptor junto con un disco con muescas, el que interrumpe periódicamente el haz de luz emitido por el sensor. Mediante la lectura del tren de pulsos generado y el uso de interrupciones en el microcontrolador, se pueden contar los cambios de estado y calcular las revoluciones por minuto (rpm). 

## Resumen del trabajo realizado
En esta práctica hemos desarrollado un sistema para medir la velocidad angular de un eje utilizando un encoder óptico. Se implementó un código en que emplea interrupciones externas para detectar los pulsos generados cuando las muescas del disco interrumpen el haz de luz del sensor. 

Durante un periodo de 5 segundos, el programa cuenta los pulsos y calcula las revoluciones por minuto (RPM) aplicando la relación entre pulsos, ranuras y tiempo de medición. Finalmente, el valor obtenido se muestra por el monitor serie, permitiendo observar el comportamiento del encoder en tiempo real y verificar su correcto funcionamiento.

## Particularidades: Problemas encontrados, funcionalidad extra.
En esta la práctica se presentaron algunas dificultades durante el montaje del circuito ya que teniamos que enterder el esquema de conexion mediante la datasheet. En cuanto al codigo estubieron relacionados con la lectura estable de los pulsos del encoder y la correcta sincronización del tiempo de medición.

Además, se implementó una funcionalidad extra que añade un botón de inicio para comenzar la medición de forma manual, mejorando la usabilidad del sistema. Esta mejora permite realizar lecturas más controladas y precisas, facilitando la repetición de pruebas.

## Video del funcionamiento.

[Video funcionamiento ejercicio 1.](https://drive.google.com/file/d/1jc8Jc-SsOOLDFyJGi2xAqcykHNjP_TB6/view?usp=drive_link)

[Video funcionalidad extra.](https://drive.google.com/file/d/12Jbo7XnUDIBxOd0nuRN_-oYq7mW-42Bh/view?usp=drive_link)

## Esquemático del circuito.
Esquema del circuito ejercicio 1.
![Esquema del circuito ejercicio 1.](/img/ejercicio_1.png)

Esquema del circuito funcionalidad extra.
![Esquema del circuito ejercicio 1.](/img/funcionalidad_extra.png)