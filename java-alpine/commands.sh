printf "Building the java code...\n\n"

javac  --source-path=app/ -p hello.world -d app/target/ app/hello.world/Main.java

printf "\nBuilding the docker image...\n\n"

docker build -t jdk:alpine .

printf "\n\nRunning the docker image...\n\n"

docker run --name light-java jdk:alpine

printf "\n\nDeleting the container...\n\n"

docker rm light-java
