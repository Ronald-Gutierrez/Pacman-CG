# Pacman 3D - Juego en OpenGL y C++

Este proyecto es un emocionante juego de Pacman en 3D desarrollado en C++ utilizando la biblioteca OpenGL. El objetivo del juego es guiar al Pacman a través de un laberinto, comer todas las bolitas y evitar ser capturado por los fantasmas. Sin embargo, esta versión del clásico juego de Pacman tiene una interesante mecánica adicional.

## Mecánica del juego

Una característica única de este juego es la capacidad del Pacman de crecer de tamaño cuando come una fruta especial. Cada vez que el Pacman se alimenta de una fruta, experimentará un cambio de escala y se volverá más grande. Después de un cierto período de tiempo, volverá a su tamaño original. Este aspecto añade un elemento estratégico adicional al juego, ya que el jugador debe aprovechar el tiempo en que el Pacman es más grande para comer más bolitas y ganar puntos adicionales.

## Niveles y mapas

El juego consta de 2 niveles emocionantes. Cada nivel presenta un desafío único y aumenta en dificultad a medida que avanzas. En cada nivel, tendrás que enfrentarte a dos mapas diferentes, cada uno con su propio laberinto lleno de monedas, fantasmas y frutas. Deberás explorar cuidadosamente los mapas, planificar tus movimientos y evitar a los fantasmas para completar cada nivel con éxito.

## Requisitos del sistema

Antes de ejecutar el juego, asegúrate de cumplir con los siguientes requisitos del sistema:

- Sistema operativo: Windows, Linux o macOS
- Compilador de C++ compatible con el estándar C++17
- Biblioteca OpenGL y sus dependencias correctamente instaladas

## Instrucciones de compilación y ejecución

Para compilar y ejecutar el juego, sigue estos pasos:

1. Clona el repositorio desde https://github.com/Ronald-Gutierrez/Pacman-CG.git
2. Asegúrate de que las dependencias requeridas estén correctamente configuradas en tu entorno de desarrollo.
3. Abre una terminal y navega al directorio del proyecto.
4. Ejecuta el siguiente comando para compilar el código fuente:

```shell
g++ -g --std=c++17 -I../include -L../lib ../src/*.cpp ../src/glad.c -lglfw3dll -o main
```
### Una vez compilado con éxito, ejecuta el siguiente comando para iniciar el juego:
```shell
./main
```
## Imagenes del Mapa
### Nivel 01
#### Mapa 1 y 2

<div>
  <img src="https://github.com/Ronald-Gutierrez/Pacman-3D/blob/main/img/Nivel01-map1.jpg" alt="Imagen 1" width="300" height="300" style="float: left; margin-right: 20px;">
  <img src="https://github.com/Ronald-Gutierrez/Pacman-3D/blob/main/img/Nivel01-map2.jpg" alt="Imagen 2" width="300" height="300" style="float: left;">
</div>

Disfruta del juego y desafía tus habilidades para completar los niveles y alcanzar la puntuación más alta.
## Contribuciones
¡Las contribuciones a este proyecto son bienvenidas! Si tienes alguna idea de mejora, corrección de errores o nuevas características, no dudes en hacer una solicitud de extracción o abrir un probl
