echo Compiling Files
g++ -c main.cpp
g++ -c Player.cpp
g++ -c Object.cpp

echo Creating O File with SFML librarys compiled with it
g++ main.o -o Game -lsfml-graphics -lsfml-window -lsfml-system

echo Running Game
./Game