g++ $1.cpp -o $1.sh #$1 = nom du main
./$1.sh $2          #$2 = nom du fichier input
rm $1.sh