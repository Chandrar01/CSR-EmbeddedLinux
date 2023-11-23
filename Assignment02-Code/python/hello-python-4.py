#!/usr/bin/python

import os
import sys
import time

from daemonize import Daemonize

def daemonize():
	# Fork the process
	pid = os.fork()

	if pid > 0:
		sys.exit()	#exit from parent process
				#are we basically creating an orphon process?

	os.chdir("/")
	os.umask(0)
	os.setsid()		#detach from controlling terminal

	# Close standard file descriptors
	sys.stdout.close()
	sys.stderr.close()
	sys.stdin.close()

	# Redirect standard file descriptors to /dev/null
	sys.stdout = open("/dev/null", "a+")
	sys.stderr = open("/dev/null", "a+")
	sys.stdin = open("/dev/null", "r")

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
	daemonize()
	main()

