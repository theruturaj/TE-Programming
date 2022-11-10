import socket

option = 0
while option != '3':
	option = raw_input("******DNS Lookup*****\n1. Hostname to IP Address\n2. IP Address to Hostname\n3.Exit\nEnter your choice:")
	if option == '1':
		host = str(raw_input("Enter your Hostname(ex. google.com): "))
		print "IP Address of "+host+" is "+socket.gethostbyname(host)+"\n"
	elif option == '2':
		ip = str(raw_input("Enter your IP Address(ex. 192.168.43.139): "))
		print "Hostname of "+ip+" is "+str(socket.gethostbyaddr(ip))+"\n"
	else:
		print "Invalid Input"
print "DNS Lookup Exited!"
