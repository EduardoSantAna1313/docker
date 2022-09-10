docker-compose up -d

docker exec nginx_compose /bin/sh -c "ping mysql_compose"