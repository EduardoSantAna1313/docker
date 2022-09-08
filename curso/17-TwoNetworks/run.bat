docker network rm net1
docker network rm net2

docker rm -f container1
docker rm -f container2

cls

docker network create -d bridge --subnet 172.30.0.0/16 --gateway 172.30.0.1 net1

docker network create -d bridge --subnet 172.31.0.0/16 --gateway 172.31.0.1 net2


docker run -dti --name container1 --network net1 myubuntu:v1
docker run -dti --name container2 --network net2 myubuntu:v1

rem "When there are containers on different networks, we can connect each other with 'docker network connect NETORK CONTAINER' command."

docker exec container1 bash -c "ping container2"

docker network connect net2 container1

docker exec container1 bash -c "ping container2"

docker network dsconnect net2 container1

docker exec container1 bash -c "ping container2"