#bin/bash

projectname=$1

echo "project_name is $projectname"

#gcc -static $projectname

gcc $projectname

echo "-------make sucess----------"

./a.out

