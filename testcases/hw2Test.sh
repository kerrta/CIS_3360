case $1 in
checksum.c)
	gcc checksum.c 
	EXE="./a.out"
	;;
checksum.cpp)
	gpp checksum.cpp
	EXE="./a.out"
	;;
checksum.java)
	javac checksum.java
	EXE="java checksum"
	;;
*)
	echo "Invalid source file name"
	exit 1
esac

echo "Case #1 - 8 bit checksum"
eval $EXE in10A.txt 8 >s10A-Output8.txt
diff s10A-Output8.txt s10A-Base8.txt


echo "Case #1 - 16 bit checksum"
eval $EXE in10A.txt 16 >s10A-Output16.txt
diff s10A-Output16.txt s10A-Base16.txt


echo "Case #1 - 32 bit checksum"
eval $EXE in10A.txt 16 >s10A-Output32.txt
diff s10A-Output32.txt s10A-Base32.txt


echo "Case #2 - 8 bit checksum"
eval $EXE in17A.txt 8 >s17A-Output8.txt
diff s17A-Output8.txt s17A-Base8.txt


echo "Case #2 - 16 bit checksum"
eval $EXE in17A.txt 16 >s17A-Output16.txt
diff s17A-Output16.txt s17A-Base16.txt


echo "Case #2 - 32 bit checksum"
eval $EXE in17A.txt 32 >s17A-Output32.txt
diff s17A-Output32.txt s17A-Base32.txt


echo "Case #3 - 8 bit checksum"
eval $EXE in18A.txt 8 >s18A-Output8.txt
diff s18A-Output8.txt s18A-Base8.txt


echo "Case #3 - 16 bit checksum"
eval $EXE in18A.txt 16 >s18A-Output16.txt
diff s18A-Output16.txt s18A-Base16.txt


echo "Case #3 - 32 bit checksum"
eval $EXE in18A.txt 32 >s18A-Output32.txt
diff s18A-Output32.txt s18A-Base32.txt


echo "Case #4 - 8 bit checksum"
eval $EXE inRF2.txt 8 >sRF2-Output8.txt
diff sRF2-Output8.txt sRF2-Base8.txt


echo "Case #4 - 16 bit checksum"
eval $EXE inRF2.txt 16 >sRF2-Output16.txt
diff sRF2-Output16.txt sRF2-Base16.txt


echo "Case #4 - 32 bit checksum"
eval $EXE inRF2.txt 32 >sRF2-Output32.txt
diff sRF2-Output32.txt sRF2-Base32.txt


echo "Case #5 - 8 bit checksum"
eval $EXE inWC2.txt 8 >sWC2-Output8.txt
diff sWC2-Output8.txt sWC2-Base8.txt


echo "Case #5 - 16 bit checksum"
eval $EXE inWC2.txt 16 >sWC2-Output16.txt
diff sWC2-Output16.txt sWC2-Base16.txt


echo "Case #5 - 32 bit checksum"
eval $EXE inWC2.txt 32 >sWC2-Output32.txt
diff sWC2-Output32.txt sWC2-Base32.txt

