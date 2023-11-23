#! /bin/bash

COUNT=0
while true ; do
	COUNT=$((COUNT+1))
	echo "COUNT: $COUNT" > /tmp/hello-bash-service.txt
	sleep 10
done

exit 0

