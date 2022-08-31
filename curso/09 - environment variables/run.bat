set CONTAINER_NAME=docker_envs
set IMAGE_VERSION=V1
docker rm -f %CONTAINER_NAME%

docker rmi -f %CONTAINER_NAME%

docker build -t %CONTAINER_NAME%:%IMAGE_VERSION% .

REM Passing environment variables through "-e" command.
docker run -d -p 80:80 --name %CONTAINER_NAME% -e "test=123456" -e "MY_ENV=321" %CONTAINER_NAME%:%IMAGE_VERSION%