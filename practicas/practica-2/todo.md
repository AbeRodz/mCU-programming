Punto 1


En main.c se deben ubicar la implementación de todas las funciones:
Consideraciones para la implementación:
delayInit debe cargar el valor de duración del retardo en la estructura, en el campo correspondiente. No debe iniciar el conteo del retardo. Debe inicializar el flag running en `false´.
delayRead debe verificar el estado del flag running.
false, tomar marca de tiempo y cambiar running a ‘true’ 
true, hacer la cuenta para saber si el tiempo del retardo se cumplió o no:

‘marca de tiempo actual - marca de tiempo inicial es mayor o igual a duración del retardo’? 
devolver un valor booleano que indique si el tiempo se cumplió o no.
Cuando el tiempo se cumple se debe cambiar el flag running a false.
delayWrite debe permitir cambiar el tiempo de duración de un delay existente
