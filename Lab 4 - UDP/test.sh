gcc udpclient.c -o udpclient
gcc udpserver.c -o udpserver

#gnome-terminal --tab -e "/bin/bash -c './udpclient; exec /bin/bash -i'"
#gnome-terminal --tab -e "/bin/bash -c './udpserver 3490; exec /bin/bash -i'"
