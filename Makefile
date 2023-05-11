GCC = $(shell which gcc)

.PHONY: all
all: submit

BUILDENVVAR=-I/usr/include -L/usr/lib -L/usr/lib/flux -L/usr/lib/flux/resource -lflux-core -lflux-idset -lflux-hostlist -lstdc++ -ljansson -lczmq -lzmq

.PHONY: submit
submit: 
	mkdir -p ./bin
	$(GCC) $(BUILDENVVAR) -o bin/submit src/submit.c -lflux-core

.PHONY: test
test:
	bats -t test/bats/cli.bats
