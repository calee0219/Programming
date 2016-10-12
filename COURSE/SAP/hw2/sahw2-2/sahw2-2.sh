#!/bin/sh

init() {
	exec 1>&2
	url="google.com"
}
welcome() {
	dialog \
		--title 'dialog browser' \
		--clear \
		--yesno "$(cat welcome.dio)" 16 51
}
web() {
	dialog \
		--title "dialog browser for $url" \
		--clear \
		--msgbox "$(w3m -dump $url)" 32 102
}
input() {
	dialog \
		--title 'input' \
		--clear \
		--cancel-label "Exit" \
		--inputbox "input URL or Command" 16 51 2> cmd-url
}
source() {
	dialog \
		--title 'source of the Web' \
		--clear \
		--msgbox "$(w3m -dump_source $url)" 32 102
}
menu() {
	w3m -dump_source $url > lin
	cat lin | awk ' \
			{
				if
			} \
		'
	while true; do
		cnt=0
		dialog \
			--backtitle "Got Link" \
			--title "Link" \
			--clear \
			--cancel-label "Exit" \
			--menu "Select a link:" 0 0 8 \
			"1" "Display System Information" \
			"2" "Display Disk Space" \
			"3" "Display Home Space Utilization" \
			2> selection
		case $? in
			0)
				clear
				echo "Program terminated."
				exit
				;;
			1)
				clear
				echo "Program aborted." >&2
				exit 1
				;;
		esac
		case $selection in
			0 )
				clear
				echo "Program terminated."
				;;
			1 )
				result=$(echo "Hostname: $HOSTNAME"; uptime)
				display_result "System Information"
				;;
			2 )
				result=$(df -h)
				display_result "Disk Space"
				;;
			3 )
				if [[ $(id -u) -eq 0 ]]; then
					result=$(du -sh /home/* 2> /dev/null)
					display_result "Home Space Utilization (All Users)"
				else
					result=$(du -sh $HOME 2> /dev/null)
					display_result "Home Space Utilization ($USER)"
				fi
				;;
		esac
	done
}
link() {
	menu
}
download() {
	menu
}
bookmark() {
}
help() {
	dialog \
	   	--title 'help' \
		--clear \
		--msgbox "$(cat help.dio)" 32 102
}
goodbye() {
	dialog \
	   	--title 'Good Bye' \
		--clear \
		--msgbox "$(cat bye.dio)" 16 51
}
end() {
	rm cmd-url
	rm selection
	rm lin
}


init
welcome
if [ $? -eq 1 ] ; then
	dialog \
	   	--title 'Out of browser' \
		--clear \
		--msgbox "$(cat out.dio)" 16 51
else
	web
	while true; do
		input
		case $? in
			0) tmp=$(cat cmd-url | sed -e 's~http[s]*://~~' -e 's~ftp*://~~')
				cnt=$(ping -c 1 "${tmp%%/*}" | grep 'received' | awk -F',' '{ print $2 }' | awk '{ print $1 }')
				if [ $cnt -ne 0 ] ; then
					url=$(cat cmd-url)
					web
				else
					case "$(cat cmd-url)" in
						\/S|\/s) source;;
						\/L|\/l) link;;
						\/D|\/d) download;;
						\/B|\/b) bookmark;;
						\/H|\/h) help;;
						\/Q|\/q) break;;
						*);;
					esac
				fi;;
			1) break;;
			*) break;;
		esac
	done
fi
goodbye
end
