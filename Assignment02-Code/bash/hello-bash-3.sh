#! /bin/bash

echo "Hello Bash!"
echo "My pid: $$"

COUNT=1
while true; do
	COUNT=$((COUNT+1))
	echo "COUNT: $COUNT"
	sleep 15
done

