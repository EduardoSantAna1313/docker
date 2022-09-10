cls

docker run -dti --name test_host --network host myubuntu:v1

docker exec test_host bash -c "hostname"