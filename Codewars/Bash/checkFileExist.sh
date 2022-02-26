#!/bin/bash

checkFile(){
	#insert first argument as file
	FILE=$1

	#if file = null
	if [ -z "$FILE" ]
	then
	  echo "Nothing to find"
	#if file is found or if file is itself
	elif [ -f "$FILE" ] || [ "$FILE" == "$0" ]
	then
	  echo "Found $1"
	else
	  echo "Can't find $1"
	fi
}

checkFile $1
