# Manejo de estructuras que usan loops #

## Fuentes de consulta ##
1. Material de clase (Videos y diapostivas).
2. Texto guia [**Operating Systems: Three Easy Pieces**](http://pages.cs.wisc.edu/~remzi/OSTEP/). Para desarrollar este laboratorio se recomienda tener a la mano el capitulo [Lock-based Concurrent Data Structures](http://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks-usage.pdf)

## Ejercicios ##

1. Consulte el uso de la función ```gettimeofday``` para medir el tiempo de ejecución de un programa
   * ¿Cómo se utiliza esta función (muestre un ejemplo)? 
   * ¿Cuál es el intervalo de tiempo más corto que se puede medir con esta función?
2. Crear un contador concurrente simple y mida cuánto tiempo lleva incrementar el contador muchas veces a medida que aumenta el número de hilos (1, 2, 4, 8, 16). Para tal fin, siga las instrucciones que aparecen en el directorio  [preciso](./preciso). Luego responda las siguientes preguntas.
3. Crear una versión del contador aproximado (sloppy counter) y mida su desempeño a medida que se varía el número de hilos, así como el umbral (S) siguiendo las instrucciones indicadas en el directorio [aproximado](./aproximado).  
4. Grafique los resultados obtenidos de las pruebas 1 y 2. Y responda las siguientes preguntas: 
   * Los valores siguen una tendencia como la que se muestra en el texto guía (cap. 29)?
   * ¿Cuántas CPU hay disponibles en el sistema que está utilizando?
   * ¿Este número afecta de alguna manera sus mediciones?

