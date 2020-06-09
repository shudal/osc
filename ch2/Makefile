obj-m += simple.o
obj-m += hello.o
obj-m += myjiffies.o
obj-m += mysec.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
