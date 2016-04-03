# Cyber  :octocat:  :rocket:
Programa desarrollado en C++ aplicación de consola Win32.

## Descripción del problema solicitado

 :eyeglasses:
La biblioteca del estado abrirá un centro de cómputo público :computer:, el cual **contará con 20 máquinas** que podrán ser usadas por cualquier persona que se identifique mediante su nombre. Aunque el **uso de las computadoras está limitado a 50 minutos por persona, el sistema no validará por el momento dichos tiempos, pero sí cuando ya no haya máquinas disponibles.**

Cuando una persona quiera hacer uso de una PC el sistema solicitará su nombre y, si hay máquina disponible, **le asignará una aleatoriamente (número aleatorio entre 1 y 20, sin repetir).**

**_El sistema mantendrá la información del uso de las máquinas mediante una estructura de lista enlazada simple._** Por ejemplo, si en algún momento dado hay ocupadas 3 máquinas.

El usuario con Nombre  "Ángel Guerrero" tiene ocupada la máquina 4
la persona "Wendy Argente" la máquina 8, y así sucesivamente.

El sistema mostrará un menú con las siguientes opciones:

1. Usar computadora
2. Dejar computadora
3. Cambiar usuario de computadora
4. Mostrar usuarios
5. Guardar registro de uso
6. Mostrar registro de uso
7. Salir

### La opción 1
Tendrá la siguiente interacción con el usuario.

1. Introduce tu nombre: "Ángel Guerrero"
2. La máquina asignada es: 5	(recuerde que este número se generará aleatoriamente)
(o en su defecto mostraría el mensaje: “Ya no hay máquinas disponibles!”).

### La opción 2
Tendrá la siguiente interacción en pantalla.

1. Introduce el número de computadora a dejar: 4
2. A lo cual deberá mostrar “La máquina 4 ha sido liberada!”, o en su defecto “Error, la máquina 4 no está siendo usada, verifique.”

### La opción 3
Se usará cuando por alguna razón especial, por ejemplo, si una máquina que está siendo usada falla.

Su interacción será como sigue:

1. Introduce la máquina usada: 4
2. La nueva máquina asignada es: 9		(recuerde que este número se generará aleatoriamente)
3. Ahora el usuario "Ángel Guerrero" está usando la máquina 9

### La opción 4
Mostrará la lista de computadoras que están siendo usadas en un momento dado, por ejemplo, para la lista de arriba se mostraría:

```
Computadora	    Usuario
===========   ==================
     4     -> Ángel Guerrero
     8     -> Wendy Argente
     1     -> Mariela Sotelo
```

### La opción 5
Guardará un registro de las máquinas que están siendo usadas al momento de seleccionar dicha opción. Cada vez que se seleccione se guardará en un archivo la información de todas las máquinas que están siendo usadas.

### Usando la opción 6
se verá como sigue:

```
20-03-2015 10:15 am
Computadora		Usuario
==========		========
4			   ->    Ángel Guerrero
8			   ->    Wendy Argente
1			   ->    Mariela Sotelo


20-03-2015 11:44 am
Computadora		Usuario
==========		========
8			Wendy Argente
1			Mariela Sotelo
```
