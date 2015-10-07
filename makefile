ALL: tarea3

.PHONY= clean

clean:
	@echo "Borrando ejecutable"
	\rm -f tarea3

tarea3:main.cpp
	g++ -std=c++11 main.cpp -o tarea3
