#!/bin/bash

PS3="Select your language please: "

select lng in Bash Java C++ Quit
do
    case $lng in
        "Bash")
            echo "$lng - that's what we're talking about";;
        "Java")
           echo "$lng - is your VM ready?";;
        "C++")
           echo "$lng - let's prepare for a lot of compilation";;
        "Quit")
           break;;
        *)
    esac
done
