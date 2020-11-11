gcc udpclient.c -o udpclient
gcc udpserver.c -o udpserver

gnome-terminal --tab -e "/bin/bash -c './udpclient; exec /bin/bash -i'"
gnome-terminal --tab -e "/bin/bash -c './udpserver 8888; exec /bin/bash -i'"
#gnome-terminal –tab -e ./udpserver

#gnome-terminal --tab -e "/bin/bash -c '/usr/bin/myprog; exec /bin/bash -i'"
