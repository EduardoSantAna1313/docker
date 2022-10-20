docker rm arrays

docker rmi -f arrays:v1

cls

docker build -t arrays:v1 --build-arg FILE="arrays.c" .

docker run -ti --name arrays arrays:v1