docker rm -f hello-world-c
docker rmi -f helloworldc:v1

cls

docker build -t helloworldc:v1 --build-arg FILE="helloworld.c" .

docker run --name hello-world-c helloworldc:v1