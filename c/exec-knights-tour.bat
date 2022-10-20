docker rm -f knights-tour

docker rmi -f knights-tour:v1

cls

docker build -t knights-tour:v1 --build-arg FILE="knights-tour.c" .

docker run -ti --name knights-tour knights-tour:v1
