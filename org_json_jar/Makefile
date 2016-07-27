TARGET= org.json.jar
JAR   = /usr/local/jdk1.6.0_26/bin/jar
JAVAC = /usr/local/jdk1.6.0_26/bin/javac
JAVAH = /usr/local/jdk1.6.0_26/bin/javah

SOURCES_DIR = org/json
SOURCES = $(wildcard ${SOURCES_DIR}/*.java)
SOURCES += $(wildcard ${SOURCES_DIR}/zip/*.java)

SOURCES_CLASS = $(wildcard ${SOURCES_DIR}/*.class)
SOURCES_CLASS = $(wildcard ${SOURCES_DIR}/zip/*.class)

all:
	$(JAVAC) $(SOURCES)

install:
	$(JAR) -cvfm $(TARGET) ./META-INF/MANIFEST.MF $(SOURCES_CLASS)

clean:
	rm -rf $(SOURCES_DIR)/*.class $(SOURCES_DIR)/zip/*.class $(TARGET)
