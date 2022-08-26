SET CONTAINER_NAME=nginx-teste

cls

docker stop %CONTAINER_NAME%:v1
docker rm %CONTAINER_NAME%
docker rmi -f %CONTAINER_NAME%:v1

docker build -t %CONTAINER_NAME%:v1 .

docker run -d -p 80:80 --name %CONTAINER_NAME% %CONTAINER_NAME%:v1
