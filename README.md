<img src="https://raw.githubusercontent.com/JaeSeoKim/badge42/main/public/badge42_logo.svg" width ="10%"/>
<h1 align="center">
	So long
</h1>

<p align="center">
	<b><i>Development repo for 42 projects</i></b><br>

---
Este proyecto es un pequeño juego en 2D. Está diseñado para hacerte
trabajar con texturas y sprites y algunos otros elementos básicos de jugabilidad.

Para compilar nuestro programa con la minilibX: gcc main.c -lmlx -framework OpenGL -framework AppKit.

ERRORES

Comprobaciones a tener en cuenta de cara a la corrección:

• Mapa vacío <br>
• Archivo .ber <br>
• Permisos de archivo  <br>
• Colleccionable detras de la puerta <br>
• Ruta valida <br>
• Acceso a todos los coleccionables <br>
• Mapa rectangular <br>
• Que exista el archivo <br>

Para comprobar los leaks tambien puedes:  ps -ax | grep so_long que te dara el numero de proceso del programa y luego ejecutar leaks numero de programa, mientras se esta ejecutando.