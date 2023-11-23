#!/usr/bin/python

import os
import sys

def main():
	print("Hello Python")
	print("My PID: " + str(os.getpid()))
	sys.exit(0)

if __name__ == "__main__":
	main()
