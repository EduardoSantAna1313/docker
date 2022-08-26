SET CONTAINER_NAME=aws_cli_test
SET CREDENTIALS_FILE=%userprofile%\.aws\credentials

REM load aws credentials properties

echo "Reading credentials from %CREDENTIALS_FILE%"

FOR /F "tokens=1,2 delims=.=" %%G IN (%CREDENTIALS_FILE%) DO (
    set %%G=%%H
)

cls

docker rm -f %CONTAINER_NAME%

docker rmi -f %CONTAINER_NAME%:v1

docker build -t %CONTAINER_NAME%:v1 ^
    --build-arg AWS_ACCESS_KEY_ID=%aws_access_key_id% ^
    --build-arg AWS_SECRET_ACCESS_KEY=%aws_secret_access_key% ^
    --build-arg S3_FILE=%S3_FILE% .

docker run --name %CONTAINER_NAME% %CONTAINER_NAME%:v1