all: build run

build: 
	g++ -I. -I./training -o neural-net  neural-net.cpp 
	g++ -I. -I./training -o training/generating/makeTrainingSamples training/generating/makeTrainingSamples.cpp 

run:
	./training/generating/makeTrainingSamples > out.txt
	./neural-net
