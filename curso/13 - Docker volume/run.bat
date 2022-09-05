SET VOLUME_NAME=docker_volume

docker volume %VOLUME_NAME%

SET CONTAINER_NAME=psql_db

SET PSQL_PWD=mysecretpassword

docker rm -f %CONTAINER_NAME%

REM Using the volume created by docker

docker run -d ^
	--name %CONTAINER_NAME% ^
	-e POSTGRES_PASSWORD=%PSQL_PWD% ^
	-e PGDATA=/var/lib/postgresql/data/pgdata ^
	-v %VOLUME_NAME%:/var/lib/postgresql/data ^
	postgres

docker exec -ti %CONTAINER_NAME% bash