#!/bin/sh

init() {
	exec 1>&2
	url="nasa.cs.nctu.edu.tw"
}
error() {
	dialog \
		--title 'ERROR' \
		--msgbox "$(cat error.dio)" 16 51
}
testURL() {
	isURL=false
	tmp=$(echo $urlTmp | sed -e 's~http[s]*://~~' -e 's~ftp://~~')
	cnt=$(ping -c 1 "${tmp%%/*}" | grep 'received' | awk -F',' '{ print $2 }' | awk '{ print $1 }')
	if [ $cnt -ne 0 ] ; then
		isURL=true
	fi
}
urlProcess() {
	url=$(echo $url | awk ' \
		{
			if($0 ~ /^(https?|ftp):\/\//) print $1;
			else print "https://"$1;
		}
	' | awk ' \
		{
			if($0 ~ /\/$/) print $1;
			else print $1"/";
		}
	')
}
welcome() {
	dialog \
		--title 'dialog browser' \
		--yesno "$(cat welcome.dio)" 16 51
}
web() {
	urlProcess
	dialog \
		--title "dialog browser for $url" \
		--msgbox "$(w3m -dump $url)" 32 102
}
input() {
	dialog \
		--title 'input' \
		--cancel-label "Exit" \
		--inputbox "input URL or Command" 16 51 2> cmd-url
}
source() {
	dialog \
		--title 'source of the Web' \
		--msgbox "$(w3m -dump_source $url)" 32 102
}
getLink() {
	w3m -dump_source $url > lin
	# make link into linkArr array
	cat lin | sed -e "s/</>/g" | awk ' \
		BEGIN { RS=">"; } \
		{
			if($1 == "a") { print $2; }
		}
	' | sed -e "s/\"//g" -e "s/href=//" -e "s/^\///" | awk -v pos="$url" ' \
		{
			if($0 ~ /^(https?|ftp):\/\//) print $1;
			else if(pos ~ /^(https?|ftp):\/\//) print pos$1;
			else print "https://"pos$1;
		}
	' | awk ' \
		{
			if($0 ~ /\/$/) print $1;
			else print $1"/";
		}
	' > linkTable
}
link() {
	getLink
	dialog \
		--backtitle "Got Link" \
		--title "Link under $url" \
		--scrollbar \
		--cancel-label "Back" \
		--menu "Select a link:" 0 0 8 \
		$(cat linkTable | awk '{ print NR,$1; }') \
		2> selection
	case $? in
		0) no=$(cat selection)
			url=$(awk -v no="$no" 'NR==no' linkTable)
			web;;
		1);;
		*) error;;
	esac
}
download() {
	getLink
	dialog \
		--backtitle "Download HTML" \
		--title "Download Source Code from $url" \
		--scrollbar \
		--cancel-label "Back" \
		--menu "Select a link:" 0 0 8 \
		$(cat linkTable | awk '{ print NR,$1; }') \
		2> selection
	case $? in
		0) no=$(cat selection)
			url=$(awk -v no="$no" 'NR==no' linkTable)
			tmp=$(echo $url | sed -e 's~http[s]*://~~' -e 's~ftp://~~' -e 's~/~.~g')
			wget -O ~/Downloads/${tmp%.} $url;;
		1) ;;
		*) error;;
	esac
}
bookmark() {
	dialog \
		--backtitle "Book Mark" \
		--title "Choose bookmark or add one" \
		--scrollbar \
		--cancel-label "Back" \
		--menu "Select a link:" 0 0 8 \
		"1" "Add a bookmark" \
		"2" "Delete a bookmark" \
		$(cat bookmark.tab | awk '{ print NR+2,$1; }') \
		2> selection
	case $? in
		0) no=$(cat selection)
			case $no in
				1) awk -v url=$url ' \
					BEGIN { there=0; }
					{ if($0 == url) there=1; }
					END { if(there == 0) print url; }
				' bookmark.tab >> bookmark.tab;;
				2) awk -v url="$url" ' \
					{ if($0 !~ url) print $1; }
				' bookmark.tab > mark
				cat mark > bookmark.tab;;
				*) url=$(awk -v no="$no" 'NR==(no-2)' bookmark.tab)
					web;;
			esac;;
		1) ;;
		*) error;;
	esac
}
help() {
	dialog \
	   	--title 'help' \
		--msgbox "$(cat help.dio)" 32 102
}
badCondition() {
	dialog \
		--title "Input \"$(cat cmd-url)\" error" \
		--msgbox "$(cat badCondition.dio)" 16 51
}
goodbye() {
	dialog \
	   	--title 'Good Bye' \
		--msgbox "$(cat bye.dio)" 16 51
}
end() {
	rm cmd-url
	rm selection
	rm lin
	rm linkTable
	rm mark
}


init
welcome
if [ $? -eq 1 ] ; then
	dialog \
	   	--title 'Out of browser' \
		--msgbox "$(cat out.dio)" 16 51
else
	web
	while true; do
		input
		case $? in
			0) urlTmp=$(cat cmd-url)
				testURL
				if [ $isURL == true ] ; then
					url=$(cat cmd-url)
					web
				else
					case "$(cat cmd-url)" in
						\/S|\/s|\/source)	source;;
						\/L|\/l|\/link)		link;;
						\/D|\/d|\/download)	download;;
						\/B|\/b|\/bookmark)	bookmark;;
						\/H|\/h|\/help)		help;;
						\/Q|\/q|\/quit)		break;;
						*)					badCondition;;
					esac
				fi;;
			1) break;;
			*) error;;
		esac
	done
fi
goodbye
end
