#!/bin/bash


<<INSTRUCCIONES
Para correr: ./run_experiments.sh
INSTRUCCIONES

echo "EXPERIMENTOS CON HILOS"

isvalid=true
while [ $isvalid ] 
do
   # Entrada de datos para el experimento
   read -p "Ingrese el valor maximo del contador: " max_cnt
   read -p "Digite el numero de hilos: " num_threads
   ./main.out $max_cnt $num_threads

   # Se pregunta si se desea salir de la aplicacion
   read -r -p "Ejecutar otro experimento ('y'/'n'): " yes
   if [[ $yes =~ ^[nN] ]]; 
   then
      echo "Hasta pronto"
      break
   fi
done


<<REFERENCIAS
https://bioinf.comav.upv.es/courses/unix/scripts_bash.html
https://www.hostinger.co/tutoriales/bash-script-linux/
https://linuxconfig.org/bash-scripting-tutorial
https://www.computerhope.com/unix/bash/read.htm
https://www.golinuxcloud.com/check-if-string-contains-numbers-shell-script/
REFERENCIAS