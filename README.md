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
## Imagenes del Pacman
Pacman es el protagonista principal y el personaje que el jugador controla. Es un cubo amarilla con una apariencia amigable. Su objetivo es moverse a través del laberinto para recolectar todas las monedas doradas mientras evita ser atrapado por los monstruos. Cuando Pacman consume una fruta, experimenta un crecimiento temporal durante 5 segundos, lo que le otorga la capacidad de devorar a los monstruos.

  <img src="https://github.com/Ronald-Gutierrez/Pacman-CG/blob/main/Img/pacman.jpeg" alt="Imagen 1" width="300" height="300" style="float: left; margin-right: 20px;">
## Imagenes del Fantasta y fruta
Los monstruos son enemigos que persiguen a Pacman a medida que se mueve por el laberinto. Se mueven en líneas rectas en dirección vertical u horizontal, y su apariencia puede variar según tu diseño. Cuando Pacman es de tamaño normal, no puede tocar a los monstruos. Sin embargo, cuando Pacman consume una fruta y crece en tamaño, los roles se invierten, y los monstruos huirán de Pacman durante el período de crecimiento.

  <img src="https://github.com/Ronald-Gutierrez/Pacman-CG/blob/main/Img/monstro_fruta.jpg" alt="Imagen 1" width="300" height="300" style="float: left; margin-right: 20px;">

##Vistas del Juego
El laberinto es el entorno en el que se desarrolla el juego. Está compuesto por pasillos, paredes y esquinas que Pacman debe navegar para recolectar todas las monedas doradas. El laberinto puede tener un diseño único y desafiante, con múltiples caminos y obstáculos para crear un juego emocionante. Los laberintos pueden variar en forma y tamaño a medida que los niveles avanzan, lo que brinda diversidad y dificultad creciente al juego. Por lo que se han añadido diferentes vistas del personaje, para variar la jugabilidad.

### Vista Izquierda

  <img src="https://github.com/Ronald-Gutierrez/Pacman-CG/blob/main/Img/vista_izq.jpg" alt="Imagen 1" width="300" height="300" style="float: left; margin-right: 20px;">
  
### Vista Derecha
  <img src="https://github.com/Ronald-Gutierrez/Pacman-CG/blob/main/Img/vista_der.jpg" alt="Imagen 1" width="300" height="300" style="float: left; margin-right: 20px;">

### Vista Delantera y Trasera
  <img src="https://github.com/Ronald-Gutierrez/Pacman-CG/blob/main/Img/vista_delante_atras.jpg" alt="Imagen 1" width="300" height="300" style="float: left; margin-right: 20px;">

## Imagenes del Mapa
### Nivel 01
#### Mapa 1 y 2

<div>
  <img src="https://github.com/Ronald-Gutierrez/Pacman-CG/blob/main/Img/map1.jpg" alt="Imagen 1" width="300" height="300" style="float: left; margin-right: 20px;">
  <img src="https://github.com/Ronald-Gutierrez/Pacman-CG/blob/main/Img/map2.jpg" alt="Imagen 2" width="300" height="300" style="float: left;">
</div>

Disfruta del juego y desafía tus habilidades para completar los niveles y alcanzar la puntuación más alta.
### 🔩COLABORADORES🔩
<a href="https://github.com/Ronald-Gutierrez">
    <img src="https://avatars.githubusercontent.com/u/113565299?v=4" width="50px">
</a>
Gutierrez Arratia Ronald Romario
<br>
<a href="https://github.com/John-Sanchez-Chilo">
    <img src="https://avatars.githubusercontent.com/u/82964968?v=4" width="50px">
</a>
Jhon Edson Sanchez Chilo
<br>

¡Las contribuciones a este proyecto son bienvenidas! Si tienes alguna idea de mejora, corrección de errores o nuevas características, no dudes en hacer una solicitud de extracción o abrir un probl

