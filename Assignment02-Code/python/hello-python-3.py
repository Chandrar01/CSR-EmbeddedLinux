#!/usr/bin/python

import os
import sys
import time

from daemonize import Daemonize

def main():
	print("Hello Python")
	print("My PID: " + str(os.getpid()))
	
	count = 0
	while True:
		count += 1
		print("count: " + str(count))
		time.sleep(15
)
	sys.exit(0)

if __name__ == "__main__":
	main()
	daemon = Daemonize(app="hello-python-3", pid="/tmp/my_daemon.pid", action=main)
	daemon.start()
