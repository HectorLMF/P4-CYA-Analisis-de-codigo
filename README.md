# Análisis de Código C++ con Expresiones Regulares

## Descripción del Programa

Se desarrollará un programa en C++ que analice el contenido de ficheros de código, utilizando expresiones regulares. El programa recibirá por línea de comandos el nombre del fichero de entrada y el nombre del fichero de salida, siguiendo el siguiente formato:

./p04_code_analyzer code.cc codescheme.txt


En caso de ejecutarse sin parámetros, el programa mostrará un mensaje de error indicando el modo correcto de ejecución, incluyendo los parámetros necesarios y su significado.

## Funcionalidades

El programa analizará un fichero de código C++ sintácticamente correcto, y generará un fichero de salida que resumirá la estructura del código. El fichero de salida incluirá la siguiente información:

1. **Declaraciones de Variables**:
   - Se detectarán declaraciones de variables de tipo `int` y `double`.
   - Cada declaración de variable se hará en una única línea.
   - Se almacenará:
     - Tipo de variable
     - Nombre de la variable
     - Línea en la que se declara
     - Si ha sido inicializada o no
   - Se llevará un control de cuántas variables de cada tipo se han definido.

2. **Utilización de Bucles**:
   - Se detectarán bucles de tipo `for` y `while`.
   - Para cada bucle detectado se almacenará:
     - Tipo de bucle
     - Línea en la que se ha encontrado
   - Se llevará un control del número de bucles de cada tipo utilizados.

3. **Programa Principal**:
   - Se detectará la existencia de una función `main` en el código fuente analizado.

4. **Comentarios**:
   - Se detectarán todos los comentarios de una línea (`//`) y de múltiples líneas (`/* */`).
   - Se almacenará:
     - Tipo de comentario
     - Línea/s en la que se encuentra cada comentario
     - Contenido del comentario
   - Si al comienzo del fichero se encuentra un comentario, este se tomará como la descripción del programa.

## Estructura del Programa

El fichero de salida no se creará directamente mientras se analiza el fichero de entrada. En su lugar, se creará al menos una clase que represente y almacene la estructura general del código C++ analizado.
