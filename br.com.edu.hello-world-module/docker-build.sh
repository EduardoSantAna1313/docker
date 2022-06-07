echo "Building maven app"

mvn clean install

echo "Docker building...."

docker build --no-cache -t hello-world-app .