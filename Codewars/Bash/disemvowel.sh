#!/bin/bash

disemvowel(){
	#prints arugment and remove every occurence of a,i,u,e,o,A,I,U,E,O
	result=$(echo $@ | sed 's/[aeiouAEIOU]//g')
	echo $result
}

disemvowel $@
