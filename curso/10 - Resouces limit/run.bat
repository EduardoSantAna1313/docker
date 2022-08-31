SET CONTAINER_NAME=docker_limit_mem
SET IMAGE_VERSION=v1

docker rm -f %CONTAINER_NAME%
docker rmi -f %CONTAINER_NAME%:%IMAGE_VERSION%

docker build -t %CONTAINER_NAME%:%IMAGE_VERSION% --build-arg "project=app" .

docker run -d -p 8080:8080 --memory "25mb" --name %CONTAINER_NAME% %CONTAINER_NAME%:%IMAGE_VERSION%

docker stats %CONTAINER_NAME%