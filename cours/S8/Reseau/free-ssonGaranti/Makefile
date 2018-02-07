CXXFLAGS= -std=c99 -Wall -Wextra -g `pkg-config libgvc --cflags` -g
LDFLAGS= `pkg-config libgvc --libs`
BINDIRCTRL   = bin/aqua/controller
SRCCTRL = controller
BINDIRV   = bin/aqua/view
SRCV = views

SOURCES  := $(wildcard $(SRCV)/*.java)

all:  $(BINDIRCTRL)/prog javav javactrl

$(BINDIRCTRL)/server.o: $(SRCCTRL)/server_tcp.c
	gcc ${CXXFLAGS} $^ -c -o $@ ${LDFLAGS}  -pthread

$(BINDIRCTRL)/prog: $(BINDIRCTRL)/server.o $(BINDIRCTRL)/graphe.o $(BINDIRCTRL)/poisson.o
	gcc ${CXXFLAGS} $^ -o $@ ${LDFLAGS}  -pthread

javactrl:
	javac -d ./bin/ -cp ./bin/ $(SRCCTRL)/*.java

$(BINDIRCTRL)/graphe.o: $(SRCCTRL)/graphe.c
	gcc ${CXXFLAGS} $^ -c -o $@ ${LDFLAGS}

$(BINDIRCTRL)/poisson.o: $(SRCCTRL)/poisson.c
	gcc ${CXXFLAGS} $^ -c -o $@ ${LDFLAGS}

$(BINDIRCTRL)/tool.o: $(SRCCTRL)/tool.c
	gcc ${CXXFLAGS} $^ -c -o $@ ${LDFLAGS}

javav:
	javac -Xlint -d ./bin/ -cp ./bin/ $(SRCV)/*.java

clean:
	rm -f $(BINDIRCTRL)/*.o $(BINDIRCTRL)/prog $(BINDIRCTRL)/*.class $(BINDIRV)/*.class
