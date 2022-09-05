SET VOLUME_FOLDER=%userprofile%\docker_volumes\

SET CONTAINER_NAME=psql_db

SET PSQL_PWD=mysecretpassword

docker rm -f %CONTAINER_NAME%

docker run -d ^
	--name %CONTAINER_NAME% ^
	-e POSTGRES_PASSWORD=%PSQL_PWD% ^
	-e PGDATA=/var/lib/postgresql/data/pgdata ^
	-v %VOLUME_FOLDER%:/var/lib/postgresql/data ^
	postgres

docker exec -ti %CONTAINER_NAME% bash