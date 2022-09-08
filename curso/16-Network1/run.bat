cls

docker network rm mynetwork

docker rm -f container1
docker rm -f container2

docker network create -d bridge --subnet 172.16.18.0/16 --gateway 172.16.18.1 mynetwork

rem docker network inspect mynetwork

docker build -t myubuntu:v1 .

docker run -dti --name container1 --network mynetwork myubuntu:v1
docker run -dti --name container2 --network mynetwork myubuntu:v1

docker exec container1 bash -c "ping container2"

docker exec container2 bash -c "ping container1"