Person: Person.cpp main-1-1.cpp
	g++ Person.cpp main-1-1.cpp -o person-1-1

Room: Room.cpp main-R.cpp
	g++ Room.cpp main-R.cpp -o room-1

Alice: Room.cpp Person.cpp Alice.cpp main-A.cpp
	g++ Room.cpp Person.cpp Alice.cpp main-A.cpp -o A-1

Puzzles: Room.cpp Person.cpp Puzzles.cpp main-2.cpp
	g++ Room.cpp Person.cpp Puzzles.cpp main-2.cpp -o 2-1

Sherlock: Room.cpp Person.cpp Sherlock.cpp main-3.cpp
	g++ Room.cpp Person.cpp Sherlock.cpp main-3.cpp -o 3-1


Final: Room.cpp Person.cpp Alice.cpp Puzzles.cpp Sherlock.cpp main.cpp
	g++ Room.cpp Person.cpp Alice.cpp Puzzles.cpp Sherlock.cpp main.cpp -o final

iotests1:
	./final < test-input-1.txt | diff - test-output-1.txt

iotests2:
	./final < test-input-2.txt | diff - test-output-2.txt

iotests3:
	./final < test-input-3.txt | diff - test-output-3.txt

