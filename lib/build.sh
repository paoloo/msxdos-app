echo "[+] cleanup..."
rm -f rel/*.rel
echo "[+] building rels..."
for F in `ls src/*.s`
do
	fname=`echo $F | cut -d'/' -f2 | cut -d'.' -f1`
	echo "building $fname.rel..."
    sdasz80 -o rel/$fname.rel $F
done

for F in `ls src/*.c`
do
    fname=`echo $F | cut -d'/' -f2 | cut -d'.' -f1`
	echo "building $fname.rel..."
	sdcc -mz80 -c -o rel/$fname.rel $F
done
