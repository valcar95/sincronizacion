# Listas enlazadas concurrentes #

## Antes de empezar ## 

Se recomienda que lea, entienda y codifique el codigo de las listas enlazadas concurrentes (sección [Lock-based Concurrent Data Structures](http://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks-usage.pdf) del texto guia). Luego, lea el problema y a partir de lo que se solicita empieze a modificar el codigo ejemplo del libro.

## Aplicacion - biblioteca ##

La empresa **ACME** en la cual usted labora ha ganado una licitación para el desarrollo de un software para la gestion de materiabl bibliografico en una biblioteca. 

![biblioteca](biblioteca.jpg)

En el momento se encuentran haciendo las pruebas de la funcionalidad de prestamo de libros. La idea es permitir que hayan 4 puestos de atención de prestamo de material que funcionen de manera simultanea sin que los datos de información del inventario se corrompan. 

La información que se  va a almacenar por cada libro será:
1. **id**: Identificador del libro.
2. **name**: Nombre del libro.
3. **num_pages**: Numero de paginas del libro.
4. **pub_year**: Año de publicación.

Para la prueba se llevaron a cabo las siguientes etapas:
1. **Inicialización de la lista con la información de los libros**: Para las pruebas se crea una lista de 10000 libros en la cual los campos **num_pages** y **pub_year** serán los mismos (por ejemplo 100 y "2020"); sin embargo, **id** (entre "0" y "9999") y el **name** (desde "book_0" hasta "book_999") van a variar. 
2. **Simulación de los prestamos**: Para el prestamo se van a simular 4 prestamos de atención. Cada uno de los cuales podra acceder a la lista de libros del creada en la etapa 1; sin embargo, solo se van a manejar 1000 prestamos por oficina de presamos. Para tal fin; cada vez que se vaya a simular un prestamo se deberá generar un número aleatorio para el **id** (para lo cual se recomienda que use ```rand_r``` (ademas no olvide inicializar la semilla aleatoria cada estación de prestamo). Si el **id** generado esta disponible dentro de la lista de libros se procede a realizar el prestamo y se actualiza esta, si no se encuentra dentro de la lista, significa que el ejemplar ya fue prestado. En todo caso, la oficina deberá llevar un registro de cuantos cuantos prestamos fueron exitosos y cuantos fallaron (para propositos de test) y mostrarlo en pantalla.
3. **Desplique de resultados**: Finalmente, el programa debera desplegar, el numero total de prestamos realizados con exito, el numero total de prestamos que fallaron y el numero de libros disponibles.
4. **Medición del tiempo de ejecución de la aplicacion**: Un vez ya se encuentre todo lo anterior listo proceda a medir el tiempo llevado a cabo para los prestamos.

Un posible ejemplo de una salida en la cual se muestra una aplicación se muestra a continuación:

```
Initializing list of available books
my id 0, my seed 2058611624 
my id 1, my seed 1662376139 
my id 2, my seed 235467922 
my id 3, my seed 788003183 
Office 2 has finished its workload, successful loans 866, failed loans 134
Office 0 has finished its workload, successful loans 790, failed loans 210
Office 3 has finished its workload, successful loans 887, failed loans 113
Office 1 has finished its workload, successful loans 759, failed loans 241
Simulation done! execution time: 341.08 ms
Total successful loans 3302, total failed loans 698
Number of remaining available books 6698
```


 





