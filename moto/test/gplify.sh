#!/bin/bash


add_gpl()
{
    MYFILE="$1"
    HAS_GPL=$(grep "GNU General Public License" "$MYFILE" | wc -l)

    if [ "$HAS_GPL" = "0" ]
	then
	echo "$MYFILE  needs GPL"
	if [ ! -f $(dirname $0)/gpl.txt ]
	    then
	    echo "GPL file missing.... leaving"
	    exit 1
	fi
	echo "Adding GPL"
	rm -f "$MYFILE".tmp
	mv "$MYFILE" "$MYFILE".tmp
	cp $(dirname $0)/gpl.txt "$MYFILE"
	cat "$MYFILE".tmp >> "$MYFILE"
    else
	echo "$MYFILE  needs NO GPL"
    fi

}



find . -name "*.[hcCH]" | while (true)
do
    read FILE
    if [ "$FILE" = "" ] ; then break ; fi
    add_gpl "$FILE"
done