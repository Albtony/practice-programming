#!/bin/bash

checkIfDir(){
	if [ -d $1 ]
	then echo "$1 is directory"
	elif [ -f $1 ]
	then echo "$1 is file"
	else echo "$1 does not exist as a file or directory"
	fi
}

checkIfDir $1
