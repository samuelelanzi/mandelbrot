# The Mandelbrot Set

>L'insieme di Mandelbrot o frattale di Mandelbrot è uno dei frattali più popolari;
>È l'insieme dei numeri complessi c per i quali la successione definita da: 
><img src="https://render.githubusercontent.com/render/math?math=z_0 = 0">
><img src="https://render.githubusercontent.com/render/math?math=z_{n %2B 1}=z_n^2 %2B c">
>è limitata.

## Compilazione ed Esecuzione
```
sudo apt-get install g++ libsfml-dev
cd mandelbrot/complexset
g++ -c mandelbrot_c.cpp
g++ mandelbrot.o -o mandelbrot -lsfml-graphics -lsfml-window -lsfml-system
./mandelbrot
```
## Risultati
![complexset](https://github.com/samuelelanzi/mandelbrot/blob/main/complexset/images/mandelbrot.png)
Nella figura e' rappresentato l'insieme di Mandelbrot ottenuto dal codice.
