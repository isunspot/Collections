TARGET= osgi.test.helloworld.jar
JAR   = /usr/local/jdk1.6.0_26/bin/jar
JAVAC = /usr/local/jdk1.6.0_26/bin/javac
JAVAH = /usr/local/jdk1.6.0_26/bin/javah

SOURCES_DIR = osgi/test/helloworld
SOURCES     = $(wildcard ${SOURCES_DIR}/*.java)

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(JAVAC) -classpath ./lib/com.chinamobile.smartgateway.jar:./lib/org.eclipse.osgi_3.10.2.v20150203-1939.jar:./lib/json.jar $(SOURCES)
	$(JAR) -cvfm $@ ../META-INF/MANIFEST.MF $(SOURCES_DIR)

clean:
	rm -rf $(SOURCES_DIR)/*.class $(TARGET)
