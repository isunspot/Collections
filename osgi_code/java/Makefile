
PLUGIN_JAR = osgi.test.helloworld.jar

PLUGIN_DIR = osgi.test.helloworld/src
TFTP_DIR = /home/heyu/workdir/zz/apps/private/rain

all:
	make -C $(PLUGIN_DIR)
	cp -a $(PLUGIN_DIR)/$(PLUGIN_JAR) $(TFTP_DIR)
	cp -a /home/heyu/workdir/zz/apps/private/joyme_lib/libjoyme.so.1.4 $(TFTP_DIR)

clean:
	make -C $(PLUGIN_DIR) clean
	rm -rf  $(TFTP_DIR)/$(PLUGIN_JAR)
